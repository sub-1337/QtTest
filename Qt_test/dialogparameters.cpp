#include "dialogparameters.h"
#include "ui_dialogparameters.h"
#include <QDebug>
#include <QIntValidator>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QFontMetrics>
#include <QAbstractItemView>

DialogParameters::DialogParameters(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogParameters)
{
    ui->setupUi(this);

    setFixedSize(700, 320);

    ui->comboBoxMethod->addItem(QIcon(":/icons/calc_2.png"), "По плотности");
    ui->comboBoxMethod->addItem(QIcon(":/icons/calc_1.png"), "По массе");
    ui->comboBoxMethod->addItem(QIcon(":/icons/calc_3.png"), "По данным источника копирования");

    //  Функция чтобы сделать выпадающий список шире но оставить его компактным без клика
    auto setAutoSizeForComboBox = [] (auto& comboBox, int additionalSpace = 0)
    {
        int maxWidth = 0;
        QFontMetrics fm(comboBox->font());

        for (int i = 0; i < comboBox->count(); ++i) {
            maxWidth = std::max(maxWidth,
                                fm.horizontalAdvance(comboBox->itemText(i)));
        }

        // Запас под отступы и скроллбар
        comboBox->view()->setMinimumWidth(maxWidth + 40 + additionalSpace);
    };

    setAutoSizeForComboBox(ui->comboBoxMethod);

    ui->comboBox_style->addItem(QIcon(":/icons/hatch_1.png"), "Металл");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_2.png"), "Естественный грунт");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_3.png"), "Насыпной грунт");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_4.png"), "Камень искусственный");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_5.png"), "Железобетон");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_6.png"), "Напряжённый железобетон");

    setAutoSizeForComboBox(ui->comboBox_style, 60);

    ui->comboBox_style->setIconSize(QSize(60,25 / 2));

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Применить");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Отменить");

    // Ввод только цифр
    ui->lineEdit_mass->setValidator(
        new QIntValidator(0, 999999, this)
    );
    ui->lineEdit_X->setValidator(
        new QIntValidator(0, 999999, this)
    );
    ui->lineEdit_Y->setValidator(
        new QIntValidator(0, 999999, this)
    );
    ui->lineEdit_Z->setValidator(
        new QIntValidator(0, 999999, this)
    );

    ui->lineEdit_density->setValidator(
        new QIntValidator(0, 999999, this)
    );

    ui->lineEdit_density2->setValidator(
        new QIntValidator(0, 999999, this)
    );
    ui->lineEdit_mass_2->setValidator(
        new QIntValidator(0, 999999, this)
    );

    ui->lineEdit_angle->setValidator(
        new QIntValidator(0, 999999, this)
    );

    connect(ui->comboBoxMethod, &QComboBox::currentIndexChanged, this, &DialogParameters::onComboboxTypeChanged);

    // Выбрать определённый элемент и обновить
    ui->comboBoxMethod->setCurrentIndex(0);
    onComboboxTypeChanged(0);

    connect(ui->checkBox_massCenter, &QCheckBox::toggled, this, &DialogParameters::onMassCenter);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DialogParameters::onSave);
}

void DialogParameters::onComboboxTypeChanged(int index)
{
    qDebug() << "index" << index;

    ui->widget_mass->setVisible(false);
    ui->widget_density->setVisible(false);
    ui->widget_source->setVisible(false);

    if (index == 0) // по плотности
    {
        ui->widget_density->setVisible(true);
        // Сдвигаем вверх
        ui->widget_density->move(
            ui->widget_method->x(),
            ui->widget_method->y() + ui->widget_method->height()
            );
    }
    else if (index == 1) // по массе
    {
        ui->widget_mass->setVisible(true);
        // Сдвигаем вверх
        ui->widget_mass->move(
            ui->widget_method->x(),
            ui->widget_method->y() + ui->widget_method->height()
            );
    }
    else if (index == 2) // по данным
    {
        ui->widget_source->setVisible(true);
        // Сдвигаем вверх
        ui->widget_source->move(
            ui->widget_method->x(),
            ui->widget_method->y() + ui->widget_method->height()
            );

        ui->lineEdit_density2->setEnabled(false);
        ui->lineEdit_mass_2->setEnabled(false);
    }
}

void DialogParameters::onMassCenter(bool checked)
{
    if (checked)
    {
        ui->lineEdit_X->show();
        ui->lineEdit_Y->show();
        ui->lineEdit_Z->show();

        ui->label_X->show();
        ui->label_Y->show();
        ui->label_Z->show();
    }
    else
    {
        ui->lineEdit_X->hide();
        ui->lineEdit_Y->hide();
        ui->lineEdit_Z->hide();

        ui->label_X->hide();
        ui->label_Y->hide();
        ui->label_Z->hide();
    }
}

void DialogParameters::onSave()
{

    int variantOfDialog = ui->comboBoxMethod->currentIndex();

    if (variantOfDialog == 0) // плотность
    {
        m_method = "плотность";
        m_mass = "0";
        m_density = ui->lineEdit_density->text();
        m_massCenter = "0.0.0";
        m_material = ui->lineEdit_material->text();
        m_style = ui->comboBox_style->currentText();
        m_angle = ui->lineEdit_angle->text();
    }
    else if (variantOfDialog == 1) // масса
    {
        m_method = "масса";
        m_mass = ui->lineEdit_mass->text();
        m_density = "0";

        if (ui->checkBox_massCenter->isChecked())
        {
            m_massCenter =   ui->lineEdit_X->text() + "."
                           + ui->lineEdit_Y->text() + "."
                           + ui->lineEdit_Z->text();
        }
        else
        {
            m_massCenter = "0.0.0";
        }

        m_material = ui->lineEdit_material->text();;
        m_style = ui->comboBox_style->currentText();
        m_angle = ui->lineEdit_angle->text();
    }
    else if (variantOfDialog == 2) // данные
    {
        m_method = "по данным";
        m_mass = ui->lineEdit_mass_2->text();
        m_density = ui->lineEdit_density2->text();
        m_massCenter = "0.0.0";
        m_material = ui->lineEdit_material->text();;
        m_style = ui->comboBox_style->currentText();
        m_angle = ui->lineEdit_angle->text();
    }
}

DialogParameters::~DialogParameters()
{
    delete ui;
}
