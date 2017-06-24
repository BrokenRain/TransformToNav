/********************************************************************************
** Form generated from reading UI file 'TransformToNav.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFORMTONAV_H
#define UI_TRANSFORMTONAV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransformToNavClass
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_save;
    QPushButton *pushButton_save;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_filename;
    QPushButton *pushButton_selcet;
    QPushButton *pushButton_Transform;

    void setupUi(QWidget *TransformToNavClass)
    {
        if (TransformToNavClass->objectName().isEmpty())
            TransformToNavClass->setObjectName(QStringLiteral("TransformToNavClass"));
        TransformToNavClass->setWindowModality(Qt::ApplicationModal);
        TransformToNavClass->resize(342, 148);
        TransformToNavClass->setMinimumSize(QSize(342, 148));
        TransformToNavClass->setMaximumSize(QSize(342, 148));
        gridLayoutWidget = new QWidget(TransformToNavClass);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 321, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_save = new QLineEdit(gridLayoutWidget);
        lineEdit_save->setObjectName(QStringLiteral("lineEdit_save"));
        lineEdit_save->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_save);

        pushButton_save = new QPushButton(gridLayoutWidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(pushButton_save);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_filename = new QLineEdit(gridLayoutWidget);
        lineEdit_filename->setObjectName(QStringLiteral("lineEdit_filename"));
        lineEdit_filename->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_filename);

        pushButton_selcet = new QPushButton(gridLayoutWidget);
        pushButton_selcet->setObjectName(QStringLiteral("pushButton_selcet"));
        pushButton_selcet->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(pushButton_selcet);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pushButton_Transform = new QPushButton(TransformToNavClass);
        pushButton_Transform->setObjectName(QStringLiteral("pushButton_Transform"));
        pushButton_Transform->setGeometry(QRect(260, 110, 75, 23));
        pushButton_Transform->setLayoutDirection(Qt::LeftToRight);

        retranslateUi(TransformToNavClass);

        pushButton_selcet->setDefault(true);


        QMetaObject::connectSlotsByName(TransformToNavClass);
    } // setupUi

    void retranslateUi(QWidget *TransformToNavClass)
    {
        TransformToNavClass->setWindowTitle(QApplication::translate("TransformToNavClass", "Nav\346\240\274\345\274\217\350\275\254\346\215\242", 0));
        pushButton_save->setText(QApplication::translate("TransformToNavClass", "\344\277\235\345\255\230\344\275\215\347\275\256", 0));
        pushButton_selcet->setText(QApplication::translate("TransformToNavClass", "\350\275\254\346\215\242\346\226\207\344\273\266", 0));
        pushButton_Transform->setText(QApplication::translate("TransformToNavClass", "\350\275\254\346\215\242", 0));
    } // retranslateUi

};

namespace Ui {
    class TransformToNavClass: public Ui_TransformToNavClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFORMTONAV_H
