#ifndef RC_UNREAL_TYPE_COMPATIBLE_BYTES_HPP
#define RC_UNREAL_TYPE_COMPATIBLE_BYTES_HPP

namespace RC::Unreal
{
    template<int32 Size,uint32 Alignment>
    struct TAlignedBytes;

    template<int32 Size>
    struct TAlignedBytes<Size,1>
    {
        uint8 Pad[Size];
    };

#ifdef __cplusplus_cli
    #define IMPLEMENT_ALIGNED_STORAGE(Align) \
		template<int32 Size>        \
		struct TAlignedBytes<Size,Align> \
		{ \
			uint8 Pad[Size]; \
			static_assert(Size % Align == 0, "CLR interop types must not be aligned."); \
		};
#else
/** A macro that implements TAlignedBytes for a specific alignment. */
#define IMPLEMENT_ALIGNED_STORAGE(Align) \
	template<int32 Size>        \
	struct TAlignedBytes<Size,Align> \
	{ \
		struct MS_ALIGN(Align) TPadding \
		{ \
			uint8 Pad[Size]; \
		} GCC_ALIGN(Align); \
		TPadding Padding; \
	};
#endif

#if defined(__clang__)
    #define GCC_PACK(n) __attribute__((packed,aligned(n)))
	#define GCC_ALIGN(n) __attribute__((aligned(n)))
	#if defined(_MSC_VER)
		#define MS_ALIGN(n) __declspec(align(n)) // With -fms-extensions, Clang will accept either alignment attribute
	#endif
#else
#define MS_ALIGN(n) __declspec(align(n))
#endif

#ifndef GCC_ALIGN
#define GCC_ALIGN(n)
#endif
#ifndef MS_ALIGN
#define MS_ALIGN(n)
#endif

    IMPLEMENT_ALIGNED_STORAGE(16);
    IMPLEMENT_ALIGNED_STORAGE(8);
    IMPLEMENT_ALIGNED_STORAGE(4);
    IMPLEMENT_ALIGNED_STORAGE(2);

#undef IMPLEMENT_ALIGNED_STORAGE

    template<typename ElementType>
    struct TTypeCompatibleBytes :
            public TAlignedBytes<
                    sizeof(ElementType),
                    alignof(ElementType)
            >
    {
        ElementType* GetTypedPtr() { return (ElementType*)this; }
        const ElementType* GetTypedPtr() const { return (const ElementType*)this; }
    };
}

#endif //RC_UNREAL_TYPE_COMPATIBLE_BYTES_HPP
