#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credentials.h"
#include "util.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    statFetch(ui);
    iPfetch(ui);
    sourcesFetch(ui);
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

void MainWindow::on_actionCredentials_triggered()
{
    Credentials credentials;
    credentials.setModal(true);
    credentials.exec();
}

void MainWindow::on_refreshBtn_clicked()
{
    iPfetch(ui);
    statFetch(ui);
    sourcesFetch(ui);
}

void MainWindow::on_securecoreBtn_clicked()
{
    connectSCC();
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_torBtn_clicked()
{
    connectTOR();
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_p2pBtn_clicked()
{
    connectP2P();
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_fastBtn_clicked()
{
    connectFast();
}

void MainWindow::on_lastBtn_clicked()
{
    connectLast();
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_randomBtn_clicked()
{
    connectRandom();
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_connectBtn_clicked()
{
    disconnect();
    iPfetch(ui);
    statFetch(ui);
}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();
}
