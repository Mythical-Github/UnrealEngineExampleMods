#ifndef RC_UNREAL_CLASS_SEARCHER_HPP
#define RC_UNREAL_CLASS_SEARCHER_HPP

#include <functional>
#include <memory>
#include <vector>

//#include <Unreal/UClass.hpp>
#include <Constructs/Loop.hpp>

namespace RC::Unreal
{
    struct FUObjectItem;
    class UObject;
    class UStruct;
    class UClass;

    using ObjectSearcherForEachPredicate = std::function<LoopAction(UObject*)>;
    using ObjectSearcherInternalSignature = void(*)(UClass* Class, UStruct* SuperStruct, const ObjectSearcherForEachPredicate& Predicate, std::vector<const FUObjectItem*>*);
    void ObjectSearcherFastInternal(UClass* Class, UStruct* SuperStruct, const ObjectSearcherForEachPredicate& Predicate, std::vector<const FUObjectItem*>* Pool);
    void ObjectSearcherSlowInternal(UClass* Class, UStruct* SuperStruct, const ObjectSearcherForEachPredicate& Predicate, std::vector<const FUObjectItem*>* Pool);

    struct EmptyStaticClass
    {
        static UClass* StaticClass() { return nullptr; }
    };

    using AnyClass = EmptyStaticClass;
    using AnySuperStruct = EmptyStaticClass;

    struct ObjectSearcherPoolBase
    {
    public:
        virtual std::vector<const FUObjectItem*>* GetPool() = 0;
    };

    template<typename ClassType, typename SuperStructType>
    struct ObjectSearcherPool : ObjectSearcherPoolBase
    {
    public:
        static inline std::vector<const FUObjectItem*> Pool{};

        // Pointer to the default generic slow searcher.
        static inline std::unique_ptr<ObjectSearcherPoolBase> UnderlyingSearcher;

    public:
        std::vector<const FUObjectItem*>* GetPool() override { return &Pool; }
    };

    struct ObjectSearcher
    {
    protected:
        UClass* Class{};
        UStruct* SuperStruct{};
        ObjectSearcherPoolBase* PoolPtr;
        ObjectSearcherInternalSignature InternalSearcher;

    public:
        ObjectSearcher(UClass* C, UStruct* S, ObjectSearcherPoolBase* P, ObjectSearcherInternalSignature IS) : Class(C), SuperStruct(S), PoolPtr(P), InternalSearcher(IS) {}

    public:
        size_t PoolSize() { return PoolPtr && PoolPtr->GetPool() ? PoolPtr->GetPool()->size() : 0; };
        bool IsFast() { return PoolPtr && PoolPtr->GetPool(); }

        void ForEach(const ObjectSearcherForEachPredicate& Predicate)
        {
            InternalSearcher(Class, SuperStruct, Predicate, PoolPtr ? PoolPtr->GetPool() : nullptr);
        }
    };

    size_t HashSearcherKey(UClass* Class, UStruct* SuperStruct);

    template<typename ClassType, typename SuperStructType>
    size_t HashSearcherKey()
    {
        return HashSearcherKey(ClassType::StaticClass(), SuperStructType::StaticClass());
    }

    extern std::unordered_map<size_t, std::unique_ptr<ObjectSearcherPoolBase>> AllSearcherPools;

    ObjectSearcher FindObjectSearcher(UClass* Class, UStruct* SuperStruct);

    template<typename ClassType, typename SuperStructType = AnySuperStruct>
    ObjectSearcher FindObjectSearcher()
    {
        return FindObjectSearcher(ClassType::StaticClass(), SuperStructType::StaticClass());
    }
}

#endif //RC_UNREAL_CLASS_SEARCHER_HPP
