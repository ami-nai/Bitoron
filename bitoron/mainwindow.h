#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase mydb;

    void connclose () {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connopen () {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("F:/Shahriar IIUC/2nd Sem/CSE/Final/Final Project/Bit-trial/bitoron/LogInData.db");

        if (!mydb.open()) {
            qDebug("Database cannot be accessed");
            return false;
        }
        else {
            qDebug("Database Connected");
            return true;
        }

    }

//    QSqlDatabase myorder;

//    void connclose2 () {
//        myorder.close();
//        myorder.removeDatabase(QSqlDatabase::defaultConnection);
//    }

//    bool connopen2 () {
//        myorder=QSqlDatabase::addDatabase("QSQLITE");
//        myorder.setDatabaseName("C:/Qt/Projects/Bitoron-main/bitoron/LogInData.db");

//        if (!myorder.open()) {
//            qDebug("Database cannot be accessed");
//            return false;
//        }
//        else {
//            qDebug("Database Connected");
//            return true;
//        }

//    }


private slots:


    void on_Btn_signin_clicked();

    void on_Btn_signup_clicked();

    void on_Btn_sendParcel_clicked();

    void on_Btn_deliveryMan_clicked();

    void on_Btn_admin_clicked();

    void on_signinBtn_2_clicked();

    void on_signupBtn_2_clicked();

    void on_signinBtn_3_clicked();

    void on_signupBtn_3_clicked();

    void on_signinBtn_clicked();

    void on_signupBtn_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H