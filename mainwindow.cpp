#include "mainwindow.hpp"
#include "ui_mainwindow.h"

QLineEdit *fields[81];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    board{}
{
    ui->setupUi(this);

    fields[0]  = ui->cell00;
    fields[1]  = ui->cell01;
    fields[2]  = ui->cell02;
    fields[3]  = ui->cell03;
    fields[4]  = ui->cell04;
    fields[5]  = ui->cell05;
    fields[6]  = ui->cell06;
    fields[7]  = ui->cell07;
    fields[8]  = ui->cell08;
    fields[9]  = ui->cell09;

    fields[10] = ui->cell10;
    fields[11] = ui->cell11;
    fields[12] = ui->cell12;
    fields[13] = ui->cell13;
    fields[14] = ui->cell14;
    fields[15] = ui->cell15;
    fields[16] = ui->cell16;
    fields[17] = ui->cell17;
    fields[18] = ui->cell18;
    fields[19] = ui->cell19;

    fields[20] = ui->cell20;
    fields[21] = ui->cell21;
    fields[22] = ui->cell22;
    fields[23] = ui->cell23;
    fields[24] = ui->cell24;
    fields[25] = ui->cell25;
    fields[26] = ui->cell26;
    fields[27] = ui->cell27;
    fields[28] = ui->cell28;
    fields[29] = ui->cell29;

    fields[30] = ui->cell30;
    fields[31] = ui->cell31;
    fields[32] = ui->cell32;
    fields[33] = ui->cell33;
    fields[34] = ui->cell34;
    fields[35] = ui->cell35;
    fields[36] = ui->cell36;
    fields[37] = ui->cell37;
    fields[38] = ui->cell38;
    fields[39] = ui->cell39;

    fields[40] = ui->cell40;
    fields[41] = ui->cell41;
    fields[42] = ui->cell42;
    fields[43] = ui->cell43;
    fields[44] = ui->cell44;
    fields[45] = ui->cell45;
    fields[46] = ui->cell46;
    fields[47] = ui->cell47;
    fields[48] = ui->cell48;
    fields[49] = ui->cell49;

    fields[50] = ui->cell50;
    fields[51] = ui->cell51;
    fields[52] = ui->cell52;
    fields[53] = ui->cell53;
    fields[54] = ui->cell54;
    fields[55] = ui->cell55;
    fields[56] = ui->cell56;
    fields[57] = ui->cell57;
    fields[58] = ui->cell58;
    fields[59] = ui->cell59;

    fields[60] = ui->cell60;
    fields[61] = ui->cell61;
    fields[62] = ui->cell62;
    fields[63] = ui->cell63;
    fields[64] = ui->cell64;
    fields[65] = ui->cell65;
    fields[66] = ui->cell66;
    fields[67] = ui->cell67;
    fields[68] = ui->cell68;
    fields[69] = ui->cell69;

    fields[70] = ui->cell70;
    fields[71] = ui->cell71;
    fields[72] = ui->cell72;
    fields[73] = ui->cell73;
    fields[74] = ui->cell74;
    fields[75] = ui->cell75;
    fields[76] = ui->cell76;
    fields[77] = ui->cell77;
    fields[78] = ui->cell78;
    fields[79] = ui->cell79;

    fields[80] = ui->cell80;

    for (int i = 0; i < 81; ++i) {
        board.cells[i]->field = fields[i];
        connect(fields[i], &QLineEdit::textChanged, this, [this, i]() {
           on_cellChanged(board.cells[i]);
        });
    } // end for //
    board.clear();
    enableInput(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableInput(bool enable)
{
    for (int i = 0; i < 81; ++i)
        fields[i]->setEnabled(enable);
}

void MainWindow::on_cellChanged(Cell *cell)
{
    switch (state) {
    case enter:
        {
            assert(cell);
            uint8_t value{static_cast<uint8_t>(cell->field->text().toInt())};
            cell->set(value);
            std::set<uint8_t> cset{board.getCollissions()};
            ui->goButton->setEnabled(true);
            for (uint8_t i = 0; i < 81; ++i) {
                QLineEdit *field{fields[i]};
                assert(field);
                if (cset.find(i) != cset.end()) {
                    field->setStyleSheet("color: yellow; background-color: red");
                    ui->goButton->setEnabled(false);
                } else if (board.cells[i]->solved()) {
                    field->setStyleSheet("color: white; background-color: black");
                } else {
                    field->setStyleSheet("color: black; background-color: white");
                }
            } // end for //
        }
        break;
    case calc:
        break;
        case result:
        break;
    } // end switch //
}

void MainWindow::on_exitButton_pressed()
{
    close();
}

void MainWindow::on_goButton_pressed()
{
}

void MainWindow::on_clearButton_pressed()
{
    board.clear();
}
