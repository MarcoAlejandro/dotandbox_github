#ifndef LEVEL_WINDOW_H
#define LEVEL_WINDOW_H

#include <QDialog>

namespace Ui {
class level_window;
}

class level_window : public QDialog
{
    Q_OBJECT

public:
    explicit level_window(QWidget *parent = 0);
    ~level_window();

private:
    Ui::level_window *ui;
};

#endif // LEVEL_WINDOW_H
