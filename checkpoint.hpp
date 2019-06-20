#ifndef CHECKPOINT_HPP
#define CHECKPOINT_HPP

#include <stdint.h>

class Board;

class CheckPoint
{
public:
    CheckPoint(const Board *board);
    void restore(Board* board) const;

private:
    uint8_t  value[81];
    uint16_t cell_mask[81];
    uint16_t group_mask[9];
    uint16_t row_mask[9];
    uint16_t col_mask[9];
};

#endif // CHECKPOINT_HPP
