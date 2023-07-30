#include "compiler.h"

// msvc requies friend function declarations to have attributes if the regular
// declaration also does.
//
// gcc only accepts c++11 style attributes after void for friend attributes, clang/msvc accept
// it before and after.
class A {
  friend PUBLIC_ABI void friendFunc(void);
};

PUBLIC_ABI void friendFunc(void);

// msvc doesn't support the visibility attributes after the return type when the return
// type is a pointer.
//class B {
//  friend B* PUBLIC_ABI friendFunc(void);
//};

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
public:
  virtual void anchor(void) = 0;
};

// clang and gcc, but not msvc need to have a visibility attribute on the class
// in order to export the vtable.
// msvc does not support attributes on the class and a member function:
// https://learn.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2487?view=msvc-170
class PUBLIC_ABI VTable : VTableParent {
public:
  void anchor(void);
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

class PUBLIC_ABI DefInHeader {
public:
  void foo(void);
};

void DefInHeader::foo(void) { }
