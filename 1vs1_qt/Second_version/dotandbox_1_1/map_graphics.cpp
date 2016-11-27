
#include "map_graphics.h"

map_graphics::map_graphics(QWidget *parent) :
    QGraphicsView(parent)
{
    m_game = new map<4,4>;
    sky = new skyline<4>(*m_game, cur_mv);
}

void map_graphics::start_graph()
{

    p1_score = 0;
    p2_score = 0;
    c_free = new QColor("000000");
    box_paint1 = new QBrush("#0C6DEB",Qt::SolidPattern);
    box_paint2 = new QBrush("#EB7F0C",Qt::SolidPattern);
    c_marked = new QColor("#EB7F0C");
    c_marked2 = new QColor("#0C6DEB");
    b_free = new QBrush(*c_free,Qt::SolidPattern);
    b_marked = new QBrush(*c_marked, Qt::SolidPattern);
    b_marked2 = new QBrush(*c_marked2,Qt::SolidPattern);

    //Dots:
    dot_00 = new QRectF(0,30,20,20);
    dot_10 = new QRectF(0,130,20,20);
    dot_20 = new QRectF(0,230,20,20);
    dot_30 = new QRectF(0,330,20,20);

    dot_01 = new QRectF(100,30,20,20);
    dot_11 = new QRectF(100,130,20,20);
    dot_21 = new QRectF(100,230,20,20);
    dot_31 = new QRectF(100,330,20,20);

    dot_02 = new QRectF(200,30,20,20);
    dot_12 = new QRectF(200,130,20,20);
    dot_22 = new QRectF(200,230,20,20);
    dot_32 = new QRectF(200,330,20,20);

    dot_03 = new QRectF(300,30,20,20);
    dot_13 = new QRectF(300,130,20,20);
    dot_23 = new QRectF(300,230,20,20);
    dot_33 = new QRectF(300,330,20,20);

    //Lines:
        //vertical:
    l_00_10 = new QRectF(7,50,7,80);
    l_10_20 = new QRectF(7,150,7,80);
    l_20_30 = new QRectF(7,250,7,80);

    l_01_11 = new QRectF(107,50,7,80);
    l_11_21 = new QRectF(107,150,7,80);
    l_21_31 = new QRectF(107,250,7,80);

    l_02_12 = new QRectF(207,50,7,80);
    l_12_22 = new QRectF(207,150,7,80);
    l_22_32 = new QRectF(207,250,7,80);

    l_03_13 = new QRectF(307,50,7,80);
    l_13_23 = new QRectF(307,150,7,80);
    l_23_33 = new QRectF(307,250,7,80);

        //horizontal:
    l_00_01 = new QRectF(20,37,80,7);
    l_01_02 = new QRectF(120,37,80,7);
    l_02_03 = new QRectF(220,37,80,7);

    l_10_11 = new QRectF(20,137,80,7);
    l_11_12 = new QRectF(120,137,80,7);
    l_12_13 = new QRectF(220,137,80,7);

    l_20_21 = new QRectF(20,237,80,7);
    l_21_22 = new QRectF(120,237,80,7);
    l_22_23 = new QRectF(220,237,80,7);

    l_30_31 = new QRectF(20,337,80,7);
    l_31_32 = new QRectF(120,337,80,7);
    l_32_33 = new QRectF(220,337,80,7);

    //Cuadro Punto

    box_01 = new QRectF(10,37,100,105);


    this->scene = new QGraphicsScene();
    this->setScene(scene);

    //Adding dots:
    scene->addEllipse(*dot_00,*c_free,*b_free);
    scene->addEllipse(*dot_10,*c_free,*b_free);
    scene->addEllipse(*dot_20,*c_free,*b_free);
    scene->addEllipse(*dot_30,*c_free,*b_free);

    scene->addEllipse(*dot_01,*c_free,*b_free);
    scene->addEllipse(*dot_11,*c_free,*b_free);
    scene->addEllipse(*dot_21,*c_free,*b_free);
    scene->addEllipse(*dot_31,*c_free,*b_free);

    scene->addEllipse(*dot_02,*c_free,*b_free);
    scene->addEllipse(*dot_12,*c_free,*b_free);
    scene->addEllipse(*dot_22,*c_free,*b_free);
    scene->addEllipse(*dot_32,*c_free,*b_free);

    scene->addEllipse(*dot_03,*c_free,*b_free);
    scene->addEllipse(*dot_13,*c_free,*b_free);
    scene->addEllipse(*dot_23,*c_free,*b_free);
    scene->addEllipse(*dot_33,*c_free,*b_free);


    //Adding box point

    //scene->addRect(*box_01,*c_free,*box_paint1);

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

        else if(dot_03->contains(*click_point))
            scene->addEllipse(*dot_03,*c_marked,*b_marked);

        else if(dot_10->contains(*click_point))
            scene->addEllipse(*dot_10,*c_marked,*b_marked);

        else if(dot_11->contains(*click_point))
            scene->addEllipse(*dot_11,*c_marked,*b_marked);

        else if(dot_12->contains(*click_point))
            scene->addEllipse(*dot_12,*c_marked,*b_marked);

        else if(dot_13->contains(*click_point))
            scene->addEllipse(*dot_13,*c_marked,*b_marked);

        else if(dot_20->contains(*click_point))
            scene->addEllipse(*dot_20,*c_marked,*b_marked);

        else if(dot_21->contains(*click_point))
            scene->addEllipse(*dot_21,*c_marked,*b_marked);

        else if(dot_22->contains(*click_point))
            scene->addEllipse(*dot_22,*c_marked,*b_marked);

        else if(dot_23->contains(*click_point))
            scene->addEllipse(*dot_23,*c_marked,*b_marked);

        else if(dot_30->contains(*click_point))
            scene->addEllipse(*dot_30,*c_marked,*b_marked);

        else if(dot_31->contains(*click_point))
            scene->addEllipse(*dot_31,*c_marked,*b_marked);

        else if(dot_32->contains(*click_point))
            scene->addEllipse(*dot_32,*c_marked,*b_marked);

        else if(dot_33->contains(*click_point))
            scene->addEllipse(*dot_33,*c_marked,*b_marked);
    }

}

void map_graphics::mouseReleaseEvent(QMouseEvent *event)
{
    if(turn==PLAYER_TURN)
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
            else if(dot_03->contains(release_point))
                scene->addEllipse(*dot_03,*c_marked,*b_marked);
            else if(dot_10->contains(release_point))
                scene->addEllipse(*dot_10,*c_marked,*b_marked);
            else if(dot_11->contains(release_point))
                scene->addEllipse(*dot_11,*c_marked,*b_marked);
            else if(dot_12->contains(release_point))
                scene->addEllipse(*dot_12,*c_marked,*b_marked);
            else if(dot_13->contains(release_point))
                scene->addEllipse(*dot_13,*c_marked,*b_marked);
            else if(dot_20->contains(release_point))
                scene->addEllipse(*dot_20,*c_marked,*b_marked);
            else if(dot_21->contains(release_point))
                scene->addEllipse(*dot_21,*c_marked,*b_marked);
            else if(dot_22->contains(release_point))
                scene->addEllipse(*dot_22,*c_marked,*b_marked);
            else if(dot_23->contains(release_point))
                scene->addEllipse(*dot_23,*c_marked,*b_marked);
            else if(dot_30->contains(release_point))
                scene->addEllipse(*dot_30,*c_marked,*b_marked);
            else if(dot_31->contains(release_point))
                scene->addEllipse(*dot_31,*c_marked,*b_marked);
            else if(dot_32->contains(release_point))
                scene->addEllipse(*dot_32,*c_marked,*b_marked);
            else if(dot_33->contains(release_point))
                scene->addEllipse(*dot_33,*c_marked,*b_marked);

            if(check_move(release_point))
            {
                draw_line(release_point, *b_marked);

                p2_score = m_game->get_p2_score();
                m_game->play(cur_mv,PLAYER_TURN);

                if(p2_score != m_game->get_p2_score())
                {
                    //sky->check_play(*m_game,cur_mv,PLAYER_TURN);
                    sky->blind_move();
                }
                else
                {
                    sky->check_play(*m_game,cur_mv,PLAYER_TURN);
                    turn = IA_TURN;

                }
            }
    }
    if(turn==IA_TURN)
    {
        ia_play();
    }

    act_score();
    emit refresh_score(p2_score,p1_score);
    emit set_turn(turn);
    refresh_dots();
}

void map_graphics::ia_play()
{
        while(turn==IA_TURN and !m_game->is_full())
        {
            p1_score = m_game->get_p1_score();
            cur_mv = sky->AI_play();
            m_game->play(cur_mv,IA_TURN);

            QPointF par1 = dot_to_qpointf(std::get<0>(cur_mv));
            QPointF par2 = dot_to_qpointf(std::get<1>(cur_mv));

            /*if(dot_00->contains(par2))
                scene->addEllipse(*dot_00,*c_marked,*b_marked);
            else if(dot_01->contains(par2))
                scene->addEllipse(*dot_01,*c_marked,*b_marked);
            else if(dot_02->contains(par2))
                scene->addEllipse(*dot_02,*c_marked,*b_marked);
            else if(dot_03->contains(par2))
                scene->addEllipse(*dot_03,*c_marked,*b_marked);
            else if(dot_10->contains(par2))
                scene->addEllipse(*dot_10,*c_marked,*b_marked);
            else if(dot_11->contains(par2))
                scene->addEllipse(*dot_11,*c_marked,*b_marked);
            else if(dot_12->contains(par2))
                scene->addEllipse(*dot_12,*c_marked,*b_marked);
            else if(dot_13->contains(par2))
                scene->addEllipse(*dot_13,*c_marked,*b_marked);
            else if(dot_20->contains(par2))
                scene->addEllipse(*dot_20,*c_marked,*b_marked);
            else if(dot_21->contains(par2))
                scene->addEllipse(*dot_21,*c_marked,*b_marked);
            else if(dot_22->contains(par2))
                scene->addEllipse(*dot_22,*c_marked,*b_marked);
            else if(dot_23->contains(par2))
                scene->addEllipse(*dot_23,*c_marked,*b_marked);
            else if(dot_30->contains(par2))
                scene->addEllipse(*dot_30,*c_marked,*b_marked);
            else if(dot_31->contains(par2))
                scene->addEllipse(*dot_31,*c_marked,*b_marked);
            else if(dot_32->contains(par2))
                scene->addEllipse(*dot_32,*c_marked,*b_marked);
            else if(dot_33->contains(par2))
                scene->addEllipse(*dot_33,*c_marked,*b_marked);*/

            draw_line(par1, par2, *b_marked2);

            if(p1_score != m_game->get_p1_score())
            {
                sky->check_play(*m_game,cur_mv,IA_TURN);
            }
            else
            {
                //sky->check_play(*m_game, cur_mv,IA_TURN);
                sky->blind_move();
                turn = PLAYER_TURN;
            }

            act_score();
            emit refresh_score(p2_score,p1_score);
            emit set_turn(turn);
            refresh_dots();
       }
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
    else if(dot_03->contains(point))
    {
        return dot = std::make_pair(0,3);

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
    else if(dot_13->contains(point))
    {
        return dot = std::make_pair(1,3);

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
    else if(dot_23->contains(point))
    {
        return dot = std::make_pair(2,3);

    }
    else if(dot_30->contains(point))
    {
        return dot = std::make_pair(3,0);

    }
    else if(dot_31->contains(point))
    {
        return dot = std::make_pair(3,1);

    }
    else if(dot_32->contains(point))
    {
        return dot = std::make_pair(3,2);

    }
    else if(dot_33->contains(point))
    {
        return dot = std::make_pair(3,3);

    }
}

//void map_graphics::msleep(unsigned long msecs){QThread::msleep(msecs);}

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
    if(dot_02->contains(*click_point) and (dot_01->contains(point) or
                                           dot_03->contains(point) or
                                           dot_12->contains(point)) )
        return true;
    //For dot03:
    if(dot_03->contains(*click_point) and (dot_02->contains(point) or
                                           dot_13->contains(point)) )
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
                                           dot_13->contains(point) or
                                           dot_22->contains(point)) )
        return true;
    //For dot13:
    if(dot_13->contains(*click_point) and (dot_03->contains(point) or
                                           dot_12->contains(point) or
                                           dot_23->contains(point)) )
        return true;
    //For dot20:
    if(dot_20->contains(*click_point) and (dot_10->contains(point) or
                                           dot_30->contains(point) or
                                           dot_21->contains(point)) )
        return true;
    //For dot21:
    if(dot_21->contains(*click_point) and (dot_11->contains(point) or
                                           dot_20->contains(point) or
                                           dot_31->contains(point) or
                                           dot_22->contains(point)) )
        return true;
    //For dot22:
    if(dot_22->contains(*click_point) and (dot_12->contains(point) or
                                           dot_23->contains(point) or
                                           dot_32->contains(point) or
                                           dot_21->contains(point)) )
        return true;
    //For dot23:
    if(dot_23->contains(*click_point) and (dot_13->contains(point) or
                                           dot_22->contains(point) or
                                           dot_33->contains(point)) )
        return true;
    //For dot30:
    if(dot_30->contains(*click_point) and (dot_20->contains(point) or
                                           dot_31->contains(point)) )
        return true;
    //For dot31:
    if(dot_31->contains(*click_point) and (dot_21->contains(point) or
                                           dot_30->contains(point) or
                                           dot_32->contains(point)) )
        return true;
    //For dot32:
    if(dot_32->contains(*click_point) and (dot_22->contains(point) or
                                           dot_31->contains(point) or
                                           dot_33->contains(point)) )
        return true;

    //For dot33:
    if(dot_33->contains(*click_point) and (dot_32->contains(point) or
                                           dot_23->contains(point)) )
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

    if( (dot_02->contains(*click_point) and dot_03->contains(point)) or
       (dot_02->contains(point) and dot_03->contains(*click_point)) )
        scene->addRect(*l_02_03,*c_free,color);

    if( (dot_10->contains(*click_point) and dot_11->contains(point)) or
       (dot_10->contains(point) and dot_11->contains(*click_point)) )
        scene->addRect(*l_10_11,*c_free,color);

    if( (dot_11->contains(*click_point) and dot_12->contains(point)) or
       (dot_11->contains(point) and dot_12->contains(*click_point)) )
        scene->addRect(*l_11_12,*c_free,color);

    if( (dot_12->contains(*click_point) and dot_13->contains(point)) or
       (dot_12->contains(point) and dot_13->contains(*click_point)) )
        scene->addRect(*l_12_13,*c_free,color);

    if( (dot_20->contains(*click_point) and dot_21->contains(point)) or
       (dot_20->contains(point) and dot_21->contains(*click_point)) )
        scene->addRect(*l_20_21,*c_free,color);

    if( (dot_21->contains(*click_point) and dot_22->contains(point)) or
       (dot_21->contains(point) and dot_22->contains(*click_point)) )
        scene->addRect(*l_21_22,*c_free,color);

    if( (dot_22->contains(*click_point) and dot_23->contains(point)) or
       (dot_22->contains(point) and dot_23->contains(*click_point)) )
        scene->addRect(*l_22_23,*c_free,color);

    if( (dot_30->contains(*click_point) and dot_31->contains(point)) or
       (dot_30->contains(point) and dot_31->contains(*click_point)) )
        scene->addRect(*l_30_31,*c_free,color);

    if( (dot_31->contains(*click_point) and dot_32->contains(point)) or
       (dot_31->contains(point) and dot_32->contains(*click_point)) )
        scene->addRect(*l_31_32,*c_free,color);

    if( (dot_32->contains(*click_point) and dot_33->contains(point)) or
       (dot_32->contains(point) and dot_33->contains(*click_point)) )
        scene->addRect(*l_32_33,*c_free,color);
    //Vertical:
    if( (dot_00->contains(*click_point) and dot_10->contains(point)) or
       (dot_00->contains(point) and dot_10->contains(*click_point)) )
        scene->addRect(*l_00_10,*c_free,color);

    if( (dot_10->contains(*click_point) and dot_20->contains(point)) or
       (dot_10->contains(point) and dot_20->contains(*click_point)) )
        scene->addRect(*l_10_20,*c_free,color);

    if( (dot_20->contains(*click_point) and dot_30->contains(point)) or
       (dot_20->contains(point) and dot_30->contains(*click_point)) )
        scene->addRect(*l_20_30,*c_free,color);

    if( (dot_01->contains(*click_point) and dot_11->contains(point)) or
       (dot_01->contains(point) and dot_11->contains(*click_point)) )
        scene->addRect(*l_01_11,*c_free,color);

    if( (dot_11->contains(*click_point) and dot_21->contains(point)) or
       (dot_11->contains(point) and dot_21->contains(*click_point)) )
        scene->addRect(*l_11_21,*c_free,color);

    if( (dot_21->contains(*click_point) and dot_31->contains(point)) or
       (dot_21->contains(point) and dot_31->contains(*click_point)) )
        scene->addRect(*l_21_31,*c_free,color);

    if( (dot_02->contains(*click_point) and dot_12->contains(point)) or
       (dot_02->contains(point) and dot_12->contains(*click_point)) )
        scene->addRect(*l_02_12,*c_free,color);

    if( (dot_12->contains(*click_point) and dot_22->contains(point)) or
       (dot_12->contains(point) and dot_22->contains(*click_point)) )
        scene->addRect(*l_12_22,*c_free,color);

    if( (dot_22->contains(*click_point) and dot_32->contains(point)) or
       (dot_22->contains(point) and dot_32->contains(*click_point)) )
        scene->addRect(*l_22_32,*c_free,color);

    if( (dot_03->contains(*click_point) and dot_13->contains(point)) or
       (dot_03->contains(point) and dot_13->contains(*click_point)) )
        scene->addRect(*l_03_13,*c_free,color);

    if( (dot_13->contains(*click_point) and dot_23->contains(point)) or
       (dot_13->contains(point) and dot_23->contains(*click_point)) )
        scene->addRect(*l_13_23,*c_free,color);

    if( (dot_23->contains(*click_point) and dot_33->contains(point)) or
       (dot_23->contains(point) and dot_33->contains(*click_point)) )
        scene->addRect(*l_23_33,*c_free,color);

}

void map_graphics::draw_line(QPointF &first_point, QPointF &second_point, QBrush &color)
{
    //Horizontal:
    if( (dot_00->contains(first_point) and dot_01->contains(second_point)) or
       (dot_00->contains(second_point) and dot_01->contains(first_point)) )
        scene->addRect(*l_00_01,*c_free,color);

    if( (dot_01->contains(first_point) and dot_02->contains(second_point)) or
       (dot_01->contains(second_point) and dot_02->contains(first_point)) )
        scene->addRect(*l_01_02,*c_free,color);

    if( (dot_02->contains(first_point) and dot_03->contains(second_point)) or
       (dot_02->contains(second_point) and dot_03->contains(first_point)) )
        scene->addRect(*l_02_03,*c_free,color);


    if( (dot_10->contains(first_point) and dot_11->contains(second_point)) or
       (dot_10->contains(second_point) and dot_11->contains(first_point)) )
        scene->addRect(*l_10_11,*c_free,color);

    if( (dot_11->contains(first_point) and dot_12->contains(second_point)) or
       (dot_11->contains(second_point) and dot_12->contains(first_point)) )
        scene->addRect(*l_11_12,*c_free,color);

    if( (dot_12->contains(first_point) and dot_13->contains(second_point)) or
       (dot_12->contains(second_point) and dot_13->contains(first_point)) )
        scene->addRect(*l_12_13,*c_free,color);

    if( (dot_20->contains(first_point) and dot_21->contains(second_point)) or
       (dot_20->contains(second_point) and dot_21->contains(first_point)) )
        scene->addRect(*l_20_21,*c_free,color);

    if( (dot_21->contains(first_point) and dot_22->contains(second_point)) or
       (dot_21->contains(second_point) and dot_22->contains(first_point)) )
        scene->addRect(*l_21_22,*c_free,color);

    if( (dot_22->contains(first_point) and dot_23->contains(second_point)) or
       (dot_22->contains(second_point) and dot_23->contains(first_point)) )
        scene->addRect(*l_22_23,*c_free,color);

    if( (dot_30->contains(first_point) and dot_31->contains(second_point)) or
       (dot_30->contains(second_point) and dot_31->contains(first_point)) )
        scene->addRect(*l_30_31,*c_free,color);

    if( (dot_31->contains(first_point) and dot_32->contains(second_point)) or
       (dot_31->contains(second_point) and dot_32->contains(first_point)) )
        scene->addRect(*l_31_32,*c_free,color);

    if( (dot_32->contains(first_point) and dot_33->contains(second_point)) or
       (dot_32->contains(second_point) and dot_33->contains(first_point)) )
        scene->addRect(*l_32_33,*c_free,color);


    //Vertical:
    if( (dot_00->contains(first_point) and dot_10->contains(second_point)) or
       (dot_00->contains(second_point) and dot_10->contains(first_point)) )
        scene->addRect(*l_00_10,*c_free,color);

    if( (dot_10->contains(first_point) and dot_20->contains(second_point)) or
       (dot_10->contains(second_point) and dot_20->contains(first_point)) )
        scene->addRect(*l_10_20,*c_free,color);

    if( (dot_20->contains(first_point) and dot_30->contains(second_point)) or
       (dot_20->contains(second_point) and dot_30->contains(first_point)) )
        scene->addRect(*l_20_30,*c_free,color);

    if( (dot_01->contains(first_point) and dot_11->contains(second_point)) or
       (dot_01->contains(second_point) and dot_11->contains(first_point)) )
        scene->addRect(*l_01_11,*c_free,color);

    if( (dot_11->contains(first_point) and dot_21->contains(second_point)) or
       (dot_11->contains(second_point) and dot_21->contains(first_point)) )
        scene->addRect(*l_11_21,*c_free,color);

    if( (dot_21->contains(first_point) and dot_31->contains(second_point)) or
       (dot_21->contains(second_point) and dot_31->contains(first_point)) )
        scene->addRect(*l_21_31,*c_free,color);

    if( (dot_02->contains(first_point) and dot_12->contains(second_point)) or
       (dot_02->contains(second_point) and dot_12->contains(first_point)) )
        scene->addRect(*l_02_12,*c_free,color);

    if( (dot_12->contains(first_point) and dot_22->contains(second_point)) or
       (dot_12->contains(second_point) and dot_22->contains(first_point)) )
        scene->addRect(*l_12_22,*c_free,color);

    if( (dot_22->contains(first_point) and dot_32->contains(second_point)) or
       (dot_22->contains(second_point) and dot_32->contains(first_point)) )
        scene->addRect(*l_22_32,*c_free,color);

    if( (dot_03->contains(first_point) and dot_13->contains(second_point)) or
       (dot_03->contains(second_point) and dot_13->contains(first_point)) )
        scene->addRect(*l_03_13,*c_free,color);

    if( (dot_13->contains(first_point) and dot_23->contains(second_point)) or
       (dot_13->contains(second_point) and dot_23->contains(first_point)) )
        scene->addRect(*l_13_23,*c_free,color);

    if( (dot_23->contains(first_point) and dot_33->contains(second_point)) or
       (dot_23->contains(second_point) and dot_33->contains(first_point)) )
        scene->addRect(*l_23_33,*c_free,color);

}

void map_graphics::refresh_dots()
{
    scene->addEllipse(*dot_00,*c_free,*b_free);
    scene->addEllipse(*dot_10,*c_free,*b_free);
    scene->addEllipse(*dot_20,*c_free,*b_free);
    scene->addEllipse(*dot_30,*c_free,*b_free);

    scene->addEllipse(*dot_01,*c_free,*b_free);
    scene->addEllipse(*dot_11,*c_free,*b_free);
    scene->addEllipse(*dot_21,*c_free,*b_free);
    scene->addEllipse(*dot_31,*c_free,*b_free);

    scene->addEllipse(*dot_02,*c_free,*b_free);
    scene->addEllipse(*dot_12,*c_free,*b_free);
    scene->addEllipse(*dot_22,*c_free,*b_free);
    scene->addEllipse(*dot_32,*c_free,*b_free);

    scene->addEllipse(*dot_03,*c_free,*b_free);
    scene->addEllipse(*dot_13,*c_free,*b_free);
    scene->addEllipse(*dot_23,*c_free,*b_free);
    scene->addEllipse(*dot_33,*c_free,*b_free);
}

void map_graphics::act_score()
{
    p1_score = m_game->get_p1_score();
    p2_score = m_game->get_p2_score();
}

QPointF map_graphics::dot_to_qpointf(std::pair<size_t, size_t> &dot_)
{
    QPointF click_;  //Click point to return

    //First row:
    if(std::get<0>(dot_) == 0)
    {
        //First column:
        if(std::get<1>(dot_) == 0)
            return click_ = dot_00->center();
        //Second column:
        if(std::get<1>(dot_) == 1)
            return click_ = dot_01->center();
        //Third column:
        if(std::get<1>(dot_) == 2)
            return click_ = dot_02->center();
        //Quarter column:
        if(std::get<1>(dot_) == 3)
            return click_ = dot_03->center();
    }

    //Second row:
    if(std::get<0>(dot_) == 1)
    {
        //First column:
        if(std::get<1>(dot_) == 0)
            return click_ = dot_10->center();

        //Second column:
        if(std::get<1>(dot_) == 1)
            return click_ = dot_11->center();

        //Third column:
        if(std::get<1>(dot_) == 2)
            return click_ = dot_12->center();

        //Quarter column:
        if(std::get<1>(dot_) == 3)
            return click_ = dot_13->center();
    }

    //Third row:
    if(std::get<0>(dot_) == 2)
    {
        //First column:
        if(std::get<1>(dot_) == 0)
            return click_ = dot_20->center();

        //Second column:
        if(std::get<1>(dot_) == 1)
            return click_ = dot_21->center();

        //Third column:
        if(std::get<1>(dot_) == 2)
            return click_ = dot_22->center();

        //Quarter column:
        if(std::get<1>(dot_) == 3)
            return click_ = dot_23->center();
    }

    //Quarter row:
    if(std::get<0>(dot_) == 3)
    {
        //First column:
        if(std::get<1>(dot_) == 0)
            return click_ = dot_30->center();

        //Second column:
        if(std::get<1>(dot_) == 1)
            return click_ = dot_31->center();

        //Third column:
        if(std::get<1>(dot_) == 2)
            return click_ = dot_32->center();

        //Quarter column:
        if(std::get<1>(dot_) == 3)
            return click_ = dot_33->center();
    }

    return click_ = QPointF(-1,-1);
}

/*void map_graphics::draw_box(int &player)
{
  std::pair<size_t,size_t> a;
  std::pair<size_t,size_t> b;
  std::tuple<std::pair<size_t,size_t>,std::pair<size_t,size_t> > c;

if(m_game->was_point(c = std::make_tuple(a = std::make_pair(std::get<0>(std::get<0>cur_mv),
                                                            std::get<0>(std::get<1>cur_mv)),




                                         b= std::make_pair(std::get<1>(std::get<0>cur_mv),
                                                           std::get<1>(std::get<1>cur_mv)))))
{



}



}*/


//void map_graphics::msleep(unsigned long 500){QThread::msleep(msecs);}

