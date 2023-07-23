#include "compiler.h"

class A { };

template <typename T> class PUBLIC_ABI TemplateClass {
public:
  void get();
};

extern template class PUBLIC_ABI TemplateClass<A>;

// gcc < 13 does not support mixing gnu visibility attributes with alignas.
// The order does not matter, it rejects the attribute both before and after
// alignas.
// clang <=12, the gnu style attribute must come before alignas(8).

class PUBLIC_ABI alignas(8) AlignAs { };

// msvc does not support this.
//namespace attribute_after PUBLIC_ABI { }

// clang < 15 does not allow gnu visibility attributes before the namespace name.
namespace PUBLIC_ABI attribute_before { }
