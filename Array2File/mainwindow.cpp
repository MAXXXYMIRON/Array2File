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

    ui->TWFirstArr->setRowCount(1);
    ui->TWSecondArr->setRowCount(1);
    ui->TWFileArr->setRowCount(1);
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

    n = ui->spinBoxValue->value();//Берём значение из SpinBox'a
    int *array = MakeArray(n);

    array = IncArray(array, n,
        [](int x, int y)->int {return rand() % 10;});


    ui->TWFirstArr->setColumnCount(n);
    ui->TWSecondArr->setColumnCount(n);
    ui->TWFileArr->setColumnCount(n);
    QTableWidgetItem *cell;

    for(int i = 0; i < n; i++)
    {
        if(ui->TWFirstArr->item(0,i) == nullptr)
        {
            cell = new QTableWidgetItem();
            ui->TWFirstArr->setItem(0, i, cell);
            cell = new QTableWidgetItem();
            ui->TWSecondArr->setItem(0, i, cell);
            cell = new QTableWidgetItem();
            ui->TWFileArr->setItem(0, i, cell);
        }
    }

    //Вывод массива
    OutArrayInTextEdin(array, n,
       [=](int Arr, int x)
       {
            ui->TWFirstArr->item(0, x)->setText(QString::number(Arr));
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
            [](int x, int y)->int {return rand() % 10;});

        OutArrayInTextEdin(array, n,
           [=](int Arr, int x)
           {
                ui->TWSecondArr->item(0, x)->setText(QString::number(Arr));
           });



        //Считываем массив из файла
        ifstream ArrFil;
        ArrFil.open("C:\Array_file.txt");

        array = fileToArray(ArrFil);

        OutArrayInTextEdin(array, n,
           [=](int Arr, int x)
           {
                ui->TWFileArr->item(0, x)->setText(QString::number(Arr));
           });

        ArrFil.close();
    }


    catch (int e)
    {
        if (e == 1)
        {
            QMessageBox::warning(this, "Внимание", "Ошибка при окрытии файла на запись");
        }
        else if (e == 2)
        {
            QMessageBox::warning(this, "Внимание", "Ошибка при окрытии файла на чтение");
        }
        else
        {
            QMessageBox::warning(this, "Внимание", "Файл пуст");
        }
    }

    delete[] array;
}

