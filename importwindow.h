#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QDialog>

namespace Ui {
class ImportWindow;
}

class ImportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ImportWindow(QList<QString> sucFiles,QList<QString> unSucFiles,QWidget *parent = nullptr);
    ~ImportWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ImportWindow *ui;
};

#endif // IMPORTWINDOW_H
