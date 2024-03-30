#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QFileInfo>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


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

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_10_clicked();

    void on_homeBtn_clicked();

    void on_pushButton_9_clicked();

    void on_backBtn_clicked();

    void on_Document_2_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_maleBtn_clicked();

    void on_femaleBtn_clicked();

    void on_Document_clicked();

    void on_Package_clicked();

    void on_Electronic_clicked();

    void on_Gift_clicked();

    void on_maleBtn_2_clicked();

    void on_femaleBtn_2_clicked();

    void on_maleBtn_3_clicked();

    void on_femaleBtn_3_clicked();

private:
    Ui::MainWindow *ui;
    QString gender, type;
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
