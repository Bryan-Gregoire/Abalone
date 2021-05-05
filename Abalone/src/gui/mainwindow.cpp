#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

#include "model/Game.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      _game {},
      _gHexaCells {}
{
    ui->setupUi(this);

    const double r = 46;
    for (unsigned int i = 0;i < abalone::Board::SIZE;i++ ) {
        for (unsigned int j = 0; j < abalone::Board::SIZE ;j++ ) {
            if(_game.getBoard().isInsideBoard(i,j)) {
                if(i % 2 == 0) {
                    _gHexaCells.push_back(new GHexaCell(i * 2 * r * 3 / 4, (sqrt(3) * r) * j + i * r, r,
                                                        std::to_string(i) + std::to_string(j),nullptr));
                } else {
                    _gHexaCells.push_back(new GHexaCell(i * 2 * r * 3 / 4, (sqrt(3) * r) * j + i * r, r,
                                                        std::to_string(i)
                                                        + std::to_string(j),nullptr));
                }
            }
        }
    }
    /* + i * r */
    /* + i * r */
    auto scene = new QGraphicsScene();

    std::for_each(begin(_gHexaCells), end(_gHexaCells),
                  [this, scene](GHexaCell * e) {
        e->setPos(e->y(), e->x());
        scene->addItem(e);
        QObject::connect(e,
                         SIGNAL(sendValue(std::string)),
                         this,
                         SLOT(on_ghexacell_clicked(std::string)));
    });
    auto view = new QGraphicsView(scene);
    view->update();
    ui->verticalLayout_4->addWidget(view);

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

void MainWindow::on_ghexacell_clicked(std::string value)
{
    ui->label->setText(value.c_str());
    std::string s = "receveive value from ghexacell ";
    s.append(value);
    qDebug() << s.c_str();
}

