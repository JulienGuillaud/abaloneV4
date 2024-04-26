#ifndef DIALOGCONNECTION_H
#define DIALOGCONNECTION_H

#include <QDialog>

namespace Ui {
class DialogConnection;
}

class DialogConnection : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnection(QWidget *parent = nullptr);
    ~DialogConnection();
    QString getPseudo();
    QString getIp();
private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonLeave_clicked();

private:
    Ui::DialogConnection *ui;
    QString pseudo, ip;
};

#endif // DIALOGCONNECTION_H
