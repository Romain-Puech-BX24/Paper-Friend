#include "all_habits.h"
#include "ui_all_habits.h"

All_Habits::All_Habits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::All_Habits)
{
    ui->setupUi(this);
}

All_Habits::~All_Habits()
{
    delete ui;
}
