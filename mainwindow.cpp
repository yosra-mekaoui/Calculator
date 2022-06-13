#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtGlobal>
#include "global.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Multiplication quiz");
    this->ui->btnSubmit->setVisible(false);
    this->ui->txtUserInput->setVisible(false);
    this->ui->lblDisplayTitle->setText("Click Start to begin multiplication quiz ");
    this->ui->lblDisplay2->setVisible("true");
    this->ui->lblDisplay->setText(" ");
    this->connect(this->ui->btnStart, SIGNAL(clicked()), this, SLOT(btnStart_click()));
    this->connect(this->ui->btnSubmit, SIGNAL(clicked()), this, SLOT(btnSubmit_click()));
;


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::btnStart_click(){

    this->ui->btnSubmit->setVisible(true);
    this->ui->txtUserInput->setVisible(true);
    this->ui->btnStart->setVisible(false);
    this->ui->txtUserInput->setFocus();
    randomise();
    //this->ui->lblDisplay->setText(" ");
    this->ui->lblDisplayTitle->setText(" ");

}

void MainWindow::btnSubmit_click(){

    QString s = this->ui->txtUserInput->text();

    if(s=="")
    {

        QMessageBox messageBox;
        messageBox.critical(0,"Error","User answer can not be empty !");
        messageBox.setFixedSize(500,200);;
        this->ui->txtUserInput->setFocus();
        this->ui->lblDisplay2->setText( "");
    }
    else{
        int userInput = s.toInt();
        validate(userInput,result);

    }


}

int MainWindow::calculate(int n1, int n2){

   return (n1*n2);

}
void MainWindow::randomise()
{
    reset();
    clickCounter++;
    int high = 12;
    int low = 1;
    randomValue1 = qrand() % ((high + 1) - low) + low;
    randomValue2= qrand() % ((high + 1) - low) + low;
    this->ui->lblDisplay->setText(QString::number(randomValue1)+ " * " + QString::number(randomValue2)+ " = ");
    result = calculate(randomValue1,randomValue2);

}

void MainWindow::validate(int userInput, int result)
{

    if(userInput==result)
    {
        this->ui->lblDisplay2->setText( "Correct!");
        nbrCorrectAnswer++;
        if(clickCounter==10)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Result");
            msgBox.setText("You got "+ QString::number(nbrCorrectAnswer) + "/10 " );
            msgBox.setStandardButtons(QMessageBox::Ok);

           if( msgBox.exec() == QMessageBox::Ok)
               QApplication::quit();
        }
        else
            randomise();
    }

    else
    {
         this->ui->lblDisplay2->setText( "Wrong," + QString::number(randomValue1)+ " * " + QString::number(randomValue2) + " is " + QString::number(result));
        if(clickCounter==10)
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Result");
            msgBox.setText("You got "+ QString::number(nbrCorrectAnswer) + "/10 " );
            msgBox.setStandardButtons(QMessageBox::Ok);

           if( msgBox.exec() == QMessageBox::Ok)
               QApplication::quit();

        }
        else
            randomise();
    }


}

void MainWindow::reset(){


   this->ui-> txtUserInput->setText("");
   this->ui->txtUserInput->setFocus();
   this->ui->txtUserInput->setFocus();

}
