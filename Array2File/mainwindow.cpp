#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<QMessageBox>
#include"MakeArr.h"
#include "WorkWithFile.h"

using namespace std;
using IncOut = int(*)(int, int);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonStart_clicked()
{
    setlocale(0, "");


    //Инциализация массива
    srand(time(NULL));
    unsigned n = (rand() % 10) + 1;
    int *array = MakeArray(n);

    array = IncArray(array, n,
        [](int x, int y)->int {return rand();});

    OutArray(array, n,
        [](int x, int y)->int {
        ui->LabelFirstArray->setText(QString::number(x));
        return 0;
    });


    //Работа с файлом
    ofstream ArrFil;
    ArrFil.open("C:\Array_file.txt");

    try
    {
        arrayToFile(array, n, ArrFil);
        ArrFil.close();


        //Изменяем массив
        array = IncArray(array, n,
            [](int x, int y)->int {return rand();});

        OutArray(array, n,
            [](int x, int y)->int {
            ui->LabelSecondArray->setText(QString::number(x));
            return 0;
        });


        //Считываем массив из файла
        ifstream ArrFil;
        ArrFil.open("C:\Array_file.txt");

        array = fileToArray(ArrFil);

        OutArray(array, n,
            [](int x, int y)->int {
            ui->LabelFileToArray->setText(QString::number(x));
            return 0;
        });

        ArrFil.close();
    }
    catch (int e)
    {
        if (e == 1)
        {
            QMessageBox::warning(this, "Внимание", "Ошибка при окрытии файла на запись");
            close();
        }
        else if (e == 2)
        {
            QMessageBox::warning(this, "Внимание", "Ошибка при окрытии файла на чтение");
            close();
        }
        else
        {
            QMessageBox::warning(this, "Внимание", "Файл пуст");
            close();
        }
    }

    delete[] array;
}
