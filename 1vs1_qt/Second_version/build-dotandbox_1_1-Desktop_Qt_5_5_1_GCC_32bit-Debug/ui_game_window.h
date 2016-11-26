/********************************************************************************
** Form generated from reading UI file 'game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_WINDOW_H
#define UI_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "map_graphics.h"

QT_BEGIN_NAMESPACE

class Ui_game_window
{
public:
    map_graphics *g_map;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *b_reset;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *b_exit;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *l_p1_id;
    QLabel *l_p1_score;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *l_p2_id;
    QLabel *l_p2_score;
    QLabel *l_img;
    QLabel *l_img_2;
    QLabel *l_img_3;

    void setupUi(QDialog *game_window)
    {
        if (game_window->objectName().isEmpty())
            game_window->setObjectName(QStringLiteral("game_window"));
        game_window->resize(774, 494);
        g_map = new map_graphics(game_window);
        g_map->setObjectName(QStringLiteral("g_map"));
        g_map->setGeometry(QRect(140, 20, 451, 361));
        g_map->setLayoutDirection(Qt::LeftToRight);
        g_map->setFrameShape(QFrame::StyledPanel);
        g_map->setLineWidth(0);
        g_map->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        g_map->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        layoutWidget = new QWidget(game_window);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 400, 330, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        b_reset = new QPushButton(layoutWidget);
        b_reset->setObjectName(QStringLiteral("b_reset"));

        horizontalLayout->addWidget(b_reset);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        b_exit = new QPushButton(layoutWidget);
        b_exit->setObjectName(QStringLiteral("b_exit"));

        horizontalLayout->addWidget(b_exit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        layoutWidget1 = new QWidget(game_window);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 130, 91, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        l_p1_id = new QLabel(layoutWidget1);
        l_p1_id->setObjectName(QStringLiteral("l_p1_id"));
        l_p1_id->setFrameShape(QFrame::NoFrame);
        l_p1_id->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(l_p1_id);

        l_p1_score = new QLabel(layoutWidget1);
        l_p1_score->setObjectName(QStringLiteral("l_p1_score"));
        l_p1_score->setFrameShape(QFrame::Box);
        l_p1_score->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(l_p1_score);

        layoutWidget2 = new QWidget(game_window);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(630, 120, 101, 61));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        l_p2_id = new QLabel(layoutWidget2);
        l_p2_id->setObjectName(QStringLiteral("l_p2_id"));
        l_p2_id->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(l_p2_id);

        l_p2_score = new QLabel(layoutWidget2);
        l_p2_score->setObjectName(QStringLiteral("l_p2_score"));
        l_p2_score->setFrameShape(QFrame::Box);
        l_p2_score->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(l_p2_score);

        l_img = new QLabel(game_window);
        l_img->setObjectName(QStringLiteral("l_img"));
        l_img->setGeometry(QRect(20, 30, 111, 81));
        l_img->setPixmap(QPixmap(QString::fromUtf8("ehm.jpg")));
        l_img->setScaledContents(true);
        l_img_2 = new QLabel(game_window);
        l_img_2->setObjectName(QStringLiteral("l_img_2"));
        l_img_2->setGeometry(QRect(630, 30, 111, 81));
        l_img_2->setPixmap(QPixmap(QString::fromUtf8("ehm.jpg")));
        l_img_2->setScaledContents(true);
        l_img_3 = new QLabel(game_window);
        l_img_3->setObjectName(QStringLiteral("l_img_3"));
        l_img_3->setGeometry(QRect(20, 280, 111, 81));
        l_img_3->setPixmap(QPixmap(QString::fromUtf8("ehm.jpg")));
        l_img_3->setScaledContents(true);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        g_map->raise();
        l_img->raise();
        l_img_2->raise();
        l_img_3->raise();
        l_p1_score->raise();

        retranslateUi(game_window);

        QMetaObject::connectSlotsByName(game_window);
    } // setupUi

    void retranslateUi(QDialog *game_window)
    {
        game_window->setWindowTitle(QApplication::translate("game_window", "Dialog", 0));
#ifndef QT_NO_ACCESSIBILITY
        g_map->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        b_reset->setText(QApplication::translate("game_window", "Reset", 0));
        b_exit->setText(QApplication::translate("game_window", "Exit", 0));
        l_p1_id->setText(QApplication::translate("game_window", "TextLabel", 0));
        l_p1_score->setText(QApplication::translate("game_window", "0", 0));
        l_p2_id->setText(QApplication::translate("game_window", "TextLabel", 0));
        l_p2_score->setText(QApplication::translate("game_window", "0", 0));
        l_img->setText(QString());
        l_img_2->setText(QString());
        l_img_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class game_window: public Ui_game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_WINDOW_H
