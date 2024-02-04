#ifndef RC_UNREAL_DERIVED420_HPP
#define RC_UNREAL_DERIVED420_HPP

#include <Unreal/VersionedContainer/Derived417.hpp>

namespace RC::Unreal
{
    class Derived420 : public Base
    {
    protected:
        // FUObjectItem -> START
        using UObjectBase = Unreal::UObject;

        struct FUObjectItem
        {
            UObjectBase* object;
            int32_t flags;
            int32_t cluster_root_index;
            int32_t serial_number;

            [[nodiscard]] auto is_unreachable() const -> bool
            {
                return !!(flags & static_cast<int32_t>(EInternalObjectFlags::Unreachable));
            }

            [[nodiscard]] auto is_pending_kill() const
            {
                return !!(flags & static_cast<int32_t>(EInternalObjectFlags::PendingKill));
            }

            auto set_root_set(SetOrUnsetFlag set_or_unset_flag)
            {
                if (set_or_unset_flag == SetOrUnsetFlag::Set)
                {
                    flags = flags | static_cast<int32_t>(EInternalObjectFlags::RootSet);
                }
                else
                {
                    flags = flags & ~static_cast<int32_t>(EInternalObjectFlags::RootSet);
                }
            }

            auto set_gc_keep(SetOrUnsetFlag set_or_unset_flag)
            {
                if (set_or_unset_flag == SetOrUnsetFlag::Set)
                {
                    flags = flags | static_cast<int32_t>(EInternalObjectFlags::GarbageCollectionKeepFlags);
                }
                else
                {
                    flags = flags & ~static_cast<int32_t>(EInternalObjectFlags::GarbageCollectionKeepFlags);
                }
            }
        };

        // Abstraction Layer -> START
        auto FUObjectItem_is_object_unreachable(const void* p_this) const -> bool override
        {
            if (!p_this) { return true; }
            auto* p_typed_this = static_cast<const FUObjectItem*>(p_this);

            if (!p_typed_this->object) { return true; }

            return p_typed_this->is_unreachable();
        }

        auto FUObjectItem_set_object_root_set(void* p_this, SetOrUnsetFlag set_or_unset_flag) -> void override
        {
            if (!p_this) { return; }
            FUObjectItem* typed_this = static_cast<FUObjectItem*>(p_this);

            typed_this->set_root_set(set_or_unset_flag);
        }

        auto FUObjectItem_set_object_gc_keep(void* p_this, SetOrUnsetFlag set_or_unset_flag) -> void override
        {
            if (!p_this) { return; }
            FUObjectItem* typed_this = static_cast<FUObjectItem*>(p_this);

            typed_this->set_gc_keep(set_or_unset_flag);
        }

        auto FUObjectItem_get_serial_number(int32_t index) -> int32_t override
        {
            FUObjectItem* object_item = static_cast<FUObjectItem*>(UObjectArray_index_to_object(index));
            return object_item->serial_number;
        }

        auto FUObjectItem_get_serial_number(void* p_this) -> int32_t override
        {
            FUObjectItem* p_typed_this = static_cast<FUObjectItem*>(p_this);
            return p_typed_this->serial_number;
        }

        auto FUObjectItem_is_valid(void* p_this, bool b_even_if_pending_kill) -> bool override
        {
            FUObjectItem* p_typed_this = static_cast<FUObjectItem*>(p_this);

            if (p_typed_this)
            {
                return b_even_if_pending_kill ? !p_typed_this->is_unreachable() : !(p_typed_this->is_unreachable() || p_typed_this->is_pending_kill());
            }
            return false;
        }

        auto FUObjectItem_get_uobject(const void* p_this) -> void* override
        {
            auto* p_typed_this = static_cast<const FUObjectItem*>(p_this);

            if (p_typed_this)
            {
                return p_typed_this->object;
            }
            else
            {
                return nullptr;
            }
        }

        bool FUObjectItem_HasAnyFlags(void* RawThis, EInternalObjectFlags InFlags) override
        {
            FUObjectItem* TypedThis = static_cast<FUObjectItem*>(RawThis);
            return !!(TypedThis->flags & int32(InFlags));
        }
        // Abstraction Layer -> END
        // FUObjectItem -> END

        // GUObjectArray -> START
    public:
        struct FChunkedFixedUObjectArray
        {
            enum
            {
                num_elements_per_chunk = 64 * 1024,
            };

            FUObjectItem** objects;
            FUObjectItem* pre_allocated_objects;
            int32_t max_elements;
            int32_t num_elements;
            int32_t max_chunks;
            int32_t num_chunks;

            [[nodiscard]] auto get_object_ptr(int32_t index) const -> FUObjectItem*
            {
                const int32_t chunk_index = index / num_elements_per_chunk;
                const int32_t within_chunk_index = index % num_elements_per_chunk;
                FUObjectItem* chunk = objects[chunk_index];
                return chunk + within_chunk_index;
            }

            [[nodiscard]] auto operator[](int32_t index) const -> FUObjectItem&
            {
                FUObjectItem* item_ptr = get_object_ptr(index);
                return *item_ptr;
            }
        };

        static constexpr size_t PLATFORM_CACHE_LINE_SIZE = Derived417::PLATFORM_CACHE_LINE_SIZE;
        struct FUObjectArray
        {
            using TUObjectArray = FChunkedFixedUObjectArray;

            int32_t obj_first_gc_index;                                                        // 0x0
            int32_t obj_last_non_gc_index;                                                     // 0x4
            int32_t max_objects_not_considered_by_gc;                                          // 0x8
            bool open_for_disregard_for_gc;                                                    // 0xC
            TUObjectArray obj_objects;                                                         // 0x10

            CRITICAL_SECTION ObjObjectsCritical;                                               // 0x18
            // Real type: TLockFreePointerListUnordered
            // In >=4.17, this is a pointer surrounded by padding.
            uint8 ObjAvailableList[PLATFORM_CACHE_LINE_SIZE + 0x8 + PLATFORM_CACHE_LINE_SIZE]; // 0x58
            TArray<FUObjectCreateListener*> UObjectCreateListeners;                            // 0xE0
            TArray<FUObjectDeleteListener*> UObjectDeleteListeners;                            // 0xF8
        };

        using GUObjectArray = FUObjectArray;

    protected:
        static inline GUObjectArray* m_guobjectarray_internal{};

    public:
        auto UObjectArray_set_internal_storage_ptr(void* ptr) -> void override
        {
            m_guobjectarray_internal = static_cast<GUObjectArray*>(ptr);
        }

        auto UObjectArray_get_internal_storage_ptr() -> void* override
        {
            return m_guobjectarray_internal;
        }

        auto UObjectArray_for_each_uobject(ForEachObjObjectsCallableType callable) -> void override
        {
            if (!m_guobjectarray_internal) { return; }

            // DEBUG INFO -> START
            /*
            printf_s("m_guobjectarray_internal: %p\n", m_guobjectarray_internal);

            // Chunks ptr
            printf_s("chunks ptr: %p\n", m_guobjectarray_internal->obj_objects.objects);

            printf_s("max chunks: %d\n", m_guobjectarray_internal->obj_objects.max_chunks);
            printf_s("num chunks: %d\n", m_guobjectarray_internal->obj_objects.num_chunks);
            printf_s("max elements: %d\n", m_guobjectarray_internal->obj_objects.max_elements);
            printf_s("num elements: %d\n", m_guobjectarray_internal->obj_objects.num_elements);
            //*/
            // DEBUG INFO -> END

            LoopAction loop_action{LoopAction::Continue};

            for (int32_t current_chunk_index{}; current_chunk_index < m_guobjectarray_internal->obj_objects.num_chunks; ++current_chunk_index)
            {
                for (int32_t current_item_index{}; current_item_index < FChunkedFixedUObjectArray::num_elements_per_chunk; ++current_item_index)
                {
                    if (m_guobjectarray_internal->obj_objects.objects[current_chunk_index][current_item_index].object)
                    {
                        auto object_item = m_guobjectarray_internal->obj_objects.objects[current_chunk_index][current_item_index];
                        if (object_item.is_unreachable()) { continue; }
                        loop_action = callable(object_item.object, current_chunk_index, current_item_index);
                    }

                    if (loop_action == LoopAction::Break) { break; }
                }

                if (loop_action == LoopAction::Break) { break; }
            }
        }

        auto UObjectArray_for_each_uobject_in_chunk(int32_t chunk_index, ForEachObjInChunkCallableType callable) -> void override
        {
            if (!m_guobjectarray_internal) { return; }
            if (chunk_index >= m_guobjectarray_internal->obj_objects.num_chunks) { return; }

            LoopAction loop_action{LoopAction::Continue};

            for (int32_t current_item_index{}; current_item_index < FChunkedFixedUObjectArray::num_elements_per_chunk; ++current_item_index)
            {
                if (m_guobjectarray_internal->obj_objects.objects[chunk_index][current_item_index].object)
                {
                    auto object_item = m_guobjectarray_internal->obj_objects.objects[chunk_index][current_item_index];
                    if (object_item.is_unreachable()) { continue; }
                    loop_action = callable(object_item.object, current_item_index);
                }

                if (loop_action == LoopAction::Break) { break; }
            }
        }

        auto UObjectArray_for_each_uobject_in_range(int32_t start, int32_t end, ForEachObjObjectsCallableType callable) -> void override
        {
            if (!m_guobjectarray_internal) { return; }

            LoopAction loop_action{LoopAction::Continue};

            const int32_t start_chunk = start / FChunkedFixedUObjectArray::num_elements_per_chunk;
            const int32_t start_item_index = start % FChunkedFixedUObjectArray::num_elements_per_chunk;

            int32_t current_total_item = start;
            for (int32_t current_chunk_index{start_chunk}; current_chunk_index < m_guobjectarray_internal->obj_objects.num_chunks; ++current_chunk_index)
            {
                bool should_break{};
                for (int32_t current_item_index{start_item_index}; current_item_index < FChunkedFixedUObjectArray::num_elements_per_chunk; ++current_item_index)
                {
                    if (m_guobjectarray_internal->obj_objects.objects[current_chunk_index][current_item_index].object)
                    {
                        auto object_item = m_guobjectarray_internal->obj_objects.objects[current_chunk_index][current_item_index];
                        if (object_item.is_unreachable()) { continue; }
                        loop_action = callable(object_item.object, current_chunk_index, current_item_index);
                    }

                    if (loop_action == LoopAction::Break || current_total_item >= end)
                    {
                        should_break = true;
                        break;
                    }
                    ++current_total_item;
                }

                if (loop_action == LoopAction::Break || should_break) { break; }
            }
        }

        auto UObjectArray_index_to_object(int32_t index) -> void* override
        {
            if (index >= 0 && index < m_guobjectarray_internal->obj_objects.num_elements)
            {
                return &m_guobjectarray_internal->obj_objects[index];
            }
            return nullptr;
        }

        auto UObjectArray_get_obj_last_non_gc_index() -> int32_t override
        {
            return m_guobjectarray_internal->obj_last_non_gc_index;
        }

        auto UObjectArray_get_uobject_from_index(int32_t index) -> UObject* override
        {
            FUObjectItem* object_item = static_cast<FUObjectItem*>(UObjectArray_index_to_object(index));
            if (object_item)
            {
                return object_item->object;
            }
            else
            {
                return nullptr;
            }
        }

        auto UObjectArray_get_max_elements() -> int32_t override
        {
            return m_guobjectarray_internal->obj_objects.max_elements;
        }

        auto UObjectArray_get_num_elements() -> int32_t override
        {
            return m_guobjectarray_internal->obj_objects.num_elements;
        }

        auto UObjectArray_get_num_chunks() -> int32_t override
        {
            return m_guobjectarray_internal->obj_objects.num_chunks;
        }

        void UObjectArray_AddUObjectCreateListener(FUObjectCreateListener* Listener) override
        {
            if (m_guobjectarray_internal->UObjectCreateListeners.Contains(Listener))
            {
                throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
            }
            m_guobjectarray_internal->UObjectCreateListeners.Add(Listener);
        }

        void UObjectArray_RemoveUObjectCreateListener(FUObjectCreateListener* Listener) override
        {
            m_guobjectarray_internal->UObjectCreateListeners.RemoveSingleSwap(Listener);
        }

        void UObjectArray_AddUObjectDeleteListener(FUObjectDeleteListener* Listener) override
        {
            if (m_guobjectarray_internal->UObjectDeleteListeners.Contains(Listener))
            {
                throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
            }
            m_guobjectarray_internal->UObjectDeleteListeners.Add(Listener);
        }

        void UObjectArray_RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener) override
        {
            m_guobjectarray_internal->UObjectDeleteListeners.RemoveSingleSwap(Listener);
        }
        // GUObjectArray -> END

    public:
        auto Field_get_type_fname(FField* p_this) -> FName override;
        auto Field_get_ffield_owner([[maybe_unused]]FField* p_this) -> void* override;
        auto FFieldClass_get_fname(FFieldClass* p_this) -> FName override;
    };
}


#endif //RC_UNREAL_DERIVED420_HPP
