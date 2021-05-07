#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ghexacell.h"

#include <QMainWindow>

#include "model/Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow represents the class
 * which is the window that contains all the
 * related components and actions.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     * @param game the given model.
     * @param parent the given parent.
     */
    MainWindow(abalone::Game *game, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    abalone::Game *_game;
    std::vector<GHexaCell *> _gHexaCells;
    QString _positions;

    /**
     * \brief initUI connect all gHexacells slots, fill labels of players name.
     */
    void initUI();

    /**
     * @brief buildBoard create the game board.
     */
    void buildBoard();

    /**
     * @brief clearLayout remove all items of the given layout.
     * @param layout the given layout to clear.
     *
     */
    void clearLayout(QLayout *layout);

    /**
     * @brief fillLayoutWithBoard fill in the given layout of the game board.
     * @param layout the given layout to fill.
     */
    void fillLayoutWithBoard(QLayout *layout);

    /**
     * @brief convertRow convert the given row.
     * @param row the given row to convert.
     * @return the converted row.
     */
    int convertRow(char row) const;

    /**
     * @brief checkIfIsSamePos check if the given position are the same.
     *
     * @param position the given positions.
     * @return true if there are positions that are the same otherwise false.
     */
    bool checkIfIsSamePos(std::vector<int> const& position) const;

    /**
     * @brief updatePlayersMarble update the number of marbles of the players.
     */
    void updatePlayersMarble() const;

    /**
     * @brief deselectCells deselect all the cells of the game board.
     */
    void deselectCells();

//    /**
//     * @brief moveCells move the marbles usign the given positions.
//     * @param positions the given positions.
//     */
//    void moveCells(std::vector<int> positions);

    /**
     * @brief showWinner set the label with the name of the player who win.
     */
    void showWinner();

signals:
    void sendPositions(std::vector<int> positions);

private slots:

    /**
     * @brief on_actionExit_triggered exit the game.
     *
     */
    void on_actionExit_triggered();

    /**
     * @brief on_ghexacell_clicked if the cell is already selected,
     *  unselected it, otherwise select it.
     *
     * @param value abapro position of the cell.
     * @param selected if the cell is selected.
     */
    void on_ghexacell_clicked(std::string value, bool selected);

    /**
     * @brief on_moveButton_clicked move the selected cells.
     */
    void on_moveButton_clicked();

    /**
     * @brief on_clearSelect_clicked remove select of all the selected cells.
     */
    void on_clearSelect_clicked();

    /**
     * @brief moveCells move the marbles usign the given positions.
     * @param positions the given positions.
     */
    void moveCells(std::vector<int> pos);
};

#endif // MAINWINDOW_H
