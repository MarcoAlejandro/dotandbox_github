#include "level_window.h"
#include "ui_level_window.h"

level_window::level_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::level_window)
{
    ui->setupUi(this);
}

level_window::~level_window()
{
    delete ui;
}
