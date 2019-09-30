 #ifndef MAKEARR_H
#define MAKEARR_H


#endif // MAKEARR_H

/**
    Инициализация и вывод массива
**/
using IncOut = int(*)(int, int);

/**
    Cоздание матрицы
**/
int** makeMatrix(unsigned Row, unsigned Col);

/**
    Инициализация матрицы
**/
int** initMatrix(int** Arr, unsigned Row, unsigned Col, IncOut init);
/**
    Удаление матрицы
**/
int** delMatrix(int** Arr, int Row, int Col);













/**
    Создание массива при помощи vector
**/
//vector<int> makeArray(unsigned n);

/**
    Выделение памяти для массива
**/
int* MakeArray(unsigned n);

/**
    Заполнение массива
**/
int* IncArray(int* Arr, unsigned n, IncOut Inc);

/**
    Вывод массива на экран
**/
void OutArray(int* Arr, unsigned n, IncOut Out);

/**
    Выбор диапозона значений
**/
int* FixArray(int* Arr, unsigned n, IncOut Fix);

/**
    Ввод эл. массива
**/
int* EnterArray(int* Arr, unsigned n, IncOut Ent);
