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
}

game_window::~game_window()
{
    delete ui;
}

void game_window::start_game(){
    //Player 1:
    this->ui->l_p1_id->setText(QString::fromStdString(this->p1.get_id()));
    //this->ui->l_p1_score->setText('0');
    //Player 2:
    this->ui->l_p2_id->setText(QString::fromStdString(this->p2.get_id()));
    //this->ui->l_p2_score->setText('0');
    this->ui->l_img->setVisible(true);
    this->ui->l_img_2->setVisible(false);


    this->ui->g_map->start_graph();
}

void game_window::act_score(uint a,uint b)
{
    //Player 1:
    this->ui->l_p1_score->setText(QString::number(a));
    //Player 2:
    this->ui->l_p2_score->setText(QString::number(b));

    //this->ui->l_p1_id->setFrameShape(QFrame::Box);
    //this->ui->l_p1_id->setStyleSheet("background-color: green");
    //this->ui->l_p1_id->setStyleSheet("color: white");
}

void game_window::show_turn(int t){
    if(t == 0)
    {
        this->ui->l_img->setVisible(true);
        this->ui->l_p1_id->setStyleSheet("background-color: green");
        this->ui->l_p2_id->setStyleSheet("background-color: none");


        this->ui->l_img_2->setVisible(false);
    }
    else if(t == 1)
    {
        this->ui->l_img->setVisible(false);
        this->ui->l_p1_id->setStyleSheet("background-color: none");
        this->ui->l_p2_id->setStyleSheet("background-color: gray");
        this->ui->l_img_2->setVisible(true);
    }
}
