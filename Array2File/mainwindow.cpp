#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<ctime>
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
        [](int x, int y)->int {cout << "Array[" << y << "] = " << x << endl; return 0;});


    cout << "\nРабота с файлом" << endl;


    //Работа с файлом
    ofstream ArrFil;
    ArrFil.open("C:\Array_file.txt");

    try
    {
        arrayToFile(array, n, ArrFil);
        ArrFil.close();


        cout << "Изменяем массив" << endl << endl;

        array = IncArray(array, n,
            [](int x, int y)->int {return rand();});

        OutArray(array, n,
            [](int x, int y)->int {cout << "Array[" << y << "] = " << x << endl; return 0;});


        cout << endl << "Считываем массив из файла" << endl << endl;

        ifstream ArrFil;
        ArrFil.open("C:\Array_file.txt");

        array = fileToArray(ArrFil);

        OutArray(array, n,
            [](int x, int y)->int {cout << "Array[" << y << "] = " << x << endl; return 0;});
    }
    catch (int e)
    {
        if (e == 1)
            cout << "Ошибка при окрытии файла на запись" << endl;
        else if (e == 2)
            cout << "Ошибка при окрытии файла на чтение" << endl;
        else
            cout << "Файл пуст" << endl;
    }

    delete[] array;
}
