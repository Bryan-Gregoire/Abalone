#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(abalone::Game *game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      _game {game},
      _gHexaCells {}
{
    ui->setupUi(this);
    _game->setCurrentPlayerName("Bryan");
    _game->switchCurrentPlayer();
    _game->setCurrentPlayerName("Billal");
    _game->switchCurrentPlayer();

    const double r = 46;
    std::array<char, 9> letters= {'A','B','C','D','E','F','G','H','I'};
    abalone::Color color = abalone::Color::NONE;
    for (unsigned int i = 0;i < abalone::Board::SIZE;i++ ) {
        for (unsigned int j = 0; j < abalone::Board::SIZE ;j++ ) {
            if(_game->getBoard().isInsideBoard(i,j)) {
                if(_game->getBoard().containMarble(i,j)) {
                    color = _game->getBoard().getColorMarble(i,j);
                } else {
                    color = abalone::Color::NONE;
                }
                _gHexaCells.push_back(new GHexaCell(i * 2 * r * 3 / 4, (round(sqrt(3)) * r) * j + i * r, r,color,
                                                    letters.at(8 - i) + std::to_string(j+1),nullptr));
            }
        }
    }
    auto scene = new QGraphicsScene();

    std::for_each(begin(_gHexaCells), end(_gHexaCells),
                  [this, scene](GHexaCell * e) {
        e->setPos(e->y(), e->x());
        scene->addItem(e);
        QObject::connect(e,
                         SIGNAL(sendValue(std::string, bool)),
                         this,
                         SLOT(on_ghexacell_clicked(std::string, bool)));
    });
    auto view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->update();

    ui->verticalLayout_4->addWidget(view);

    ui->player1->setText(_game->getIdxPlayerName(0).c_str());
    ui->player2->setText(_game->getIdxPlayerName(1).c_str());
    ui->turnPName->setText(ui->player1->text());

    /* connect in for_each
        QObject::connect(_gHexaCells[0], SIGNAL(sendValue(std::string)),
                         this, SLOT(on_ghexacell_clicked(std::string)));
        */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered() {
    QApplication::quit();
}

void MainWindow::on_ghexacell_clicked(std::string value, bool selected)
{
    QString pos = ui->positions->text();
    selected ? pos.append(value.c_str()) : pos.remove(value.c_str());
    ui->positions->setText(pos);

    std::string s = "receveive value from ghexacell ";
    s.append(value);
    qDebug() << s.c_str();
}


