#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->container->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Btn_signin_clicked()
{
    ui->container->setCurrentIndex(2);  //stackedWidget is renamed as container

}

void MainWindow::on_Btn_signup_clicked()
{
    ui->container->setCurrentIndex(2);  //stackedWidget is renamed as container
}

void MainWindow::on_Btn_sendParcel_clicked()
{
    ui->container->setCurrentIndex(2);  //stackedWidget is renamed as container
}

void MainWindow::on_Btn_deliveryMan_clicked()
{
    ui->container->setCurrentIndex(1);  //stackedWidget is renamed as container
}

void MainWindow::on_Btn_admin_clicked()
{
    ui->container->setCurrentIndex(3);  //stackedWidget is renamed as container
}


void MainWindow::on_signinBtn_2_clicked()
{
    connopen();

    QString UserName, Password, status = "user";
    UserName = ui->userLineEdit_3->text();
    Password = ui->passLineEdit_2->text();

    QSqlQuery qry;
    qry.prepare("select * from list where Username='"+UserName+"' and Password = '"+Password+"' and Status = '"+status+"'");
    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            connclose();
            ui->container->setCurrentIndex(4);
        }
        else if (count == 0){
            QMessageBox msgBox;
            msgBox.setText("User not found");
            msgBox.exec();
            connclose();
        }
    }
}

void MainWindow::on_signupBtn_2_clicked()
{
    connopen();

    QString firstname, lastname, username, district, mobile, password, gender, status;
    firstname = ui->firstnameLineEdit_2->text();
    lastname = ui->lastnameLineEdit_2->text();
    username = ui->userLineEdit_4->text();
    district = ui->disLineEdit_4->text();
    mobile = ui->mobileLineEdit_5->text();
    password = ui->passLineEdit_6->text();
    if (ui->maleBtn_2) {
        gender = "Male";
    }
    if (ui->femaleBtn_2){
        gender = "Female";
    }
    status = "user";

    QSqlQuery qry;
    qry.prepare("insert into list (FirstName, LastName, Username, District, Mobile, Password, Gender, Status) values ('"+firstname+"', '"+lastname+"', '"+username+"', '"+district+"', '"+mobile+"', '"+password+"', '"+gender+"', '"+status+"')");

    if (qry.exec()) {
        QMessageBox msgBox;
        msgBox.setText("!!! Welcome !!!");
        msgBox.exec();
        connclose();
        ui->container->setCurrentIndex(4);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("!!! ERROR !!!");
        msgBox.exec();
        connclose();
    }
}

void MainWindow::on_signinBtn_3_clicked()
{
    connopen();

    QString AdminName, Password, status = "admin";
    AdminName = ui->userLineEdit_5->text();
    Password = ui->passLineEdit_3->text();


    QSqlQuery qry;
    qry.prepare("select * from list where Username='"+AdminName+"' and Password = '"+Password+"' and Status = '"+status+"'");
    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            connclose();
            ui->container->setCurrentIndex(6);
        }
        else if (count == 0){
            QMessageBox msgBox;
            msgBox.setText("Admin not found");
            msgBox.exec();
            connclose();
        }
    }
}


void MainWindow::on_signupBtn_3_clicked()
{
    connopen();

    QString firstname, lastname, username, district, mobile, password, gender, status;
    firstname = ui->firstnameLineEdit_3->text();
    lastname = ui->lastnameLineEdit_3->text();
    username = ui->userLineEdit_6->text();
    district = ui->disLineEdit_5->text();
    mobile = ui->mobileLineEdit_6->text();
    password = ui->passLineEdit_7->text();
    if (ui->maleBtn_3) {
        gender = "Male";
    }
    if (ui->femaleBtn_3){
        gender = "Female";
    }
    status = "admin";

    QSqlQuery qry;
    qry.prepare("insert into list (FirstName, LastName, Username, District, Mobile, Password, Gender, Status) values ('"+firstname+"', '"+lastname+"', '"+username+"', '"+district+"', '"+mobile+"', '"+password+"', '"+gender+"', '"+status+"')");

    if (qry.exec()) {
        QMessageBox msgBox;
        msgBox.setText("!!! Welcome !!!");
        msgBox.exec();
        connclose();
        ui->container->setCurrentIndex(6);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("!!! ERROR !!!");
        msgBox.exec();
        connclose();
    }
}


void MainWindow::on_signinBtn_clicked()
{
    connopen();

    QString BoyName, Password, status = "delivery";
    BoyName = ui->userLineEdit->text();
    Password = ui->passLineEdit->text();

    QSqlQuery qry;
    qry.prepare("select * from list where Username='"+BoyName+"' and Password = '"+Password+"' and Status = '"+status+"'");
    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            ui->container->setCurrentIndex(6);
            connclose();
        }
        else if (count == 0){
            QMessageBox msgBox;
            msgBox.setText("Not found");
            msgBox.exec();
            connclose();
        }
    }
}


void MainWindow::on_signupBtn_clicked()
{
    connopen();

    QString firstname, lastname, username, district, mobile, password, gender, status;
    firstname = ui->firstnameLineEdit->text();
    lastname = ui->lastnameLineEdit->text();
    username = ui->userLineEdit_2->text();
    district = ui->disLineEdit_3->text();
    mobile = ui->mobileLineEdit_4->text();
    password = ui->passLineEdit_5->text();

    if (ui->maleBtn) {
        gender = "Male";
    }
    if (ui->femaleBtn){
        gender = "Female";
    }

    status = "delivery";

    QSqlQuery qry;
    qry.prepare("insert into list (FirstName, LastName, Username, District, Mobile, Password, Gender, Status) values ('"+firstname+"', '"+lastname+"', '"+username+"', '"+district+"', '"+mobile+"', '"+password+"', '"+gender+"', '"+status+"')");

    if (qry.exec()) {
        QMessageBox msgBox;
        msgBox.setText("!!! Welcome !!!");
        msgBox.exec();
        connclose();
        ui->container->setCurrentIndex(0);
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("!!! ERROR !!!");
        msgBox.exec();
        connclose();
    }
}



void MainWindow::on_pushButton_8_clicked()
{
    QString name, mobile, address, pickup, drop, type;
    name = ui->lineEdit_3->text();
    mobile = ui->lineEdit_4->text();
    address = ui->lineEdit_5->text();
    pickup = ui->lineEdit->text();
    drop = ui->lineEdit_2->text();

    if (ui->Document->isChecked()) type = "Document";
    else if (ui->Package->isChecked()) type = "Package";
    else if (ui->Electronic->isChecked()) type = "Electronic";
    else if (ui->Gift->isChecked()) type = "Gift";

    qDebug() << name << " " << mobile << " " << address << " " << pickup << " " << drop;

    connopen();

    QSqlQuery qry1;
    qry1.prepare("INSERT INTO `Order` (Name, MobileW, Address, Pickup, Drop, Type) "
                 "VALUES (:name, :mobile, :address, :pickup, :drop, :type)");

    qry1.bindValue(":name", name);
    qry1.bindValue(":mobile", mobile);
    qry1.bindValue(":address", address);
    qry1.bindValue(":pickup", pickup);
    qry1.bindValue(":drop", drop);
    qry1.bindValue(":type", type);

    bool success = qry1.exec();

    if (success) {
        QMessageBox msgBox;
        msgBox.setText("!!! Thank you for trusting us !!!");
        msgBox.exec();
        connclose();
        ui->container->setCurrentIndex(0);
    } else {
        QMessageBox msgBox;
        msgBox.setText("!!! ERROR !!!");
        msgBox.exec();
        connclose();
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->container->setCurrentIndex(0);
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->container->setCurrentIndex(0);
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->container->setCurrentIndex(0);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->container->setCurrentIndex(0);
}


void MainWindow::on_homeBtn_clicked()
{
    ui->container->setCurrentIndex(0);
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->container->setCurrentIndex(2);
}


void MainWindow::on_backBtn_clicked()
{
    ui->container->setCurrentIndex(4);
}



