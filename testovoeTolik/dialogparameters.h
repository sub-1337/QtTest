#ifndef DIALOGPARAMETERS_H
#define DIALOGPARAMETERS_H

#include <QDialog>

namespace Ui {
class DialogParameters;
}

class DialogParameters : public QDialog
{
    Q_OBJECT

public:
    explicit DialogParameters(QWidget *parent = nullptr);
    ~DialogParameters();

    QString m_method;
    QString m_mass;
    QString m_density;
    QString m_massCenter;
    QString m_material;
    QString m_style;
    QString m_angle;

private:
    Ui::DialogParameters *ui;
    void onComboboxTypeChanged(int index);
    void onMassCenter(bool checked);

    void onSave();
};

#endif // DIALOGPARAMETERS_H
