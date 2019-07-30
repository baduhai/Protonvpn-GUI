#include <QProcess>
#include <QString>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credentials.h"
#include "util.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statFetch(ui);
    iPfetch(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_credentials_clicked()
{
    Credentials credentials;
    credentials.setModal(true);
    credentials.exec();
}

void MainWindow::on_refreshBtn_clicked()
{
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_securecoreBtn_clicked()
{
    connectSCC();
}

void MainWindow::on_torBtn_clicked()
{
    connectTOR();
}

void MainWindow::on_p2pBtn_clicked()
{
    connectP2P();
}

void MainWindow::on_fastBtn_clicked()
{
    connectFast();
}

void MainWindow::on_lastBtn_clicked()
{
    connectLast();
}

void MainWindow::on_randomBtn_clicked()
{
    connectRandom();
}
