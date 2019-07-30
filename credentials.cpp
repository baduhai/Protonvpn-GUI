#include "credentials.h"
#include "ui_credentials.h"

Credentials::Credentials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Credentials)
{
    ui->setupUi(this);
}

Credentials::~Credentials()
{
    delete ui;
}
