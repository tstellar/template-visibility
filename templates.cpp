#include "compiler.h"
#include "templates.h"


/* clang 16.0.5 does not allow us to use the C++11 style attributes here. */
/* clang 16.0.5 accepts the __attribute__ syntax here, but does not emit a symbol
 * for TemplateClass<A>::get() when annotated with
 * __attribute__((visibility("default"))*/
/* gcc 13.1.1 allows C++11 style attributes here. */
template class PUBLIC_ABI TemplateClass<A>;


template <typename T> void TemplateClass<T>::get() { }
