#include "importform.h"
#include "ui_importform.h"

importForm::importForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::importForm)
{
    ui->setupUi(this);
}

importForm::~importForm()
{
    delete ui;
}
