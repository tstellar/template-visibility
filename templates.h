#include "compiler.h"

// msvc requies friend function declarations to have attributes if the regular
// declaration also does.
//
// gcc only accepts c++11 style attributes after void, clang/msvc accept
// it before and after.
class A {
  friend void PUBLIC_ABI friendFunc(void);
};

PUBLIC_ABI void friendFunc(void);

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
// msvc does not support this.
//namespace PUBLIC_ABI attribute_before { }

class VTableParent {
  virtual void anchor(void) = 0;
};

// clang and gcc, but not msvc need to have a visibility attribute on the class
// in order to export the vtable.

class PUBLIC_ABI VTable : VTableParent {
  PUBLIC_ABI void anchor(void);
};

// msvc unique_ptr issue
#include <memory>
#include <vector>

class PUBLIC_ABI UniquePtrTest {
};

class PUBLIC_ABI UniquePtrTestMember {
  // Explicitly delete these to avoid error C2280: attempting to reference a deleted function.
  UniquePtrTestMember(const UniquePtrTestMember &) = delete;
  UniquePtrTestMember &operator=(const UniquePtrTestMember &) = delete;
private:
    std::vector<std::unique_ptr<UniquePtrTest>> x;
};

