#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"

AddTaskDialog::AddTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTaskDialog)
{
    ui->setupUi(this);
}

//destructor.
AddTaskDialog::~AddTaskDialog()
{
    delete ui;
}


//slot for save button click.
void AddTaskDialog::on_SaveButton_clicked()
{
  Task task(ui->titleLineEdit->text(),ui->CategoryCombo->currentText(), ui->DescriptionEdit->toPlainText(),
            ui->DeadlineEdit->dateTime(),ui->PriorityCombo->currentText(),ui->StatusCombo->currentText());

  emit taskAdded(task); //emits signal

   accept(); //close the dialog after saving.
}

