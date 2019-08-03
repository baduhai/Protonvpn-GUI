#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_credentials_clicked();
    void on_refreshBtn_clicked();
    void on_securecoreBtn_clicked();
    void on_torBtn_clicked();
    void on_p2pBtn_clicked();
    void on_fastBtn_clicked();
    void on_lastBtn_clicked();
    void on_randomBtn_clicked();

    void on_connectBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
