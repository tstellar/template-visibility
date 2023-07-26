#include "templates.h"
#include "xcoff.h"

int main(int argc, char **argv) {
  TemplateClass<A> a;
  a.get();

  VTable v;

  XCOFFRelocation32 x;
  return x.isRelocationSigned();
}
