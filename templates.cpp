#include "compiler.h"
#include "templates.h"




template <typename T> void TemplateClass<T>::get() { }

/* clang 16.0.5 does not allow us to use the C++11 style attributes here. */
/* clang 16.0.5 accepts the __attribute__ syntax here. */
/* gcc 13.1.1 allows C++11 style attributes here. */

// Note that in order for clang to emit a symbol for TemplateClass<A>::get(), the
// explicit instantiation has to go after the get function definition.
// gcc seems to generate the symbol no matter where it is.
// See https://eel.is/c++draft/temp.explicit#11
// See https://cplusplus.github.io/CWG/issues/470.html
// See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=22263
template class TemplateClass<A>;
