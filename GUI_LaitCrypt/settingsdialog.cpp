#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(laiter::Encryption* crypt, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings");
    this->setWindowIcon(QIcon(":/icon/img/icon.png"));
    crypt_ = crypt;
    ui->spinBoxThreads->setValue(crypt_->get_cpu());
    ui->spinBoxLoops->setValue(crypt->get_loop());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_pushButtonReset_clicked()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setWindowTitle("Reset Settings");
    msgBox.setText("Do you want to reset settings to default?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    if(msgBox.exec() == QMessageBox::No) return;

    crypt_->set_real_threads();
    crypt_->set_loop();
    ui->spinBoxThreads->setValue(crypt_->get_cpu());
    ui->spinBoxLoops->setValue(crypt_->get_loop());
}

void SettingsDialog::on_buttonBox_accepted()
{
    crypt_->set_cpu(ui->spinBoxThreads->value());
    crypt_->set_threads();
    crypt_->set_loop(ui->spinBoxLoops->value());
}
