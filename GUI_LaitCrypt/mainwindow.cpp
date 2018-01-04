#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LaitCrypt");
    this->setWindowIcon(QIcon(":/icon/img/icon.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

laiter::Encryption& MainWindow::getCrypt()
{
    return crypt_;
}

void MainWindow::on_pushButtonOpen_clicked()
{
    filePath_ = QFileDialog::getOpenFileName(this, "Select file");
    //qDebug() << _filePath;
    crypt_.set_file_path(filePath_.toStdString());
    if (filePath_ != "")
    {
        statusBar()->showMessage(filePath_ + " opened");
    }
    else
    {
        statusBar()->showMessage("");
    }
}

void MainWindow::on_pushButtonEncrypt_clicked()
{
    if(filePath_ == "")
    {
        on_pushButtonOpen_clicked();
        if (filePath_ == "") return;
    }
    crypt_.set_key(ui->lineEditCryptogram->text().toStdString());
    statusBar()->showMessage(filePath_ + " encryption started");
    crypt_.encrypt();
    ui->lineEditCryptogram->setText(QString::fromStdString(crypt_.get_key()));
    crypt_.set_key("");
    filePath_ = QString(crypt_.get_file_path().c_str());
    statusBar()->showMessage(filePath_ + " encryption finished");
}

void MainWindow::on_pushButtonDecrypt_clicked()
{
    if(ui->lineEditCryptogram->text() != "")
    {
        crypt_.set_key(ui->lineEditCryptogram->text().toStdString());
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("Key is not set.");
        msgBox.exec();
        return;
    }
    statusBar()->showMessage(filePath_ + " decryption started");
    crypt_.decrypt();
    crypt_.set_key("");
    filePath_ = QString(crypt_.get_file_path().c_str());
    statusBar()->showMessage(filePath_ + " decryption finished");
}

void MainWindow::on_pushButtonLoadCryptogram_clicked()
{
    if(ui->lineEditCryptogram->text() != "")
    {
        crypt_.set_key(ui->lineEditCryptogram->text().toStdString());
    }
}

void MainWindow::on_pushButtonSettings_clicked()
{
    SettingsDialog dlg(&crypt_);
    dlg.exec();
}

void MainWindow::on_actionSettings_triggered()
{
    on_pushButtonSettings_clicked();
}

void MainWindow::on_action_Open_triggered()
{
    on_pushButtonOpen_clicked();
}

void MainWindow::on_action_Encrypt_triggered()
{
    on_pushButtonEncrypt_clicked();
}

void MainWindow::on_action_Decrypt_triggered()
{
    on_pushButtonDecrypt_clicked();
}
