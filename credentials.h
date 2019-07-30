#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <QDialog>

namespace Ui {
    class Credentials;
}

class Credentials : public QDialog
{
    Q_OBJECT

public:
    explicit Credentials(QWidget *parent = nullptr);
    ~Credentials();

private:
    Ui::Credentials *ui;
};

#endif // CREDENTIALS_H
