#ifndef MAP_GRAPHICS_H
#define MAP_GRAPHICS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QColor>
#include <QThread>

#include <../../../dot_H/dot.H>
#include <../../../map/map.H>
#include <../../../player_H/player.H>
#include <../../../skyline/skyline_H/skyline.H>

#define PLAYER_TURN 2
#define IA_TURN 1

class map_graphics : public QGraphicsView
{
    Q_OBJECT
public:
    explicit map_graphics(QWidget *parent = 0);

    void start_graph();
    void for_test();

    bool check_move(QPointF &point);
    void draw_line(QPointF &point, QBrush &color);
    void draw_line(QPointF&, QPointF&,QBrush&);
    void refresh_dots();
    void act_score();
    QPointF dot_to_qpointf(std::pair<size_t,size_t>&dot_);
    std::pair<unsigned short, unsigned short> detect_dot(QPointF &point);
    uint p1_score, p2_score;


    //To delay:




public slots:
   void mousePressEvent(QMouseEvent *e);
   // void dotPressed()
   void mouseReleaseEvent(QMouseEvent *event);
   //void mouseMoveEvent()
   //void show_turn(int);

   //static void msleep(unsigned long);

signals:
    void refresh_score(uint,uint);
    void set_turn(int);


private:
    //HUD Atributes:
    QGraphicsScene *scene;

    QRectF *dot_00, *dot_01, *dot_02, *dot_03,
           *dot_10, *dot_11, *dot_12, *dot_13,
           *dot_20, *dot_21, *dot_22, *dot_23,
           *dot_30, *dot_31, *dot_32, *dot_33,
    //Lines (l_Fila_Columna):
        //HORIZONTAL:
           *l_00_01, *l_01_02, *l_02_03,
           *l_10_11, *l_11_12, *l_12_13,
           *l_20_21, *l_21_22, *l_22_23,
           *l_30_31, *l_31_32, *l_32_33,

        //VERTICAL:
           *l_00_10, *l_10_20, *l_20_30,
           *l_01_11, *l_11_21, *l_21_31,
           *l_02_12, *l_12_22, *l_22_32,
           *l_03_13, *l_13_23, *l_23_33;

    QColor *c_free;
    QColor *c_marked;
    QColor *c_marked2;
    QBrush *b_free;
    QBrush *b_marked;
    QBrush *b_marked2;
    QPointF *click_point;


    //Game Atributes:
    map<3,3> *m_game;
    MOVE cur_mv;
    int turn = PLAYER_TURN;
    //skyline sky;
   // size_t last_player;

};

#endif // MAP_GRAPHICS_H
