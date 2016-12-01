#include "game_window.h"
#include "ui_game_window.h"
#include <map_graphics.h>

game_window::game_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game_window)
{
    ui->setupUi(this);

    connect(ui->g_map,SIGNAL(refresh_score(uint,uint)),this,
            SLOT(act_score(uint,uint)));

    connect(ui->g_map,SIGNAL(set_turn(int)),this,SLOT(show_turn(int)));

    this->ui->l_p1_id->setStyleSheet("background-color: #EB7F0C");
    this->ui->l_p2_id->setStyleSheet("background-color: #0C6DEB");

}

game_window::~game_window()
{
    delete ui;
}

void game_window::start_game(ushort p_or_ai){
    //This flag is necessary to reset the game:
    _p_or_ai = p_or_ai;
    //Player 1:
    this->ui->l_p1_id->setText(QString::fromStdString(this->p1.get_id()));
    //Player 2:
    this->ui->l_p2_id->setText(QString::fromStdString(this->p2.get_id()));
    //Showing image for turn:
    this->ui->l_img->setVisible(true);
    this->ui->l_img_2->setVisible(false);

    //Starting the game:
    this->ui->g_map->start_graph(p_or_ai);
}

void game_window::act_score(uint a,uint b)
{
    //Player 1:
    this->ui->l_p1_score->setText(QString::number(a));
    //Player 2:
    this->ui->l_p2_score->setText(QString::number(b));
}

void game_window::show_turn(int t){
    if(t == 2)
    {
        this->ui->l_img->setVisible(true);
        this->ui->l_img_2->setVisible(false);
    }
    else if(t == 1)
    {
        this->ui->l_img->setVisible(false);
        this->ui->l_img_2->setVisible(true);
    }
}

void game_window::on_b_exit_clicked()
{
    this->close();
}

void game_window::on_b_reset_clicked()
{
    this->start_game(this->_p_or_ai);
}
