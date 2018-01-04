#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include <QDialog>
#include <QFileSystemModel>
#include "settingsdialog.h"
#include "encryption.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    laiter::Encryption& getCrypt();

private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonEncrypt_clicked();

    void on_pushButtonDecrypt_clicked();

    void on_pushButtonLoadCryptogram_clicked();

    void on_pushButtonSettings_clicked();

    void on_actionSettings_triggered();

    void on_action_Open_triggered();

    void on_action_Encrypt_triggered();

    void on_action_Decrypt_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath_;
    laiter::Encryption crypt_;
};

#endif // MAINWINDOW_H
