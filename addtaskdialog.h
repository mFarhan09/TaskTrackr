#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include "task.h"
#include <QDialog>

namespace Ui {
class AddTaskDialog;
}

class AddTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskDialog(QWidget *parent = nullptr);
    ~AddTaskDialog();

signals:
    void taskAdded(Task & task);

private slots:
    void on_SaveButton_clicked();

private:
    Ui::AddTaskDialog *ui;
};

#endif // ADDTASKDIALOG_H
