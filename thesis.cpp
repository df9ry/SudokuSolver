#include "thesis.hpp"

uint8_t Thesis::nextValue()
{
    for (; r < 10; ++r) {
        uint8_t m{static_cast<uint8_t>(1 << r)};
        if (mask & m) {
            mask &= ~m;
            return r;
        }
    } // end for //
    return 0;
}
