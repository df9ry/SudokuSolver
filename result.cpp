#include "result.hpp"
#include "board.hpp"

#include <assert.h>

Result::Result(const Board *board)
{
    assert(board);
    for (int i = 0; i < 81; ++i)
        value[i] = board->cells[i]->get();
}

void Result::copy(Board *board)
{
    assert(board);
    board->clear();
    for (int i = 0; i < 81; ++i)
        board->cells[i]->set(value[i]);
}
