#include <QLineEdit>

#include <assert.h>

#include "board.hpp"

void Serie::getCollissions(int cell_no, uint8_t value,
                            std::set<uint8_t>& cset) const
{
    if (value) {
        for (int i = 0; i < 9; ++i) {
            Cell *cell{cells[i]};
            assert(cell);
            if (cell->no == cell_no) // Don't check the caller cell itself
                continue;
            if (cell->value == value) // This is a collition
                cset.insert(cell->no);
        } // end for //
    }
}


void Serie::clear()
{
    mask = 0x00;
}

void Cell::getCollissions(std::set<uint8_t>& cset) const
{
    group.getCollissions(no, value, cset);
    row.getCollissions(no, value, cset);
    col.getCollissions(no, value, cset);
}

void Cell::clear()
{
    assert(field);
    field->setText("");
    value = 0;
    mask = 0x00;
}

void Cell::set(uint8_t v)
{
    value = v;
    uint8_t m{static_cast<uint8_t>(1 << v)};
    group.mask |= m;
    row.mask |= m;
    col.mask |= m;
}

Board::Board()
{

}

void Board::clear()
{
    for (int i = 0; i < 81; ++i)
        cells[i]->clear();
    for (int i = 0; i < 9; ++i)
        rows[i].clear();
    for (int i = 0; i < 9; ++i)
        cols[i].clear();
    for (int i = 0; i < 9; ++i)
        groups[i].clear();
}

std::set<uint8_t> Board::getCollissions() const
{
    std::set<uint8_t> cset;
    for (int i = 0; i < 81; ++i)
        cells[i]->getCollissions(cset);
    return cset;
}
