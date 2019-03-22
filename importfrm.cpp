#include "importfrm.h"
#include "ui_importfrm.h"

importFrm::importFrm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importFrm)
{
    ui->setupUi(this);
}

importFrm::~importFrm()
{
    delete ui;
}
