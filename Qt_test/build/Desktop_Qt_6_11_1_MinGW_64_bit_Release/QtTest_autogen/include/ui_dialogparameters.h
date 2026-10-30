/********************************************************************************
** Form generated from reading UI file 'dialogparameters.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPARAMETERS_H
#define UI_DIALOGPARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogParameters
{
public:
    QWidget *widget;
    QWidget *widget_mass;
    QLabel *label_mass;
    QLineEdit *lineEdit_mass;
    QCheckBox *checkBox_massCenter;
    QLabel *label_X;
    QLineEdit *lineEdit_X;
    QLineEdit *lineEdit_Y;
    QLabel *label_Y;
    QLineEdit *lineEdit_Z;
    QLabel *label_Z;
    QWidget *widget_2;
    QWidget *widget_density;
    QLabel *label_density;
    QLineEdit *lineEdit_density;
    QWidget *widget_source;
    QLineEdit *lineEdit_density2;
    QLabel *label_density2;
    QLabel *label_mass2;
    QLineEdit *lineEdit_mass_2;
    QWidget *widget_method;
    QLabel *label;
    QComboBox *comboBoxMethod;
    QWidget *widget_material;
    QLabel *label_2;
    QLineEdit *lineEdit_material;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_style;
    QLabel *label_angle;
    QLineEdit *lineEdit_angle;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogParameters)
    {
        if (DialogParameters->objectName().isEmpty())
            DialogParameters->setObjectName("DialogParameters");
        DialogParameters->resize(748, 414);
        widget = new QWidget(DialogParameters);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 30, 711, 371));
        widget_mass = new QWidget(widget);
        widget_mass->setObjectName("widget_mass");
        widget_mass->setGeometry(QRect(0, 50, 351, 191));
        label_mass = new QLabel(widget_mass);
        label_mass->setObjectName("label_mass");
        label_mass->setGeometry(QRect(70, 10, 61, 20));
        label_mass->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_mass = new QLineEdit(widget_mass);
        lineEdit_mass->setObjectName("lineEdit_mass");
        lineEdit_mass->setGeometry(QRect(140, 10, 171, 26));
        checkBox_massCenter = new QCheckBox(widget_mass);
        checkBox_massCenter->setObjectName("checkBox_massCenter");
        checkBox_massCenter->setGeometry(QRect(140, 40, 121, 24));
        checkBox_massCenter->setChecked(true);
        label_X = new QLabel(widget_mass);
        label_X->setObjectName("label_X");
        label_X->setGeometry(QRect(110, 70, 21, 31));
        label_X->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_X = new QLineEdit(widget_mass);
        lineEdit_X->setObjectName("lineEdit_X");
        lineEdit_X->setGeometry(QRect(140, 70, 171, 31));
        lineEdit_Y = new QLineEdit(widget_mass);
        lineEdit_Y->setObjectName("lineEdit_Y");
        lineEdit_Y->setGeometry(QRect(140, 110, 171, 31));
        label_Y = new QLabel(widget_mass);
        label_Y->setObjectName("label_Y");
        label_Y->setGeometry(QRect(110, 110, 21, 31));
        label_Y->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_Z = new QLineEdit(widget_mass);
        lineEdit_Z->setObjectName("lineEdit_Z");
        lineEdit_Z->setGeometry(QRect(140, 150, 171, 31));
        label_Z = new QLabel(widget_mass);
        label_Z->setObjectName("label_Z");
        label_Z->setGeometry(QRect(110, 150, 21, 31));
        label_Z->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        widget_2 = new QWidget(widget_mass);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(80, 220, 120, 80));
        widget_density = new QWidget(widget);
        widget_density->setObjectName("widget_density");
        widget_density->setGeometry(QRect(-1, 239, 351, 51));
        label_density = new QLabel(widget_density);
        label_density->setObjectName("label_density");
        label_density->setGeometry(QRect(10, 10, 121, 31));
        label_density->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_density = new QLineEdit(widget_density);
        lineEdit_density->setObjectName("lineEdit_density");
        lineEdit_density->setGeometry(QRect(140, 10, 171, 31));
        widget_source = new QWidget(widget);
        widget_source->setObjectName("widget_source");
        widget_source->setGeometry(QRect(-10, 300, 361, 71));
        lineEdit_density2 = new QLineEdit(widget_source);
        lineEdit_density2->setObjectName("lineEdit_density2");
        lineEdit_density2->setGeometry(QRect(150, 0, 171, 31));
        label_density2 = new QLabel(widget_source);
        label_density2->setObjectName("label_density2");
        label_density2->setGeometry(QRect(10, 0, 131, 31));
        label_density2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_mass2 = new QLabel(widget_source);
        label_mass2->setObjectName("label_mass2");
        label_mass2->setGeometry(QRect(80, 40, 61, 20));
        label_mass2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_mass_2 = new QLineEdit(widget_source);
        lineEdit_mass_2->setObjectName("lineEdit_mass_2");
        lineEdit_mass_2->setGeometry(QRect(150, 40, 171, 26));
        widget_method = new QWidget(widget);
        widget_method->setObjectName("widget_method");
        widget_method->setGeometry(QRect(0, 0, 311, 51));
        label = new QLabel(widget_method);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 131, 41));
        comboBoxMethod = new QComboBox(widget_method);
        comboBoxMethod->setObjectName("comboBoxMethod");
        comboBoxMethod->setGeometry(QRect(140, 10, 171, 26));
        widget_material = new QWidget(widget);
        widget_material->setObjectName("widget_material");
        widget_material->setGeometry(QRect(350, 0, 321, 371));
        label_2 = new QLabel(widget_material);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 81, 20));
        lineEdit_material = new QLineEdit(widget_material);
        lineEdit_material->setObjectName("lineEdit_material");
        lineEdit_material->setGeometry(QRect(100, 10, 161, 26));
        label_3 = new QLabel(widget_material);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 50, 81, 20));
        label_4 = new QLabel(widget_material);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 70, 63, 20));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        comboBox_style = new QComboBox(widget_material);
        comboBox_style->setObjectName("comboBox_style");
        comboBox_style->setGeometry(QRect(100, 70, 161, 26));
        label_angle = new QLabel(widget_material);
        label_angle->setObjectName("label_angle");
        label_angle->setGeometry(QRect(10, 110, 63, 20));
        label_angle->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEdit_angle = new QLineEdit(widget_material);
        lineEdit_angle->setObjectName("lineEdit_angle");
        lineEdit_angle->setGeometry(QRect(100, 110, 161, 26));
        buttonBox = new QDialogButtonBox(widget_material);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(DialogParameters);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogParameters, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogParameters, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogParameters);
    } // setupUi

    void retranslateUi(QDialog *DialogParameters)
    {
        DialogParameters->setWindowTitle(QCoreApplication::translate("DialogParameters", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\234\320\246\320\245", nullptr));
        label_mass->setText(QCoreApplication::translate("DialogParameters", "\320\234\320\260\321\201\321\201\320\260, \320\263", nullptr));
        lineEdit_mass->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        checkBox_massCenter->setText(QCoreApplication::translate("DialogParameters", "\320\246\320\265\320\275\321\202\321\200 \320\274\320\260\321\201\321\201", nullptr));
        label_X->setText(QCoreApplication::translate("DialogParameters", "X:", nullptr));
        lineEdit_X->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        lineEdit_Y->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        label_Y->setText(QCoreApplication::translate("DialogParameters", "Y:", nullptr));
        lineEdit_Z->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        label_Z->setText(QCoreApplication::translate("DialogParameters", "Z:", nullptr));
        label_density->setText(QCoreApplication::translate("DialogParameters", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214, \320\263/\320\274\320\2743", nullptr));
        lineEdit_density->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        lineEdit_density2->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        label_density2->setText(QCoreApplication::translate("DialogParameters", "\320\237\320\273\320\276\321\202\320\275\320\276\321\201\321\202\321\214, \320\263/\320\274\320\2743", nullptr));
        label_mass2->setText(QCoreApplication::translate("DialogParameters", "\320\234\320\260\321\201\321\201\320\260, \320\263", nullptr));
        lineEdit_mass_2->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
        label->setText(QCoreApplication::translate("DialogParameters", "\320\241\320\277\320\276\321\201\320\276\320\261 \321\200\320\260\321\201\321\201\321\207\321\221\321\202\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogParameters", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273:", nullptr));
        lineEdit_material->setText(QString());
        label_3->setText(QCoreApplication::translate("DialogParameters", "\320\250\321\202\321\200\320\270\321\205\320\276\320\262\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("DialogParameters", "\320\241\321\202\320\270\320\273\321\214:", nullptr));
        label_angle->setText(QCoreApplication::translate("DialogParameters", "\320\243\320\263\320\276\320\273:", nullptr));
        lineEdit_angle->setText(QCoreApplication::translate("DialogParameters", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogParameters: public Ui_DialogParameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPARAMETERS_H
