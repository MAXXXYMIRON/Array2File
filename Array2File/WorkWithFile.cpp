#include "WorkWithFile.h"
#include "MakeArr.h"
#include <fstream>

using namespace std;

/**
    Запись массива в файл
**/
void arrayToFile(int* Arr, unsigned n, ofstream& FIleName)
{
    if (!FIleName.is_open()) throw 1;

    for (int i = 0; i < n; i++)
        FIleName << Arr[i] << endl;
}


/**
    Кол-во чисел в файле
**/
int numFile(ifstream& FileName)
{
    int n = 0;
    string s;

    while (!FileName.eof())
    {
        getline(FileName, s);
        n++;
    }

    FileName.clear();
    FileName.seekg(0);
    return n - 1;
}

/**
    Запись файла в массив
**/
int* fileToArray(ifstream& FileName)
{
    int n = 0;

    if (!FileName.is_open()) throw 2;
    else
    {
        n = numFile(FileName);
        if (n == 0) throw 3;
    }

    int *Arr = new int[n];
    string number;

    for (int i = 0; i < n; i++)
    {
        getline(FileName, number);
        Arr[i] = stoi(number);
    }

    return Arr;
}

/**
    Запись Матрицы в файл
**/
void matrixTpFile(int** Arr, unsigned Row, unsigned Col, ofstream& FileName)
{
    if(!FileName.is_open()) throw 1;

    for(int i = 0; i < Row; i++)
    {
       for(int j = 0; j < Col; j++)
       {
           FileName << Arr[i][j] << endl;
       }
       FileName << endl;
    }

    FileName.close();
}

/**
    Кол-во строк матрице
**/
int numRow(ifstream& FileName)
{
    int n = 0;
    string s = "";

    while(!FileName.eof())
    {
        getline(FileName, s);
        n = (s != "") ? n + 1 : n;
    }

    FileName.clear();
    FileName.seekg(0);
    return n;
}

/**
    Кол-во столбцов в матрице
**/
int numCol(ifstream& FileName)
{
    int n = 0;
    string s = "";

    while(!FileName.eof())
    {
        getline(FileName, s);
        n = (s == "") ? n + 1 : n;
    }

    FileName.clear();
    FileName.seekg(0);
    return n - 1;
}

/**
    Чтение матрицы из файла
**/
int** fileToMatrix(ifstream& FileName)
{
    string s = "";
    int Row = numCol(FileName);
    int Col = numRow(FileName) / Row;

    if (!FileName.is_open()) throw 2;
    else if (Row == 0) throw 3;

    int** Arr = makeMatrix(Row, Col);

    for(int i = 0; i < Row; i++)
        for(int j = 0; j < Col; j++)
        {
            getline(FileName, s);
            if (s == "") getline(FileName, s);
            Arr[i][j] = stoi(s);
        }

    FileName.close();
    return Arr;
}
















