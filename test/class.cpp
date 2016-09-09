#include "fuzz.hpp"

int main() {
  ramfuzz::runtime::gen g;
  B b;
  ramfuzz::B::control rb(g, b);
  for (auto m : rb.mroulette)
    (rb.*m)();
  if (b.sum != 11)
    return 1;
  else
    return 0;
}

unsigned ::ramfuzz::runtime::spinlimit = 3;