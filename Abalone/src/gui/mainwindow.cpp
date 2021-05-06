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
      _gHexaCells {},
      _positions {}
{
    _game->setCurrentPlayerName("Bryan");
    _game->switchCurrentPlayer();
    _game->setCurrentPlayerName("Billal");
    _game->switchCurrentPlayer();
    buildBoard();
    initUI();

    /* connect in for_each
        QObject::connect(_gHexaCells[0], SIGNAL(sendValue(std::string)),
                         this, SLOT(on_ghexacell_clicked(std::string)));
        */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI() {
    ui->setupUi(this);

    QObject::connect(this,
                     SIGNAL(sendPositions(std::vector<int>)),
                     this,
                     SLOT(moveCells(std::vector<int>)));

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


}

void MainWindow::buildBoard() {
    _gHexaCells.clear();
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
                _gHexaCells.push_back(new GHexaCell(i * 2 * r * 3 / 4, (round(sqrt(3)) * r) * j + i * r,
                                                    r, color,
                                                    letters.at(8 - i) + std::to_string(j+1),nullptr));
            }
        }
    }
}

void MainWindow::fillLayoutWithBoard(QLayout *layout) {
    clearLayout(layout);
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

    layout->addWidget(view);
}

void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void MainWindow::on_actionExit_triggered() {
    QApplication::quit();
}

void MainWindow::on_ghexacell_clicked(std::string value, bool selected)
{
    QString pos = ui->abaPro->text();
    selected ? pos.append(value.c_str()) : pos.remove(value.c_str());
    ui->abaPro->setText(pos);

    selected ? _positions.append(value.c_str()) : _positions.remove(value.c_str());

    std::string s = "receveive value from ghexacell ";
    s.append(value);
    qDebug()<< s.c_str();

}

void MainWindow::on_moveButton_clicked()
{

    std::vector<int> pos;
    std::string allPos = _positions.toStdString();

    for (int i = 0; i < _positions.size() ;i+=2 ) {
        int row = convertRow(allPos.at(i));
        int col = _positions.at(i+1).digitValue() - 1;
        pos.push_back(row);
        pos.push_back(col);
    }

    _positions.clear();
    ui->abaPro->clear();
    //deselectCells();

    qDebug() << "Button click";

    emit sendPositions(pos);

}

void MainWindow::moveCells(std::vector<int> pos) {
    qDebug()<<"move cells";
    try {
        if(_game->checkContentPositions(pos) && !checkIfIsSamePos(pos)
                && _game->checkGoodMovePos(pos) ) {

            _game->move(pos);
            _game->switchCurrentPlayer();
            _game->updateLevelStatus();

            buildBoard();
            fillLayoutWithBoard(ui->verticalLayout_4);

            updatePlayersMarble();
        }
        qDebug()<<"I moved";
    }  catch (...) {
        qDebug()<< "Error from move";
    }
}

void MainWindow::deselectCells() {
    for(auto & cell : _gHexaCells) {
        cell->setSelected(false);
        cell->update();
    }
}

void MainWindow::updatePlayersMarble() const {
    QString nbP1Marble = "marbles : ";
    int marblesP1 = _game->getIdxPlayerNbMarble(0);
    nbP1Marble.append(std::to_string(marblesP1).c_str());
    ui->p1marble->setText(nbP1Marble);

    QString nbP2Marble = "marbles : ";
    int marblesP2 = _game->getIdxPlayerNbMarble(1);
    nbP2Marble.append(std::to_string(marblesP2).c_str());
    ui->p2marble->setText(nbP2Marble);
}

bool MainWindow::checkIfIsSamePos(std::vector<int> const& position) const {
    if(position.size() == 4) {
        return position.at(0) == position.at(2) && position.at(1) == position.at(3);
    }
    return (position.at(0) == position.at(2) && position.at(1) == position.at(3))
            || (position.at(0) == position.at(4) && position.at(1) == position.at(5))
            || (position.at(2) == position.at(4) && position.at(3) == position.at(5));
}


int MainWindow::convertRow(char row) const {
    switch(row) {
    case 'A':
        return 8;
    case 'B':
        return 7;
    case 'C':
        return 6;
    case 'D':
        return 5;
    case 'E':
        return 4;
    case 'F':
        return 3;
    case 'G':
        return 2;
    case 'H':
        return 1;
    case 'I':
        return 0;
    }
    return -1;
}
