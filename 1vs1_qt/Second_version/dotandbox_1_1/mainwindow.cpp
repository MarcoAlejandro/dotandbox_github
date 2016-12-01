#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_b_play_clicked()
{
    Game_window = new game_window();
    Game_window->setAttribute(Qt::WA_DeleteOnClose);
    Game_window->setModal(true);
    Game_window->p1.set_id((this->ui->l_id1->text()).toStdString());
    Game_window->p2.set_id(this->ui->l_id2->text().toStdString());

    Game_window->start_game(1);

    Game_window->show();
}

void MainWindow::on_b_ai_play_clicked()
{
    Game_window = new game_window();
    Game_window->setAttribute(Qt::WA_DeleteOnClose);
    Game_window->setModal(true);
    Game_window->p1.set_id((this->ui->l_id1->text()).toStdString());
    Game_window->p2.set_id(this->ui->l_id2->text().toStdString());

    Game_window->start_game(2);

    Game_window->show();
}
