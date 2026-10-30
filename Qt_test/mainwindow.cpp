#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogparameters.h"
#include <QItemSelectionModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_model = new QStandardItemModel(this);
    // Заполнение заголовков
    m_model->setHorizontalHeaderLabels({ "способ рассчёта", "масса", "плотность", "центр масс", "материал", "стиль штриховки", "угол штриховки" });

    ui->tableView->setModel(m_model);
    // Запретить редактирование
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
        );

    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::OnAdd);
    connect(ui->pushButtonDelete, &QPushButton::clicked, this, &MainWindow::onDelete);

    // Корректное выделение по одному
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

// Добавление
void MainWindow::OnAdd()
{
    DialogParameters dlg;
    auto res = dlg.exec();
    if (res == QDialog::Accepted)
    {
        auto& data = dlg.data;
        m_model->appendRow({
            new QStandardItem(data.m_method),
            new QStandardItem(data.m_mass),
            new QStandardItem(data.m_density),
            new QStandardItem(data.m_massCenter),
            new QStandardItem(data.m_material),
            new QStandardItem(data.m_style),
            new QStandardItem(data.m_angle),
        });
    }

}

// Удаление
void MainWindow::onDelete()
{
    const auto rows = ui->tableView->selectionModel()->selectedRows();

    if (rows.isEmpty())
        return; // Ничего не выделено

    m_model->removeRow(rows.first().row());
}

MainWindow::~MainWindow()
{
    delete ui;
}
