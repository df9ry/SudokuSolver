#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "board.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_pressed();
    void on_goButton_pressed();
    void on_clearButton_pressed();

private:
    void on_cellChanged(Cell *cell);
    void enableInput(bool enable);

    Ui::MainWindow *ui;
    Board           board;
    enum { enter, calc, result } state {enter};
};

#endif // MAINWINDOW_HPP
