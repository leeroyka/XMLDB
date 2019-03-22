#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QTextCodec"
#include "importwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::ReadXMLFiles(QString file,QList<QString> &headerNames, int &count )
{
    QXmlStreamReader xmlReader;
    xmlReader.addData(file);
    bool isFirstEl=false;
    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            if(!isFirstEl)
            {
                isFirstEl = 1;
            }
            else {
                headerNames<<xmlReader.name().toString();
                count++;
            }
        }
        xmlReader.readNext();
    }
}
bool MainWindow::CheckFiles(QString file)
{
    QXmlStreamReader xmlReader;
    xmlReader.addData(file);
    bool isFirstEl=false;
    QStringList names;
    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {

            if(!isFirstEl)
            {
                isFirstEl = 1;
            }
            else {

            }
            names.push_back(xmlReader.name().toString());
        }
        if(xmlReader.isEndElement())
        {
            if(names.indexOf(xmlReader.name().toString())==-1)
            {
                return false;
            }
            names.removeAt(names.indexOf(xmlReader.name().toString()));
        }
        xmlReader.readNext();
    }
    if(names.isEmpty())
        return true;
    else {
        return false;
    }
}
void MainWindow::ReadXML(QString file)
{
    QXmlStreamReader xmlReader;
    xmlReader.addData(file);
    QList<QString> values;
    bool isFirstEl=false;
    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            if(!isFirstEl)
            {
                isFirstEl = 1;
            }
            else {
                values<<xmlReader.readElementText();
            }
        }
        xmlReader.readNext();
    }
    model->setDat(values);
    //ui->tableView->setModel(model);
}
void MainWindow::on_importButton_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/",tr("File (*.xml)"));
    if(fileNames.isEmpty())
        return;
    QList<QString> headerNames;
    QList<QString> sucFiles;
    QList<QString> unSucFiles;
    int countColumns=0;
    if( !fileNames.isEmpty())
    {

        for (int i = 0;i<fileNames.count();i++)
        {
            QFile file(fileNames.at(i));
            if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
            {
                QString FileString = QTextCodec::codecForMib(106)->toUnicode(file.readAll());
                if(CheckFiles(FileString))
                {
                    sucFiles<<fileNames.at(i);
                    qDebug("+");
                }
                else {
                    unSucFiles<<fileNames.at(i);
                    fileNames.removeAt(i);
                    file.close();
                    qDebug("-");
                    i--;
                    continue;
                }
            }

        }

    }
    ImportWindow impWindow(sucFiles,unSucFiles);
    impWindow.exec();
    //QMessageBox::information(this,"Импорт XML-Файлов","Успешно импортировано: "+QString::number(sucFiles.count())+"\n"+"Файлы с ошибками: "+QString::number(unSucFiles.count())+"\n");

    if( !fileNames.isEmpty())
    {

        for (int i = 0;i<fileNames.count();i++)
        {
            QFile file(fileNames.at(i));
            if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
            {
                QString FileString = QTextCodec::codecForMib(106)->toUnicode(file.readAll());

                if(i == 0)
                {
                    ReadXMLFiles(FileString,headerNames,countColumns);
                    model = new QTableModel(countColumns,fileNames.count(),headerNames,fileNames);
                }
                ReadXML(FileString);
                file.close();
            }

        }

    }
    //model = new QTableModel(countColumns,fileNames.count(),headerNames,fileNames);
    ui->tableView->setModel(model);

}

void MainWindow::on_clearButton_clicked()
{
    model->removeRows();
    model->removeColumns();
    QMessageBox::information(this,"Очистка таблица","Данные успешно удалены");
}

void MainWindow::on_action_2_triggered()
{
    model->removeRows();
    model->removeColumns();
    QMessageBox::information(this,"Очистка таблица","Данные успешно удалены");
}
