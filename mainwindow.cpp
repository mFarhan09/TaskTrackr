#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskdelegate.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    taskmodel = new TaskModel(this);
    ui->TaskListView->setModel(taskmodel);

    TaskDelegate* delegate = new TaskDelegate(this);
     ui->TaskListView->setItemDelegate(delegate);

   ui->searchBar->setPlaceholderText("Search");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddTaskPushButton_clicked()
{

    dialog = new AddTaskDialog(this);
    connect(dialog,&AddTaskDialog::taskAdded,taskmodel,&TaskModel::addTask);

    dialog->exec(); // open the dialog
}

