#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <set>

class QLineEdit;
class Cell;

class Serie
{
friend class Cell;
friend class Board;

protected:
    /**
     * @brief Serie Base class for Group, Row and Col.
     * @param i Number of the Group, Row or Col.
     * @param _cells cells within this Serie.
     */
    Serie(int i, const std::vector<Cell*>& _cells) :
        no{i}, cells{_cells}
    {}

    /**
     * @brief getCollissions Add collitions to a set of
     *  collitions. This method didn't recognize mask.
     * @param cell_no Number of cell calling this method.
     * @param cell_value Value to check against.
     * @param cset Colliition set, where collitions shall
     *  be added to.
     */
    void getCollissions(int cell_no, uint8_t value,
                        std::set<uint8_t>& cset) const;

private:
    void clear();

    const int                no;
    const std::vector<Cell*> cells;
    uint16_t                 mask;
};

class Group : public Serie
{
friend class Board;

private:
    /**
     * @brief Constructor of a Cell group,
     *  containing 3 x 3 cells.
     * @param i Number of this group.
     * @param _cells Cells in this group.
     */
    Group(int i, const std::vector<Cell*>& _cells) :
        Serie(i, _cells)
    {}
};

class Row : public Serie
{
friend class Board;

private:
    /**
     * @brief Constructor of a Cell row,
     *  containing 9 cells.
     * @param i Number of this row.
     * @param _cells Cells in this row.
     */
    Row(int i, const std::vector<Cell*>& _cells) :
        Serie(i, _cells)
    {}
};

class Col : public Serie
{
friend class Board;
friend class Cell;

private:
    /**
     * @brief Constructor of a Cell column,
     *  containing 9 cells.
     * @param i Number of this column.
     * @param _cells Cells in this column.
     */
    Col(int i, const std::vector<Cell*>& _cells) :
        Serie(i, _cells)
    {}
};

class Cell
{
friend class Board;
friend class Serie;

public:
    void clear();
    bool solved() const { return (value); }
    void set(uint8_t value);

QLineEdit *field{nullptr};

private:
    /**
     * @brief Cell Constructor.
     * @param i Number of this cell.
     * @param _group Group this cell is within.
     * @param _row Row this cell is within.
     * @param _col Column this cell is within.
     */
    Cell(int i, Group& _group, Row& _row, Col& _col) :
        no{i},
        group{_group},
        row{_row},
        col{_col}
    {}

    /**
     * @brief getCollissions Get collitions with this cell.
     * @param cset Set of collitions.
     */
    void getCollissions(std::set<uint8_t>& cset) const;

    const int  no;
    uint16_t   mask;
    uint8_t    value;
    Group&     group;
    Row&       row;
    Col&       col;
};

class Board
{
public:
    /**
     * @brief Board Constructor
     */
    Board();

    Cell *cells[81] {
        new Cell( 0, groups[0], rows[0], cols[0]),
        new Cell( 1, groups[0], rows[0], cols[1]),
        new Cell( 2, groups[0], rows[0], cols[2]),
        new Cell( 3, groups[0], rows[1], cols[0]),
        new Cell( 4, groups[0], rows[1], cols[1]),
        new Cell( 5, groups[0], rows[1], cols[2]),
        new Cell( 6, groups[0], rows[2], cols[0]),
        new Cell( 7, groups[0], rows[2], cols[1]),
        new Cell( 8, groups[0], rows[2], cols[2]),

        new Cell( 9, groups[1], rows[0], cols[3]),
        new Cell(10, groups[1], rows[0], cols[4]),
        new Cell(11, groups[1], rows[0], cols[5]),
        new Cell(12, groups[1], rows[1], cols[3]),
        new Cell(13, groups[1], rows[1], cols[4]),
        new Cell(14, groups[1], rows[1], cols[5]),
        new Cell(15, groups[1], rows[2], cols[3]),
        new Cell(16, groups[1], rows[2], cols[4]),
        new Cell(17, groups[1], rows[2], cols[5]),

        new Cell(18, groups[2], rows[0], cols[6]),
        new Cell(19, groups[2], rows[0], cols[7]),
        new Cell(20, groups[2], rows[0], cols[8]),
        new Cell(21, groups[2], rows[1], cols[6]),
        new Cell(22, groups[2], rows[1], cols[7]),
        new Cell(23, groups[2], rows[1], cols[8]),
        new Cell(24, groups[2], rows[2], cols[6]),
        new Cell(25, groups[2], rows[2], cols[7]),
        new Cell(26, groups[2], rows[2], cols[8]),

        new Cell(27, groups[3], rows[3], cols[0]),
        new Cell(28, groups[3], rows[3], cols[1]),
        new Cell(29, groups[3], rows[3], cols[2]),
        new Cell(30, groups[3], rows[4], cols[0]),
        new Cell(31, groups[3], rows[4], cols[1]),
        new Cell(32, groups[3], rows[4], cols[2]),
        new Cell(33, groups[3], rows[5], cols[0]),
        new Cell(34, groups[3], rows[5], cols[1]),
        new Cell(35, groups[3], rows[5], cols[2]),

        new Cell(36, groups[4], rows[3], cols[3]),
        new Cell(37, groups[4], rows[3], cols[4]),
        new Cell(38, groups[4], rows[3], cols[5]),
        new Cell(39, groups[4], rows[4], cols[3]),
        new Cell(40, groups[4], rows[4], cols[4]),
        new Cell(41, groups[4], rows[4], cols[5]),
        new Cell(42, groups[4], rows[5], cols[3]),
        new Cell(43, groups[4], rows[5], cols[4]),
        new Cell(44, groups[4], rows[5], cols[5]),

        new Cell(45, groups[5], rows[3], cols[6]),
        new Cell(46, groups[5], rows[3], cols[7]),
        new Cell(47, groups[5], rows[3], cols[8]),
        new Cell(48, groups[5], rows[4], cols[6]),
        new Cell(49, groups[5], rows[4], cols[7]),
        new Cell(50, groups[5], rows[4], cols[8]),
        new Cell(51, groups[5], rows[5], cols[6]),
        new Cell(52, groups[5], rows[5], cols[7]),
        new Cell(53, groups[5], rows[5], cols[8]),

        new Cell(54, groups[6], rows[6], cols[1]),
        new Cell(55, groups[6], rows[6], cols[2]),
        new Cell(56, groups[6], rows[6], cols[3]),
        new Cell(57, groups[6], rows[7], cols[1]),
        new Cell(58, groups[6], rows[7], cols[2]),
        new Cell(59, groups[6], rows[7], cols[3]),
        new Cell(60, groups[6], rows[8], cols[1]),
        new Cell(61, groups[6], rows[8], cols[2]),
        new Cell(62, groups[6], rows[8], cols[3]),

        new Cell(63, groups[7], rows[6], cols[3]),
        new Cell(64, groups[7], rows[6], cols[4]),
        new Cell(65, groups[7], rows[6], cols[5]),
        new Cell(66, groups[7], rows[7], cols[3]),
        new Cell(67, groups[7], rows[7], cols[4]),
        new Cell(68, groups[7], rows[7], cols[5]),
        new Cell(69, groups[7], rows[8], cols[3]),
        new Cell(70, groups[7], rows[8], cols[4]),
        new Cell(71, groups[7], rows[8], cols[5]),

        new Cell(72, groups[8], rows[6], cols[6]),
        new Cell(73, groups[8], rows[6], cols[7]),
        new Cell(74, groups[8], rows[6], cols[8]),
        new Cell(75, groups[8], rows[7], cols[6]),
        new Cell(76, groups[8], rows[7], cols[7]),
        new Cell(77, groups[8], rows[7], cols[8]),
        new Cell(78, groups[8], rows[8], cols[6]),
        new Cell(79, groups[8], rows[8], cols[7]),
        new Cell(80, groups[8], rows[8], cols[8])
    };

    Group groups[9] {
        Group(0, std::vector<Cell*> {
            cells[0],  cells[1],  cells[2],
            cells[3],  cells[4],  cells[5],
            cells[6],  cells[7],  cells[8]
        }),
        Group(1, std::vector<Cell*> {
            cells[9],  cells[10], cells[11],
            cells[12], cells[13], cells[14],
            cells[15], cells[16], cells[17]
        }),
        Group(2, std::vector<Cell*> {
            cells[18], cells[19], cells[20],
            cells[21], cells[22], cells[23],
            cells[24], cells[25], cells[26]
        }),
        Group(3, std::vector<Cell*> {
            cells[27], cells[28], cells[29],
            cells[30], cells[31], cells[32],
            cells[33], cells[34], cells[35]
        }),
        Group(4, std::vector<Cell*> {
            cells[36], cells[37], cells[38],
            cells[39], cells[40], cells[41],
            cells[42], cells[43], cells[44]
        }),
        Group(5, std::vector<Cell*> {
            cells[45], cells[46], cells[47],
            cells[48], cells[49], cells[50],
            cells[51], cells[52], cells[53]
        }),
        Group(6, std::vector<Cell*> {
            cells[54], cells[55], cells[56],
            cells[57], cells[58], cells[59],
            cells[60], cells[61], cells[62]
        }),
        Group(7, std::vector<Cell*> {
            cells[63], cells[64], cells[65],
            cells[66], cells[67], cells[68],
            cells[69], cells[70], cells[71]
        }),
        Group(8, std::vector<Cell*> {
            cells[72], cells[73], cells[74],
            cells[75], cells[76], cells[77],
            cells[78], cells[79], cells[80]
        })
    };

    Row rows[9] = {
        Row(0, std::vector<Cell*> {
            cells[0],  cells[1],  cells[2],
            cells[9],  cells[10], cells[11],
            cells[18], cells[19], cells[20]
        }),
        Row(1, std::vector<Cell*> {
            cells[3],  cells[4],  cells[5],
            cells[12], cells[13], cells[14],
            cells[21], cells[22], cells[23]
        }),
        Row(2, std::vector<Cell*> {
            cells[6],  cells[7],  cells[8],
            cells[15], cells[16], cells[17],
            cells[24], cells[25], cells[26]
        }),
        Row(3, std::vector<Cell*> {
            cells[27], cells[28], cells[29],
            cells[36], cells[37], cells[38],
            cells[45], cells[46], cells[47]
        }),
        Row(4, std::vector<Cell*> {
            cells[30], cells[31], cells[32],
            cells[39], cells[40], cells[41],
            cells[48], cells[49], cells[50]
        }),
        Row(5, std::vector<Cell*> {
            cells[33], cells[34], cells[35],
            cells[42], cells[43], cells[44],
            cells[51], cells[52], cells[53]
        }),
        Row(6, std::vector<Cell*> {
            cells[54], cells[55], cells[56],
            cells[63], cells[64], cells[65],
            cells[72], cells[73], cells[74]
        }),
        Row(7, std::vector<Cell*> {
            cells[57], cells[58], cells[59],
            cells[66], cells[67], cells[68],
            cells[75], cells[76], cells[77]
        }),
        Row(8, std::vector<Cell*> {
            cells[60], cells[61], cells[62],
            cells[69], cells[70], cells[71],
            cells[78], cells[79], cells[80]
        })
    };

    Col cols[9] {
        Col(0, std::vector<Cell*> {
            cells[0],  cells[3],  cells[6],
            cells[27], cells[30], cells[33],
            cells[54], cells[57], cells[60]
        }),
        Col(1, std::vector<Cell*> {
            cells[1],  cells[4],  cells[7],
            cells[28], cells[31], cells[34],
            cells[55], cells[58], cells[61]
        }),
        Col(2, std::vector<Cell*> {
            cells[2],  cells[5],  cells[8],
            cells[29], cells[32], cells[35],
            cells[56], cells[59], cells[62]
        }),
        Col(3, std::vector<Cell*> {
            cells[9],  cells[12], cells[15],
            cells[36], cells[39], cells[42],
            cells[63], cells[66], cells[69]
        }),
        Col(4, std::vector<Cell*> {
            cells[10], cells[13], cells[16],
            cells[37], cells[40], cells[43],
            cells[64], cells[67], cells[70]
        }),
        Col(5, std::vector<Cell*> {
            cells[11], cells[14], cells[17],
            cells[38], cells[41], cells[44],
            cells[65], cells[68], cells[71]
        }),
        Col(6, std::vector<Cell*> {
            cells[18], cells[21], cells[24],
            cells[45], cells[48], cells[51],
            cells[72], cells[75], cells[78]
        }),
        Col(7, std::vector<Cell*> {
            cells[19], cells[22], cells[25],
            cells[46], cells[49], cells[52],
            cells[73], cells[76], cells[79]
        }),
        Col(8, std::vector<Cell*> {
            cells[20], cells[23], cells[26],
            cells[47], cells[50], cells[53],
            cells[74], cells[77], cells[80]
        })
    };

    void clear();
    std::set<uint8_t> getCollissions() const;
};

#endif // BOARD_HPP
