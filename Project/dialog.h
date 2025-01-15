#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Ville.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, Ville* ville = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Ville* ville; // Pointer to Ville object
};

#endif // DIALOG_H
