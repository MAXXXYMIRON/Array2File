#ifndef WORKWITHFILE_H
#define WORKWITHFILE_H
#include <fstream>
#include <string>

#endif // WORKWITHFILE_H

using namespace std;

/**
    Запись Матрицы в файл
**/
void matrixTpFile(int** Arr, unsigned Row, unsigned Col, ofstream& FileName);

/**
    Кол-во строк матрице
**/
int numRow(ifstream& FileName);

/**
    Кол-во столбцов в матрице
**/
int numCol(ifstream& FileName);

/**
    Чтение матрицы из файла
**/
int** fileToMatrix(ifstream& FileName);

/**
    Запись массива в файл
**/
void arrayToFile(int* Arr, unsigned n, ofstream& FIleName);

/**
    Кол-во чисел в файле
**/
int numFile(ifstream& FileName);

/**
    Запись файла в массив
**/
int* fileToArray(ifstream& FileName);
