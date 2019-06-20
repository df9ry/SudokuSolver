#ifndef RESULT_HPP
#define RESULT_HPP

#include <stdint.h>

class Board;

class Result
{
public:
    Result(const Board *board);

    void copy(Board *board);

private:
    uint8_t value[81];
};

#endif // RESULT_HPP
