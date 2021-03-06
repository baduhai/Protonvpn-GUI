#include <QProcess>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "credentials.h"

#ifndef UTIL_H
#define UTIL_H

const static QString protonCli = "/usr/bin/protonvpn-cli -"; // Set master protonvpn-cli command
const static QString elevatedProtonCli = "pkexec /usr/bin/protonvpn-cli -"; // Set master protonvpn-cli command

const static QString ipCmd(protonCli+"-ip"); // Set command to find IP
static QProcess fetchIP; // Initialise process fetchIP
void iPfetch(Ui::MainWindow* ui); // Fetching IP address

const static QString statCmd(protonCli+"-status"); // Set command to determine connection
static QProcess fetchStat; // Initialise process fetchStat
static QString outputStat;
void statFetch(Ui::MainWindow* ui); // Fetching connection status

const static QString sscCmd(elevatedProtonCli+"sc"); // Set command to connect "Secure Core"
static QProcess sscConnect; // Initialise process sscConnect
void connectSCC(); // Secure Core Connect

const static QString torCmd(elevatedProtonCli+"tor"); // Set command to connect TOR
static QProcess torConnect; // Initialise process torConnect
void connectTOR(); // TOR Connect

const static QString p2pCmd(elevatedProtonCli+"p2p"); // Set command to connect P2P
static QProcess p2pConnect; // Initialise process p2pConnect
void connectP2P(); // P2P Connect

const static QString fastCmd(elevatedProtonCli+"f"); // Set command to connect fastest server
static QProcess fastConnect; // Initialise process fastConnect
void connectFast(); // Fastest Connect

const static QString lastCmd(elevatedProtonCli+"l"); // Set command to connect last server
static QProcess lastConnect; // Initialise process lastConnect
void connectLast(); // Last Connect

const static QString randomCmd(elevatedProtonCli+"r"); // Set command to connect random server
static QProcess randomConnect; // Initialise process randomConnect
void connectRandom(); // Random Connect

const static QString disconnectCmd(elevatedProtonCli+"d"); // Set command to disconnect
static QProcess disConnect; // Initialise process disConnect
void disconnect(); // Disconnect

const static QUrl sourcesUrl("https://api.protonmail.ch/vpn/logicals/"); // Set URL of adress list
static QNetworkRequest request; // Initialise network request "request"
const static  QStringList labels = { "#", "Country", "City", "Domain", "IP", "Load" }; // Set headings
static QJsonDocument sources;
void sourcesFetch(Ui::MainWindow* ui); // Fetch sources

#endif // UTIL_H
