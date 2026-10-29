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
    m_model->setHorizontalHeaderLabels({ "способ рассчёта", "масса", "плотность", "центр масс", "материал", "стиль штриховки", "угол штриховки" });

    ui->tableView->setModel(m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
        );

    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::OnAdd);
    connect(ui->pushButtonDelete, &QPushButton::clicked, this, &MainWindow::onDelete);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void MainWindow::OnAdd()
{
    DialogParameters dlg;
    auto res = dlg.exec();
    if (res == QDialog::Accepted)
    {
        m_model->appendRow({
            new QStandardItem(dlg.m_method),
            new QStandardItem(dlg.m_mass),
            new QStandardItem(dlg.m_density),
            new QStandardItem(dlg.m_massCenter),
            new QStandardItem(dlg.m_material),
            new QStandardItem(dlg.m_style),
            new QStandardItem(dlg.m_angle),
        });
    }

}
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
