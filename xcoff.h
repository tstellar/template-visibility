#include "compiler.h"

class X32 {
};

class X64 {
};

template <typename AddressType> class PUBLIC_ABI XCOFFRelocation {
public:
  bool isRelocationSigned() const;
  bool isFixupIndicated() const;
  
  // Returns the number of bits being relocated.
  unsigned getRelocatedLength() const;
};
  
extern template class PUBLIC_ABI XCOFFRelocation<X32>;
extern template class PUBLIC_ABI XCOFFRelocation<X64>;

using XCOFFRelocation32 = XCOFFRelocation<X32>;
using XCOFFRelocation64 = XCOFFRelocation<X64>;

