#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ghexacell.h"

#include <QMainWindow>

#include "model/Game.h"
#include "model/utils/observer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(abalone::Game *game, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    abalone::Game *_game;
    std::vector<GHexaCell *> _gHexaCells;
    QString _positions;

    void initUI();
    void buildBoard();
    void clearLayout(QLayout *layout);
    void fillLayoutWithBoard(QLayout *layout);
    int convertRow(char row) const;
    bool checkIfIsSamePos(std::vector<int> const& position) const;
    void updatePlayersMarble() const;
    void deselectCells();
    void moveCells(std::vector<int> positions);
    void showWinner();

private slots:
    void on_actionExit_triggered();
    void on_ghexacell_clicked(std::string value, bool selected);
    void on_moveButton_clicked();
    void on_clearSelect_clicked();
};

#endif // MAINWINDOW_H
