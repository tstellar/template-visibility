#include "compiler.h"

class A { };

template <typename T> class PUBLIC_ABI TemplateClass {
public:
  void get();
};

// gcc < 13 does not support mixing gnu visibility attributes with alignas.
// The order does not matter, it rejects the attribute both before and after
// alignas.
// clang <=12 does not like this when using the gnu attributes.

class alignas(8) PUBLIC_ABI AlignAs { };
