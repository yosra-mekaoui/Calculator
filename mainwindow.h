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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

private slots:

    void btnStart_click();
    void btnSubmit_click();
    int calculate(int n1, int n2);
    void randomise();
    void reset();
    void validate(int userInput, int result);

};

#endif // MAINWINDOW_H
