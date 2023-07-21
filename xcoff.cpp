#include "xcoff.h"

template <typename AddressType>
bool XCOFFRelocation<AddressType>::isRelocationSigned() const {
  return true;
} 

template class XCOFFRelocation<X32>;
template class XCOFFRelocation<X64>;
