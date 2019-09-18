#include "mainwindow.h"
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"MakeArr.h"
#include "WorkWithFile.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
