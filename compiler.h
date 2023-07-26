#if defined(GNU_VISIBILITY)
#define PUBLIC_ABI __attribute__((visibility("default")))
#elif defined(CXX11_VISIBILITY)
#define PUBLIC_ABI [[gnu::visibility("default")]]
#elif defined(NO_VISIBILITY)
#define PUBLIC_ABI
#elif defined(__ELF__)
#  define PUBLIC_ABI __attribute__((visibility("default")))
#else
#  if defined(template_visibility_EXPORTS)
#    define PUBLIC_ABI __declspec(dllexport)
#  else
#    define PUBLIC_ABI __declspec(dllimport)
#  endif
#endif
