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

private slots:
    void on_actionExit_triggered();
    void on_ghexacell_clicked(std::string value);
};

#endif // MAINWINDOW_H
