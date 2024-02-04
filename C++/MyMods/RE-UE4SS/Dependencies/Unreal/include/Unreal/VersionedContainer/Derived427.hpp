#ifndef RC_UNREAL_DERIVED427_HPP
#define RC_UNREAL_DERIVED427_HPP

#include <Unreal/VersionedContainer/Base.hpp>

namespace RC::Unreal
{
    class Derived427 : public Default
    {
        struct FUObjectArray
        {
            using TUObjectArray = Default::FChunkedFixedUObjectArray;

            int32_t obj_first_gc_index;                             // 0x0
            int32_t obj_last_non_gc_index;                          // 0x4
            int32_t max_objects_not_considered_by_gc;               // 0x8
            bool open_for_disregard_for_gc;                         // 0xC
            TUObjectArray obj_objects;                              // 0x10

            CRITICAL_SECTION ObjObjectsCritical;                    // 0x18
            TArray<int32> ObjAvailableList;                         // 0x58
            TArray<FUObjectCreateListener*> UObjectCreateListeners; // 0x68
            TArray<FUObjectDeleteListener*> UObjectDeleteListeners; // 0x78

            void AddUObjectDeleteListener(FUObjectDeleteListener* Listener)
            {
                if (UObjectDeleteListeners.Contains(Listener))
                {
                    throw std::runtime_error{"Cannot add a listener because it already exists in TArray"};
                }
                UObjectDeleteListeners.Add(Listener);
            }

            void RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener)
            {
                UObjectDeleteListeners.RemoveSingleSwap(Listener);
            }
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
                    auto& object_item = m_guobjectarray_internal->obj_objects.objects[chunk_index][current_item_index];
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

        void UObjectArray_AddUObjectCreateListener(FUObjectCreateListener* Listener) override;
        void UObjectArray_RemoveUObjectCreateListener(FUObjectCreateListener* Listener) override;
        void UObjectArray_AddUObjectDeleteListener(FUObjectDeleteListener* Listener) override;
        void UObjectArray_RemoveUObjectDeleteListener(FUObjectDeleteListener* Listener) override;
        // GUObjectArray -> END

        auto Field_get_type_fname(FField* p_this) -> FName override;
        auto Field_get_ffield_owner(FField* p_this) -> void* override;
        auto FFieldClass_get_fname(FFieldClass* p_this) -> FName override;
    };
}


#endif //RC_UNREAL_DERIVED427_HPP
