#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<QMessageBox>
#include<functional>
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

void OutArrayInTextEdin(int *Arr, unsigned n, function<void(int, int)> Out)
{
    for(int i = 0; i < n; i++)
    {
        Out(Arr[i], i);
    }
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

    OutArrayInTextEdin(array, n,
                       [=](int Arr, int i)
                       {
                            ui->TextEFirstArray->append("Array[" + QString::number(i) + "] = " +
                            QString::number(Arr));
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

        OutArrayInTextEdin(array, n,
                           [=](int Arr, int i)
                           {
                                ui->TextESecondArray->append("Array[" + QString::number(i) + "] = " +
                                QString::number(Arr));
                           });


        //Считываем массив из файла
        ifstream ArrFil;
        ArrFil.open("C:\Array_file.txt");

        array = fileToArray(ArrFil);

        OutArrayInTextEdin(array, n,
                           [=](int Arr, int i)
                           {
                                ui->TextEFileToArray->append("Array[" + QString::number(i) + "] = " +
                                QString::number(Arr));
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
