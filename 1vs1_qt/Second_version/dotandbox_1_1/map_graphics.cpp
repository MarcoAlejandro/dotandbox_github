
#include "map_graphics.h"

map_graphics::map_graphics(QWidget *parent) :
    QGraphicsView(parent)
{
}

void map_graphics::start_graph()
{
    p1_score = 0;
    p2_score = 0;
    m_game = new map<3,3>;
    c_free = new QColor("navy");
    c_marked = new QColor("green");
    c_marked2 = new QColor("gray");
    b_free = new QBrush(*c_free,Qt::SolidPattern);
    b_marked = new QBrush(*c_marked, Qt::SolidPattern);
    b_marked2 = new QBrush(*c_marked2,Qt::SolidPattern);

    //Dots:
    dot_00 = new QRectF(0,30,20,20);
    dot_10 = new QRectF(0,130,20,20);
    dot_20 = new QRectF(0,230,20,20);

    dot_01 = new QRectF(100,30,20,20);
    dot_11 = new QRectF(100,130,20,20);
    dot_21 = new QRectF(100,230,20,20);

    dot_02 = new QRectF(200,30,20,20);
    dot_12 = new QRectF(200,130,20,20);
    dot_22 = new QRectF(200,230,20,20);

    //Lines:
        //vertical:
    l_00_10 = new QRectF(7,50,7,80);
    l_10_20 = new QRectF(7,150,7,80);

    l_01_11 = new QRectF(107,50,7,80);
    l_11_21 = new QRectF(107,150,7,80);

    l_02_12 = new QRectF(207,50,7,80);
    l_12_22 = new QRectF(207,150,7,80);
        //horizontal:
    l_00_01 = new QRectF(20,37,80,7);
    l_01_02 = new QRectF(120,37,80,7);

    l_10_11 = new QRectF(20,137,80,7);
    l_11_12 = new QRectF(120,137,80,7);

    l_20_21 = new QRectF(20,237,80,7);
    l_21_22 = new QRectF(120,237,80,7);


    this->scene = new QGraphicsScene();
    this->setScene(scene);

    //Adding dots:
    scene->addEllipse(*dot_00,*c_free,*b_free);
    scene->addEllipse(*dot_10,*c_free,*b_free);
    scene->addEllipse(*dot_20,*c_free,*b_free);

    scene->addEllipse(*dot_01,*c_free,*b_free);
    scene->addEllipse(*dot_11,*c_free,*b_free);
    scene->addEllipse(*dot_21,*c_free,*b_free);

    scene->addEllipse(*dot_02,*c_free,*b_free);
    scene->addEllipse(*dot_12,*c_free,*b_free);
    scene->addEllipse(*dot_22,*c_free,*b_free);

    act_score();
    emit refresh_score(p1_score,p2_score);
    emit set_turn(turn);



/*
    //Adding lines:
        //vertical:
    scene->addRect(*l_00_10,*c_free,*b_marked);
    scene->addRect(*l_10_20,*c_free,*b_marked);

    scene->addRect(*l_01_11,*c_free,*b_marked);
    scene->addRect(*l_11_21,*c_free,*b_marked);

    scene->addRect(*l_02_12,*c_free,*b_marked);
    scene->addRect(*l_12_22,*c_free,*b_marked);

        //horizontal:
    scene->addRect(*l_00_01,*c_free,*b_marked);
    scene->addRect(*l_01_02,*c_free,*b_marked);

    scene->addRect(*l_10_11,*c_free,*b_marked);
    scene->addRect(*l_11_12,*c_free,*b_marked);

    scene->addRect(*l_20_21,*c_free,*b_marked);
    scene->addRect(*l_21_22,*c_free,*b_marked);
    */


}


void map_graphics::mousePressEvent(QMouseEvent *e)
{
    click_point = new QPointF(this->mapToScene(e->pos()));

    if(e->button() == Qt::LeftButton)
    {
        if(dot_00->contains(*click_point))
            scene->addEllipse(*dot_00,*c_marked,*b_marked);
        else if(dot_01->contains(*click_point))
            scene->addEllipse(*dot_01,*c_marked,*b_marked);
        else if(dot_02->contains(*click_point))
            scene->addEllipse(*dot_02,*c_marked,*b_marked);
        else if(dot_10->contains(*click_point))
            scene->addEllipse(*dot_10,*c_marked,*b_marked);
        else if(dot_11->contains(*click_point))
            scene->addEllipse(*dot_11,*c_marked,*b_marked);
        else if(dot_12->contains(*click_point))
            scene->addEllipse(*dot_12,*c_marked,*b_marked);
        else if(dot_20->contains(*click_point))
            scene->addEllipse(*dot_20,*c_marked,*b_marked);
        else if(dot_21->contains(*click_point))
            scene->addEllipse(*dot_21,*c_marked,*b_marked);
        else if(dot_22->contains(*click_point))
            scene->addEllipse(*dot_22,*c_marked,*b_marked);
    }

}

void map_graphics::mouseReleaseEvent(QMouseEvent *event)
{
    QPointF release_point = this->mapToScene(event->pos());
    std::get<0>(cur_mv) = detect_dot(*click_point);
    std::get<1>(cur_mv) = detect_dot(release_point);

    if(dot_00->contains(release_point))
        scene->addEllipse(*dot_00,*c_marked,*b_marked);
    else if(dot_01->contains(release_point))
        scene->addEllipse(*dot_01,*c_marked,*b_marked);
    else if(dot_02->contains(release_point))
        scene->addEllipse(*dot_02,*c_marked,*b_marked);
    else if(dot_10->contains(release_point))
        scene->addEllipse(*dot_10,*c_marked,*b_marked);
    else if(dot_11->contains(release_point))
        scene->addEllipse(*dot_11,*c_marked,*b_marked);
    else if(dot_12->contains(release_point))
        scene->addEllipse(*dot_12,*c_marked,*b_marked);
    else if(dot_20->contains(release_point))
        scene->addEllipse(*dot_20,*c_marked,*b_marked);
    else if(dot_21->contains(release_point))
        scene->addEllipse(*dot_21,*c_marked,*b_marked);
    else if(dot_22->contains(release_point))
        scene->addEllipse(*dot_22,*c_marked,*b_marked);

    if(check_move(release_point))
    {
        if(turn == 0)
        {
            draw_line(release_point, *b_marked);

            p1_score = m_game->get_p1_score();
            m_game->play(cur_mv,1);
            if(p1_score == m_game->get_p1_score())
                turn = 1;
        }
        else
        {
            draw_line(release_point, *b_marked2);

            p2_score = m_game->get_p2_score();
            m_game->play(cur_mv,2);
            if(p2_score == m_game->get_p2_score())
                turn = 0;
        }

    }

    act_score();
    emit refresh_score(p1_score,p2_score);
    emit set_turn(turn);
    refresh_dots();
    //refresh_dots();


}

std::pair<unsigned short,unsigned short> map_graphics::detect_dot(QPointF &point)
{
    std::pair<unsigned short,unsigned short> dot;
    if(dot_00->contains(point))
    {
        return dot = std::make_pair(0,0);
    }
    else if(dot_01->contains(point))
    {
        return dot = std::make_pair(0,1);

    }
    else if(dot_02->contains(point))
    {
        return dot = std::make_pair(0,2);

    }
    else if(dot_10->contains(point))
    {
        return dot = std::make_pair(1,0);

    }
    else if(dot_11->contains(point))
    {
        return dot = std::make_pair(1,1);

    }
    else if(dot_12->contains(point))
    {
        return dot = std::make_pair(1,2);

    }
    else if(dot_20->contains(point))
    {
        return dot = std::make_pair(2,0);

    }
    else if(dot_21->contains(point))
    {
        return dot = std::make_pair(2,1);

    }
    else if(dot_22->contains(point))
    {
        return dot = std::make_pair(2,2);

    }
}

bool map_graphics::check_move(QPointF &point)
{
    //For dot00:
    if(dot_00->contains(*click_point) and (dot_01->contains(point) or
                                           dot_10->contains(point)) )
        return true;
    //For dot01:
    if(dot_01->contains(*click_point) and (dot_00->contains(point) or
                                           dot_11->contains(point) or
                                           dot_02->contains(point)) )
        return true;
    //For dot02:
    if(dot_02->contains(*click_point) and (dot_02->contains(point) or
                                           dot_12->contains(point)) )
        return true;
    //For dot10
    if(dot_10->contains(*click_point) and (dot_00->contains(point) or
                                           dot_11->contains(point) or
                                           dot_20->contains(point)) )
        return true;
    //For dot11:
    if(dot_11->contains(*click_point) and (dot_01->contains(point) or
                                           dot_12->contains(point) or
                                           dot_21->contains(point) or
                                           dot_10->contains(point)) )
        return true;
    //For dot12:
    if(dot_12->contains(*click_point) and (dot_02->contains(point) or
                                           dot_11->contains(point) or
                                           dot_22->contains(point)) )
        return true;
    //For dot20:
    if(dot_20->contains(*click_point) and (dot_10->contains(point) or
                                           dot_21->contains(point)) )
        return true;
    //For dot21:
    if(dot_21->contains(*click_point) and (dot_11->contains(point) or
                                           dot_20->contains(point) or
                                           dot_22->contains(point)) )
        return true;
    //For dot22:
    if(dot_22->contains(*click_point) and (dot_12->contains(point) or
                                           dot_21->contains(point)) )
        return true;

    return false;
}

void map_graphics::draw_line(QPointF &point, QBrush &color)
{
    //Horizontal:
    if( (dot_00->contains(*click_point) and dot_01->contains(point)) or
       (dot_00->contains(point) and dot_01->contains(*click_point)) )
        scene->addRect(*l_00_01,*c_free,color);

    if( (dot_01->contains(*click_point) and dot_02->contains(point)) or
       (dot_01->contains(point) and dot_02->contains(*click_point)) )
        scene->addRect(*l_01_02,*c_free,color);

    if( (dot_10->contains(*click_point) and dot_11->contains(point)) or
       (dot_10->contains(point) and dot_11->contains(*click_point)) )
        scene->addRect(*l_10_11,*c_free,color);

    if( (dot_11->contains(*click_point) and dot_12->contains(point)) or
       (dot_11->contains(point) and dot_12->contains(*click_point)) )
        scene->addRect(*l_11_12,*c_free,color);

    if( (dot_20->contains(*click_point) and dot_21->contains(point)) or
       (dot_20->contains(point) and dot_21->contains(*click_point)) )
        scene->addRect(*l_20_21,*c_free,color);

    if( (dot_21->contains(*click_point) and dot_22->contains(point)) or
       (dot_21->contains(point) and dot_22->contains(*click_point)) )
        scene->addRect(*l_21_22,*c_free,color);
    //Vertical:
    if( (dot_00->contains(*click_point) and dot_10->contains(point)) or
       (dot_00->contains(point) and dot_10->contains(*click_point)) )
        scene->addRect(*l_00_10,*c_free,color);

    if( (dot_10->contains(*click_point) and dot_20->contains(point)) or
       (dot_10->contains(point) and dot_20->contains(*click_point)) )
        scene->addRect(*l_10_20,*c_free,color);

    if( (dot_01->contains(*click_point) and dot_11->contains(point)) or
       (dot_01->contains(point) and dot_11->contains(*click_point)) )
        scene->addRect(*l_01_11,*c_free,color);

    if( (dot_11->contains(*click_point) and dot_21->contains(point)) or
       (dot_11->contains(point) and dot_21->contains(*click_point)) )
        scene->addRect(*l_11_21,*c_free,color);

    if( (dot_02->contains(*click_point) and dot_12->contains(point)) or
       (dot_02->contains(point) and dot_12->contains(*click_point)) )
        scene->addRect(*l_02_12,*c_free,color);

    if( (dot_12->contains(*click_point) and dot_22->contains(point)) or
       (dot_12->contains(point) and dot_22->contains(*click_point)) )
        scene->addRect(*l_12_22,*c_free,color);

}

void map_graphics::refresh_dots()
{
    scene->addEllipse(*dot_00,*c_free,*b_free);
    scene->addEllipse(*dot_10,*c_free,*b_free);
    scene->addEllipse(*dot_20,*c_free,*b_free);

    scene->addEllipse(*dot_01,*c_free,*b_free);
    scene->addEllipse(*dot_11,*c_free,*b_free);
    scene->addEllipse(*dot_21,*c_free,*b_free);

    scene->addEllipse(*dot_02,*c_free,*b_free);
    scene->addEllipse(*dot_12,*c_free,*b_free);
    scene->addEllipse(*dot_22,*c_free,*b_free);
}

void map_graphics::act_score()
{
    p1_score = m_game->get_p1_score();
    p2_score = m_game->get_p2_score();
}

