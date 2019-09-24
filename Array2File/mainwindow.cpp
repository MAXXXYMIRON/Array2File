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

    ui->tableWidget->setRowCount(1);
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
    int *array = MakeArray(n);


    array = IncArray(array, n,
        [](int x, int y)->int {return rand();});

    OutArrayInTextEdin(array, n,
                       [=](int Arr, int x)
                       {
                            QTableWidgetItem *cell;

                            for(int i = 0; i < n; i++)
                            {
                                if(ui->tableWidget->item(0,i) == nullptr)
                                {
                                    cell = new QTableWidgetItem();
                                    ui->tableWidget->setItem(0, i, cell);
                                }
                            }
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

                           });


        //Считываем массив из файла
        ifstream ArrFil;
        ArrFil.open("C:\Array_file.txt");

        array = fileToArray(ArrFil);

        OutArrayInTextEdin(array, n,
                           [=](int Arr, int i)
                           {

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

void MainWindow::on_spinBoxValue_valueChanged(int arg1)
{
    n = arg1;
    ui->tableWidget->setColumnCount(n);
}
