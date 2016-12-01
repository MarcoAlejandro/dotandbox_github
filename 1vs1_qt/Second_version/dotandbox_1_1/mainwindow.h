#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <game_window.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_b_play_clicked();

    void on_b_ai_play_clicked();

private:
    Ui::MainWindow *ui;
    game_window *Game_window;
};

#endif // MAINWINDOW_H
