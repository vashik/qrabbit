#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "hubconnection.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindowClass *ui;
    QList<HubConnection*> hubs;
public slots:
    void slotDisplayMessages(QString&);
private slots:
    void on_lineSearch_returnPressed();
    void on_lineEdit_returnPressed();
    void on_btnStart_clicked();
};

#endif // MAINWINDOW_H
