#include "importwindow.h"
#include "ui_importwindow.h"
#include "QString"
ImportWindow::ImportWindow(QList<QString> sucFiles,QList<QString> unSucFiles,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
    ui->sucLabel->setText(QString::number(sucFiles.count()));
    ui->unSucLabel->setText(QString::number(unSucFiles.count()));
    for(int i=0;i<sucFiles.count();i++)
    {
            ui->sucListLabel->setText(ui->sucListLabel->text()+sucFiles.at(i)+"\n");
    }
    QPalette p;
    p.setColor(QPalette::WindowText, Qt::red);
    ui->unSucLabel->setPalette(p);
    ui->label_3->setPalette(p);
    ui->unSucListLabel->setPalette(p);
    for(int i=0;i<unSucFiles.count();i++)
    {
            ui->unSucListLabel->setText(ui->unSucListLabel->text()+unSucFiles.at(i)+"\n");
    }

}

ImportWindow::~ImportWindow()
{
    delete ui;
}

void ImportWindow::on_pushButton_clicked()
{
    this->close();
}
