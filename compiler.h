#if defined(GNU_VISIBILITY)
#define PUBLIC_ABI __attribute__((visibility("default")))
#elif defined(CXX11_VISIBILITY)
#define PUBLIC_ABI [[gnu::visibility("default")]]
#elif defined(NO_VISIBILITY)
#define PUBLIC_ABI
#else
#  ifdef __clang__
#    define PUBLIC_ABI __attribute__((visibility("default")))
#  else
#    define PUBLIC_ABI [[gnu::visibility("default")]]
#  endif
#endif
