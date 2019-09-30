#include<iostream>
#include<string>
#include"MakeArr.h"


using namespace std;

    /**
        Выделение памяти для массива
    **/
    int* MakeArray(unsigned n)
    {
        int* Arr = new int[n];
        return Arr;
    }

    /**
        Заполнение массива
    **/
    int* IncArray(int* Arr, unsigned n, IncOut Inc)
    {
        for (int i = 0; i < n; i++)
            Arr[i] = Inc(0, 0);

        return Arr;
    }

    /**
        Вывод массива на экран
    **/
    void OutArray(int* Arr, unsigned n, IncOut Out)
    {
        for (int i = 0; i < n; i++)
            Out(Arr[i], i);
    }

    /**
        Выбор диапозона значений
    **/
    int* FixArray(int* Arr, unsigned n, IncOut Fix)
    {
        int min, max;
        cout << "Минимально возможное значение - ";
        cin >> min;
        cout << "Максимально возможное значение - ";
        cin >> max;

        for (int i = 0; i < n; i++)
            Arr[i] = Fix(min, max);

        return Arr;
    }

    /**
        Ввод эл. массива
    **/
    int* EnterArray(int* Arr, unsigned n, IncOut Ent)
    {
        int y = 0;

        for (int i = 0; i < n; i++)
            Arr[i] = Ent(i, y);

        return Arr;
    }

    /**
        Cоздание матрицы
    **/
    int** makeMatrix(unsigned Row, unsigned Col)
    {
        int** Arr = new int* [Row];
        for(int i = 0; i < Row; i++)
        {
            Arr[i] = new int[Col];
        }
        return Arr;
    }

    /**
        Инициализация матрицы
    **/
    int** initMatrix(int** Arr, unsigned Row, unsigned Col, IncOut init)
    {
        for(int i = 0; i < Row; i++)
            for(int j = 0; j < Col; j++)
            {
                Arr[i][j] = init(0, 0);
            }
        return Arr;
    }

    /**
        Удаление матрицы
    **/
    int** delMatrix(int** Arr, int Row, int Col)
    {
        for(int i = 0; i < Row; i++)
        {
            delete[] Arr[i];
        }
        delete[] Arr;

        return Arr;
    }





















