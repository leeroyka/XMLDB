#ifndef IMPORTFORM_H
#define IMPORTFORM_H

#include <QWidget>

namespace Ui {
class importForm;
}

class importForm : public QWidget
{
    Q_OBJECT

public:
    explicit importForm(QWidget *parent = nullptr);
    ~importForm();

private:
    Ui::importForm *ui;
};

#endif // IMPORTFORM_H
