#include "checkpoint.hpp"
#include "board.hpp"

#include <assert.h>

CheckPoint::CheckPoint(const Board *board)
{
    assert(board);
    for (int i = 0; i < 81; ++i) {
        value[i]     = board->cells[i]->value;
        cell_mask[i] = board->cells[i]->mask;
    } // end for //
    for (int i = 0; i < 9; ++i) {
        group_mask[i] = board->groups[i].mask;
        row_mask[i]   = board->rows[i].mask;
        col_mask[i]   = board->cols[i].mask;
    } // end for //
}

void CheckPoint::restore(Board* board) const
{
    assert(board);
    for (int i = 0; i < 81; ++i) {
        board->cells[i]->value = value[i];
        board->cells[i]->mask  = cell_mask[i];
    } // end for //
    for (int i = 0; i < 9; ++i) {
        board->groups[i].mask = group_mask[i];
        board->rows[i].mask   = row_mask[i];
        board->cols[i].mask   = col_mask[i];
    } // end for //
}
