#ifndef THESIS_HPP
#define THESIS_HPP

#include <stdint.h>

class Thesis
{
public:
    Thesis(int _no, uint16_t _mask) :
        no{_no}, mask{_mask}, r{1}
    {}

    int getNo() const { return no; }
    uint8_t nextValue();

private:
    const int no;
    uint16_t mask;
    uint8_t  r;
};

#endif // THESIS_HPP
