#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#include "Submatrix.h"


template <typename T>
Submatrix<T>::Submatrix(const Vectors<T>* arr, unsigned size):Matrices<T>(arr,size){} //конструктор

template <typename T>
Submatrix<T>::Submatrix():Matrices<T>::Matrices(){} //конструктор по подразбиране

template <typename T>
Submatrix<T>::Submatrix(Matrices<T> matrix, unsigned row1, unsigned column1, unsigned row2, unsigned column2) //конструктор
{
    if(row1 > row2)             //ако въведем първо долния
    {                           //и после горния ред
        unsigned tmp = row1;
        row1 = row2;
        row2 = tmp;
    }
    if(column1 > column2)       //ако въведем първо дясната
    {                           //и после лявата колона
        unsigned tmp = column1;
        column1 = column2;
        column2 = tmp;
    }

    // ако се опитваме да въведем ред, който не е от матрицата
    if(row1 < 0)
    {
        cout << "Въвели сте некоректен ред!";
        row1 = 0;
    }
    if(column1 < 0)
    {
        column1 = 0;
        cout << "Въвели сте некоректна колона!";
    }
    if(row2 >= matrix.get_num_rows())
    {
        cout << "Въвели сте некоректен ред!";
        row2 = matrix.get_num_rows();
    }
    if(column2 >= matrix.get_num_columns())
    {
        cout << "Въвели сте некоректна колона!";
        row2 = matrix.get_num_columns();
    }

    unsigned num_columns = column2 - column1 + 1;  //броя на колоните на субматрицата
    unsigned num_rows = row2 - row1 + 1;           //боря на редовете на субматрицата
    T* array = new T[num_columns];                 //създаваме масив от числа от произволен тип с размер = броя на колоните
    Vectors<T> tmpV(array, num_columns);           //създаваме вектор
    Vectors<T>* tmpArr = new Vectors<T>[num_rows]; //създаваме масив от вектори с размер = броя на редовете
    for(int i = 0; i < num_rows; i++)              //и го запълваме с вече създадения вектор
        tmpArr[i] = tmpV;                          //за да направим всички редове да са с правилния брой координати
    Submatrix<T> tmpM(tmpArr, num_rows);           //създаваме субматрица
    tmpM.set_num_columns(num_columns);             //задаваме броя на колоните на субматрицата

    for(int i = row1, k = 0; i <= row2; i++, k++)   //обхожда матрицата от i-тия до j-тия ред
        for(int j = column1, p = 0; j <=  column2; j++, p++)    //обхожда матрицата от i-тата до j-тата колона
            tmpM[k][p] = matrix[i][j];              //записва в субматрицата
    *this = tmpM;
}

template <typename T>
Submatrix<T>::Submatrix(const Matrices<T> other)    //копи конструктор с матрица
{
    (Matrices<T>&)*this = other;
}

template <typename T>
Submatrix<T>& Submatrix<T>::operator=(const Matrices<T> other) //оператор = с матрица
{
    (Matrices<T>&)*this = other;
}

template <typename T>
Submatrix<T>::Submatrix(const Cursor<T> other)  //копи конструктор с курсор
{
    (Matrices<T>&)*this = (Matrices<T>&)other;
}

template <typename T>
Submatrix<T>& Submatrix<T>::operator=(const Cursor<T> other) //оператор = с курсор
{
    (Matrices<T>&)*this = (Matrices<T>&)other;
}
