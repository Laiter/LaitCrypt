#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "encryption.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(laiter::Encryption* crypt, QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    void on_pushButtonReset_clicked();

    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
    laiter::Encryption* crypt_;
};

#endif // SETTINGSDIALOG_H
