#include <QProcess>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifndef UTIL_H
#define UTIL_H

const static QString protonCli = "/usr/bin/protonvpn-cli -"; // Set master protonvpn-cli command

const static QString ipCmd(protonCli+"-ip"); // Set command to find IP
static QProcess fetchIP; // Initialise process fetchIP
void iPfetch(Ui::MainWindow* ui); // Fetching IP address

const static QString statCmd(protonCli+"-status"); // Set command to determine connection
static QProcess fetchStat; // Initialise process fetchStat
void statFetch(Ui::MainWindow* ui); // Fetching connection status

const static QString sscCmd(protonCli+"sc"); // Set command to connect "Secure Core"
static QProcess sscConnect; // Initialise process sscConnect
void connectSCC(); // Safety Core Connect

const static QString torCmd(protonCli+"tor"); // Set command to connect TOR
static QProcess torConnect; // Initialise process torConnect
void connectTOR(); // TOR Connect

const static QString p2pCmd(protonCli+"p2p"); // Set command to connect P2P
static QProcess p2pConnect; // Initialise process p2pConnect
void connectP2P(); // P2P Connect

const static QString fastCmd(protonCli+"f"); // Set command to connect fastest server
static QProcess fastConnect; // Initialise process fastConnect
void connectFast(); // Fastest Connect

const static QString lastCmd(protonCli+"l"); // Set command to connect last server
static QProcess lastConnect; // Initialise process lastConnect
void connectLast(); // Last Connect

const static QString randomCmd(protonCli+"r"); // Set command to connect random server
static QProcess randomConnect; // Initialise process randomConnect
void connectRandom(); // Random Connect

const static QString disconnectCmd(protonCli+"d"); // Set command to disconnect
static QProcess disConnect; // Initialise process disConnect
void disconnect(); // Disconnect

#endif // UTIL_H
