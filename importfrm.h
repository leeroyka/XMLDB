#ifndef IMPORTFRM_H
#define IMPORTFRM_H

#include <QDialog>

namespace Ui {
class importFrm;
}

class importFrm : public QDialog
{
    Q_OBJECT

public:
    explicit importFrm(QWidget *parent = nullptr);
    ~importFrm();

private:
    Ui::importFrm *ui;
};

#endif // IMPORTFRM_H
