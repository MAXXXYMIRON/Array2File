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

//Лямбда выражение для вывода в TableWidget
void OutMatrixInTW(int **Arr, unsigned Row, unsigned Col, function<void(int, int, int)> Out)
{
    for(int i = 0; i < Row; i++)
        for(int j = 0; j < Col; j++)
        {
           Out(Arr[i][j], i, j);
        }
}



void MainWindow::on_ButtonStart_clicked()
{
    setlocale(0, "");

    //Создание и инциализация массива
    srand(time(NULL));

    Row = ui->spinBoxRow->value();
    Col = ui->spinBoxCol->value();

    Matrix = makeMatrix(Row, Col);
    Matrix = initMatrix(Matrix, Row, Col,
                        [](int x, int y){return rand() % 10;});



    //Создание ячеек TableWidget
    /////////////////////////////////////////////////////
    ui->TWFirstArr->setColumnCount(Col);
    ui->TWSecondArr->setColumnCount(Col);
    ui->TWFileArr->setColumnCount(Col);
    ui->TWFirstArr->setRowCount(Row);
    ui->TWSecondArr->setRowCount(Row);
    ui->TWFileArr->setRowCount(Row);

    QTableWidgetItem *cell;
    for(int i = 0; i < Col; i++)
    {
        for(int j = 0; j < Row; j++)
        {
            if(ui->TWFirstArr->item(j,i) == nullptr)
            {
                cell = new QTableWidgetItem();
                ui->TWFirstArr->setItem(j, i, cell);
                cell = new QTableWidgetItem();
                ui->TWSecondArr->setItem(j, i, cell);
                cell = new QTableWidgetItem();
                ui->TWFileArr->setItem(j, i, cell);
            }
        }
    }
    /////////////////////////////////////////////////////


    //Вывод матрицы
    OutMatrixInTW(Matrix, Row, Col,
       [=](int Arr, int i, int j)
       {
            ui->TWFirstArr->item(i, j)->setText(QString::number(Arr));
       });



    //Работа с файлом
    ofstream ArrFil;
    ArrFil.open("C:\Array_file.txt");

    try
    {
        void matrixTpFile(int** Matrix, unsigned Row, unsigned Col, ofstream& ArrFil);
        ArrFil.close();


        //Изменяем матрицу
        Matrix = initMatrix(Matrix, Row, Col,
                            [](int x, int y){return rand() % 10;});

        //Вывод матрицы
        OutMatrixInTW(Matrix, Row, Col,
           [=](int Arr, int i, int j)
           {
                ui->TWSecondArr->item(i, j)->setText(QString::number(Arr));
           });



        //Считываем массив из файла
        ifstream ArrFil;
        ArrFil.open("C:\Array_file.txt");

        array = fileToArray(ArrFil);

        //Вывод матрицы
        OutMatrixInTW(Matrix, Row, Col,
           [=](int Arr, int i, int j)
           {
                ui->TWFileArr->item(i, j)->setText(QString::number(Arr));
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

    Matrix = delMatrix(Matrix, Row, Col);
}

