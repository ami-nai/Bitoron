#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->container->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Qt/Projects/Bitoron/bitoron/data.db");
    db.open();
    if (db.isOpen()) qDebug("Database accessed.");
    else qDebug("Check the location of the database file");
}

MainWindow::~MainWindow()
{
    db.close();
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
    QString UserName, Password;
    UserName = ui->userLineEdit_3->text();
    Password = ui->passLineEdit_2->text();

    QSqlQuery query;
    query.exec("SELECT * FROM Users WHERE Nickname = ('"+UserName+"') AND password = ('"+Password+"') ");
    if (query.next()) {
        ui->container->setCurrentIndex(4);
    }
    else {
        qDebug() << "Didn't found user!" << endl;
    }
}

void MainWindow::on_signupBtn_2_clicked()
{
    QString firstname, lastname, nickname, district, mobile, password;
    firstname = ui->firstnameLineEdit_2->text();
    lastname = ui->lastnameLineEdit_2->text();
    nickname = ui->userLineEdit_4->text();
    district = ui->disLineEdit_4->text();
    mobile = ui->mobileLineEdit_5->text();
    password = ui->passLineEdit_6->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Users (first, last, nickname, district, mobile, password, gender) VALUES ('"+firstname+"', '"+lastname+"', '"+nickname+"', '"+district+"', '"+mobile+"', '"+password+"', '"+gender+"')");

    if (query.exec()) {
        qDebug() << "Inserted User into database !" << endl;
        qDebug() << "Gender: " << gender << endl;
    }
    else {
        qDebug() << "Failed to insert user." << endl;
    }
}

void MainWindow::on_signinBtn_3_clicked()
{
    QString AdminName, Password;
    AdminName = ui->userLineEdit_5->text();
    Password = ui->passLineEdit_3->text();

    QSqlQuery query;
    query.exec("SELECT * FROM Admins WHERE Nickname = ('"+AdminName+"') AND password = ('"+Password+"') ");
    if (query.next()) {
        ui->container->setCurrentIndex(6);
    }
    else {
        qDebug() << "Didn't found Admin!" << endl;
    }
}


void MainWindow::on_signupBtn_3_clicked()
{
    QString firstname, lastname, nickname, district, mobile, password;
    firstname = ui->firstnameLineEdit_3->text();
    lastname = ui->lastnameLineEdit_3->text();
    nickname = ui->userLineEdit_6->text();
    district = ui->disLineEdit_5->text();
    mobile = ui->mobileLineEdit_6->text();
    password = ui->passLineEdit_7->text();

    QSqlQuery query;
    query.prepare("INSERT INTO Admins (first, last, nickname, district, mobile, password, gender) VALUES ('"+firstname+"', '"+lastname+"', '"+nickname+"', '"+district+"', '"+mobile+"', '"+password+"', '"+gender+"')");

    if (query.exec()) {
        qDebug() << "Inserted Admin into database !" << endl;
        qDebug() << "Gender: " << gender << endl;
    }
    else {
        qDebug() << "Failed to insert Admin." << endl;
    }
}


void MainWindow::on_signinBtn_clicked()
{
    QString BoyName, Password;
    BoyName = ui->userLineEdit->text();
    Password = ui->passLineEdit->text();

    QSqlQuery query;
    query.exec("SELECT * FROM DeliveryBoys WHERE Nickname = ('"+BoyName+"') AND password = ('"+Password+"') ");
    if (query.next()) {
        ui->container->setCurrentIndex(0);
    }
    else {
        qDebug() << "Didn't found Delivery Boy!" << endl;
    }
}


void MainWindow::on_signupBtn_clicked()
{
    QString firstname, lastname, nickname, district, mobile, password;
    firstname = ui->firstnameLineEdit->text();
    lastname = ui->lastnameLineEdit->text();
    nickname = ui->userLineEdit_2->text();
    district = ui->disLineEdit_3->text();
    mobile = ui->mobileLineEdit_4->text();
    password = ui->passLineEdit_5->text();

    QSqlQuery query;
    query.prepare("INSERT INTO DeliveryBoys (first, last, nickname, district, mobile, password, gender) VALUES ('"+firstname+"', '"+lastname+"', '"+nickname+"', '"+district+"', '"+mobile+"', '"+password+"', '"+gender+"')");

    if (query.exec()) {
        qDebug() << "Inserted Delivery Boy into database !" << endl;
        qDebug() << "Gender: " << gender << endl;
    }
    else {
        qDebug() << "Failed to insert Delivery Boy." << endl;
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QString source, destination, name, mobile, address;
    source = ui->lineEdit->text();
    destination = ui->lineEdit_2->text();
    name = ui->lineEdit_3->text();
    mobile = ui->lineEdit_4->text();
    address = ui->lineEdit_5->text();

    QSqlQuery query;
    if (type == "document") {
        query.prepare("INSERT INTO Documents (Source, Destination, Name, Mobile, Address) VALUES ('"+source+"', '"+destination+"', '"+name+"', '"+mobile+"', '"+address+"')");

        if (query.exec()) {
            qDebug() << "Inserted document into database !" << endl;
        }
        else {
            qDebug() << "Failed to insert document." << endl;
        }
    }
    else if (type == "package") {
        query.prepare("INSERT INTO Package (Source, Destination, Name, Mobile, Address) VALUES ('"+source+"', '"+destination+"', '"+name+"', '"+mobile+"', '"+address+"')");

        if (query.exec()) {
            qDebug() << "Inserted package into database !" << endl;
        }
        else {
            qDebug() << "Failed to insert package." << endl;
        }
    }
    else if (type == "electronics") {
        query.prepare("INSERT INTO Electronics (Source, Destination, Name, Mobile, Address) VALUES ('"+source+"', '"+destination+"', '"+name+"', '"+mobile+"', '"+address+"')");

        if (query.exec()) {
            qDebug() << "Inserted electronics into database !" << endl;
        }
        else {
            qDebug() << "Failed to insert electronics." << endl;
        }
    }
    else if (type == "gift") {
        query.prepare("INSERT INTO Gift (Source, Destination, Name, Mobile, Address) VALUES ('"+source+"', '"+destination+"', '"+name+"', '"+mobile+"', '"+address+"')");

        if (query.exec()) {
            qDebug() << "Inserted gift into database !" << endl;
        }
        else {
            qDebug() << "Failed to insert gift." << endl;
        }
    }


    //qDebug() << name << " " << mobile << " " << address << " " << pickup << " " << drop << type;
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


void MainWindow::on_Document_2_clicked()
{

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->admin_container->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{

}


void MainWindow::on_pushButton_17_clicked()
{

}


void MainWindow::on_pushButton_16_clicked()
{
    ui->admin_container->setCurrentIndex(3);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->container->setCurrentIndex(0);
}


void MainWindow::on_maleBtn_clicked()
{
    gender = "male";
}


void MainWindow::on_femaleBtn_clicked()
{
    gender = "female";
}


void MainWindow::on_Document_clicked()
{
    type = "document";
}


void MainWindow::on_Package_clicked()
{
    type = "package";
}


void MainWindow::on_Electronic_clicked()
{
    type = "electronics";
}


void MainWindow::on_Gift_clicked()
{
    type = "gift";
}


void MainWindow::on_maleBtn_2_clicked()
{
    gender = "male";
}


void MainWindow::on_femaleBtn_2_clicked()
{
    gender = "female";
}


void MainWindow::on_maleBtn_3_clicked()
{
    gender = "male";
}


void MainWindow::on_femaleBtn_3_clicked()
{
    gender = "female";
}

