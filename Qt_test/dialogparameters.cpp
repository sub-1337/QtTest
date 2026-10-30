#include "dialogparameters.h"
#include "ui_dialogparameters.h"
#include <QDebug>
#include <QIntValidator>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QFontMetrics>
#include <QAbstractItemView>
#include <QDoubleValidator>

DialogParameters::DialogParameters(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogParameters)
{
    ui->setupUi(this);

    // Задать фиксированныые размеры окна
    setFixedSize(700, 320);

    // Заполняем способ рассчёта
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

    // Заполняем комбо бокс правый - стиль
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_1.png"), "Металл");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_2.png"), "Естественный грунт");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_3.png"), "Насыпной грунт");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_4.png"), "Камень искусственный");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_5.png"), "Железобетон");
    ui->comboBox_style->addItem(QIcon(":/icons/hatch_6.png"), "Напряжённый железобетон");

    setAutoSizeForComboBox(ui->comboBox_style, 60);

    // Фикс размера иконки в стиле
    ui->comboBox_style->setIconSize(QSize(60,25 / 2));

    // Переименовать кнопки в диалоге
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Применить");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Отменить");

    // Ввод только цифр
    // допустимы дроби через запятую
    ui->lineEdit_mass->setValidator(
        new QDoubleValidator(
            0.0,       // Minimum value
            10000.0,     // Maximum value
            2,         // Decimal places
            ui->lineEdit_mass
            ));

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
        new QDoubleValidator(
            0.0,       // Minimum value
            10000.0,     // Maximum value
            2,         // Decimal places
            ui->lineEdit_density
            )
    );

    ui->lineEdit_density2->setValidator(
        new QDoubleValidator(
            0.0,       // Minimum value
            10000.0,     // Maximum value
            2,         // Decimal places
            ui->lineEdit_density2
            )
    );
    ui->lineEdit_mass_2->setValidator(
        new QDoubleValidator(
            0.0,       // Minimum value
            10000.0,     // Maximum value
            2,         // Decimal places
            ui->lineEdit_mass_2
            )
    );

    ui->lineEdit_angle->setValidator(
        new QDoubleValidator(
            0.0,       // Minimum value
            10000.0,     // Maximum value
            2,         // Decimal places
            ui->lineEdit_angle
            )
    );
    // Привязать изменение типа диалогового окна
    connect(ui->comboBoxMethod, &QComboBox::currentIndexChanged, this, &DialogParameters::onComboboxTypeChanged);

    // Выбрать определённый элемент и обновить
    ui->comboBoxMethod->setCurrentIndex(0);
    onComboboxTypeChanged(0);

    // Привязать галочку центра масс
    connect(ui->checkBox_massCenter, &QCheckBox::toggled, this, &DialogParameters::onMassCenter);
    // Привязать сохранение данных
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DialogParameters::onSave);
}

// При активации комбо бокса "способ рассчёта"
void DialogParameters::onComboboxTypeChanged(int index)
{
    ui->widget_mass->setVisible(false);
    ui->widget_density->setVisible(false);
    ui->widget_source->setVisible(false);

    ui->lineEdit_material->setEnabled(true);
    ui->comboBox_style->setEnabled(true);
    ui->lineEdit_angle->setEnabled(true);

    if (index == 0) // по плотности
    {
        // Выставляем видимыми контроллы плотности
        ui->widget_density->setVisible(true);
        // Сдвигаем вверх
        ui->widget_density->move(
            ui->widget_method->x(),
            ui->widget_method->y() + ui->widget_method->height()
            );
    }
    else if (index == 1) // по массе
    {
        // Выставляем видимыми контроллы массы
        ui->widget_mass->setVisible(true);
        // Сдвигаем вверх
        ui->widget_mass->move(
            ui->widget_method->x(),
            ui->widget_method->y() + ui->widget_method->height()
            );
    }
    else if (index == 2) // по данным
    {
        // Выставляем видимыми контроллы данных
        ui->widget_source->setVisible(true);
        // Сдвигаем вверх
        ui->widget_source->move(
            ui->widget_method->x(),
            ui->widget_method->y() + ui->widget_method->height()
            );

        // Отключаем редактирование всего
        ui->lineEdit_density2->setEnabled(false);
        ui->lineEdit_mass_2->setEnabled(false);

        ui->lineEdit_material->setEnabled(false);
        ui->comboBox_style->setEnabled(false);
        ui->lineEdit_angle->setEnabled(false);

        // Зачитываем в контроллы сохранённые параметры из главного окна
        if (!data.m_density.isEmpty())
        {
            ui->lineEdit_density2->setText(data.m_density);
        }
        else
        {
            ui->lineEdit_density2->setText("0");
        }

        if (!data.m_mass.isEmpty())
        {
            ui->lineEdit_mass_2->setText(data.m_mass);
        }
        else
        {
            ui->lineEdit_mass_2->setText("0");
        }

        if (!data.m_material.isEmpty())
        {
            ui->lineEdit_material->setText(data.m_material);
        }
        else
        {
            ui->lineEdit_material->setText("");
        }

        if (!data.m_style.isEmpty())
        {
            ui->comboBox_style->setCurrentText(data.m_style);
        }
        else
        {
            ui->comboBox_style->setCurrentIndex(0);
        }

        if (!data.m_angle.isEmpty())
        {
            ui->lineEdit_angle->setText(data.m_angle);
        }
        else
        {
            ui->lineEdit_angle->setText("0");
        }

    }
}

// При активации галочки "центр масс"
void DialogParameters::onMassCenter(bool checked)
{
    if (checked)
    {
        // Показываем контроллы если галочка стоит
        ui->lineEdit_X->show();
        ui->lineEdit_Y->show();
        ui->lineEdit_Z->show();

        ui->label_X->show();
        ui->label_Y->show();
        ui->label_Z->show();
    }
    else
    {
        // Скрываем контроллы если галочки нет
        ui->lineEdit_X->hide();
        ui->lineEdit_Y->hide();
        ui->lineEdit_Z->hide();

        ui->label_X->hide();
        ui->label_Y->hide();
        ui->label_Z->hide();
    }
}

// При нажатии кнопки сохранить
void DialogParameters::onSave()
{

    int variantOfDialog = ui->comboBoxMethod->currentIndex();

    if (variantOfDialog == 0) // плотность
    {
        data.m_method = "плотность";
        data.m_mass = "0";
        // Если не пустое поле
        if (ui->lineEdit_density->hasAcceptableInput())
        {
            data.m_density = ui->lineEdit_density->text();
        }
        else
        {
            data.m_density = "0";
        }

        data.m_massCenter = "0.0.0";
        data.m_material = ui->lineEdit_material->text();
        data.m_style = ui->comboBox_style->currentText();

        // Если не пустое поле
        if (ui->lineEdit_angle->hasAcceptableInput())
        {
            data.m_angle = ui->lineEdit_angle->text();
        }
        else
        {
            data.m_angle = "0";
        }

    }
    else if (variantOfDialog == 1) // масса
    {
        data.m_method = "масса";

        // Если не пустое поле
        if (ui->lineEdit_mass->hasAcceptableInput())
        {
            data.m_mass = ui->lineEdit_mass->text();
        }
        else
        {
            data.m_mass = "0";
        }

        data.m_density = "0";

        //  Если галочка центра масс активна
        if (ui->checkBox_massCenter->isChecked())
        {
            // Если не пустые поля
            if (ui->lineEdit_X->hasAcceptableInput()
                && ui->lineEdit_Y->hasAcceptableInput()
                && ui->lineEdit_Z->hasAcceptableInput())
            {
                data.m_massCenter =   ui->lineEdit_X->text() + "."
                               + ui->lineEdit_Y->text() + "."
                               + ui->lineEdit_Z->text();
            }
            else
            {
                data.m_massCenter = "0.0.0";
            }

        }
        else
        {
            data.m_massCenter = "0.0.0";
        }

        data.m_material = ui->lineEdit_material->text();;
        data.m_style = ui->comboBox_style->currentText();

        if (ui->lineEdit_angle->hasAcceptableInput())
        {
            data.m_angle = ui->lineEdit_angle->text();
        }
        else
        {
            data.m_angle = "0";
        }

    }
    else if (variantOfDialog == 2) // данные
    {
        data.m_method = "по данным";
        data.m_mass = ui->lineEdit_mass_2->text();
        data.m_density = ui->lineEdit_density2->text();
        data.m_massCenter = "0.0.0";
        data.m_material = ui->lineEdit_material->text();;
        data.m_style = ui->comboBox_style->currentText();
        data.m_angle = ui->lineEdit_angle->text();
    }
}

DialogParameters::~DialogParameters()
{
    delete ui;
}
