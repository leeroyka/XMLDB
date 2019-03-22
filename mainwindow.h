#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtablemodel.h>
#include <QXmlStreamReader>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool CheckFiles(QString file);
    void ReadXML(QString file);
    void ReadXMLFiles(QString file,QList<QString> &headerNames, int &count );
private slots:


    void on_importButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    QTableModel *model;

};

#endif // MAINWINDOW_H
