#ifndef DIALOGPARAMETERS_H
#define DIALOGPARAMETERS_H

#include <QDialog>

namespace Ui {
class DialogParameters;
}

struct RecordData
{
    QString m_method;
    QString m_mass;
    QString m_density;
    QString m_massCenter;
    QString m_material;
    QString m_style;
    QString m_angle;
};

class DialogParameters : public QDialog
{
    Q_OBJECT

public:
    explicit DialogParameters(QWidget *parent = nullptr);
    ~DialogParameters();

    RecordData data{};

private:
    Ui::DialogParameters *ui;
    void onComboboxTypeChanged(int index); // При активации комбо бокса "способ рассчёта"
    void onMassCenter(bool checked); // При активации галочки "центр масс"
    void onSave(); // При нажатии кнопки сохранить
};

#endif // DIALOGPARAMETERS_H
