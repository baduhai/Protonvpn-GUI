#include "util.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QString>

void iPfetch(Ui::MainWindow* ui) // Fetching IP address
{
    fetchIP.start(ipCmd); // Start process fetchIP
    fetchIP.waitForFinished(); // Wait for process fetchIP to finish
    QString outputIPraw(fetchIP.readAllStandardOutput()); // Store output of fetchIP
    QString outputIP = outputIPraw.split("\n").at(0); // Parse output of fetchIP
    ui->addressVal->setText(outputIP); // Display output of fetchIP
}

void statFetch(Ui::MainWindow* ui) // Fetching connection status
{
    fetchStat.start(statCmd); // Start process fetchStat
    fetchStat.waitForFinished(); // Wait for process fetchStat to finish
    QString outputStatRaw(fetchStat.readAllStandardOutput()); // Store output of fetchStat
    QString outputStat = outputStatRaw.split("\n").at(0); // Parse output of fetchStat
    // Determine whether connected or not and display output of outputStat
    if (outputStat == "[OpenVPN Status]: Not Running") {
        outputStat = "Disconnected";
        ui->securecoreBtn->setEnabled(1);
        ui->torBtn->setEnabled(1);
        ui->p2pBtn->setEnabled(1);
        ui->fastBtn->setEnabled(1);
        ui->lastBtn->setEnabled(1);
        ui->randomBtn->setEnabled(1);
        ui->reconnectBtn->setEnabled(0);
        ui->connectBtn->setText("Connect");
        ui->statusVal->setText(outputStat);
        ui->statusVal->setStyleSheet("QLabel { color : red; }");
    }
    else if (outputStat == "[OpenVPN Status]: Running") {
        outputStat = "Connected";
        ui->securecoreBtn->setEnabled(0);
        ui->torBtn->setEnabled(0);
        ui->p2pBtn->setEnabled(0);
        ui->fastBtn->setEnabled(0);
        ui->lastBtn->setEnabled(0);
        ui->randomBtn->setEnabled(0);
        ui->reconnectBtn->setEnabled(1);
        ui->connectBtn->setText("Disconnect");
        ui->statusVal->setText(outputStat);
        ui->statusVal->setStyleSheet("QLabel { color : green; }");
    }
    else { //This situation shouldn't exist
        outputStat = "Is protonvpn-cli installed?";
    }
}

void connectSCC() // Safety Core Connect
{
    sscConnect.start(sscCmd); // Start process sscConnect
    sscConnect.waitForFinished(); // Wait for process sscConnect to finish
}

void connectTOR() // TOR Connect
{
    torConnect.start(torCmd); // Start process torConnect
    torConnect.waitForFinished(); // Wait for process torConnect to finish
}

void connectP2P() // P2P Connect
{
    p2pConnect.start(p2pCmd); // Start process p2pConnect
    p2pConnect.waitForFinished(); // Wait for process p2pConnect to finish
}

void connectFast() // Fastest Connect
{
    fastConnect.start(fastCmd); // Start process fastConnect
    fastConnect.waitForFinished(); // Wait for process fastConnect to finish
}

void connectLast() // Last Connect
{
    lastConnect.start(lastCmd); // Start process lastConnect
    lastConnect.waitForFinished(); // Wait for process lastConnect to finish
}

void connectRandom() // Random Connect
{
    randomConnect.start(randomCmd); // Start process randomConnect
    randomConnect.waitForFinished(); // Wait for process randomConnect to finish
}

void disconnect() // Disconnect
{
    disConnect.start(disconnectCmd); // Start process disConnect
    disConnect.waitForFinished(); // Wait for process disConnect to finish
}
