#include <iostream>
#include <cstdlib>
using namespace std;
#include "Cursor.h"

template <typename T>
Cursor<T>::Cursor():Matrices<T>(){}         //конструктор по подразбиране

template <typename T>
Cursor<T>::Cursor(const Vectors<T>* arr, unsigned size):Matrices<T>(arr, size){}    //конструктор

template <typename T>
Cursor<T>::Cursor(const Matrices<T> other)      //копи конструктор с матрица
{
    (Matrices<T>&)*this = other;
}

template <typename T>
Cursor<T>& Cursor<T>::operator=(const Matrices<T> other)    //оператор = с матрица
{
    (Matrices<T>&)*this = other;
}

template <typename T>
Cursor<T>::Cursor(const Submatrix<T> other)         //копи конструктор със субматрица
{
    (Matrices<T>&)*this = (Matrices<T>&)other;
}

template <typename T>
Cursor<T>& Cursor<T>::operator=(const Submatrix<T> other)  //оператор = със субматрица
{
    (Matrices<T>&)*this = (Matrices<T>&)other;
}

//видове обхождания
template <typename T>
ostream& Cursor<T>::row_increase(ostream& os)
{
    for(int i = 0; i < this -> get_num_rows(); i++)              //обхожда редовете
        {
            os << "(";
            for(int j = 0; j < this -> get_num_columns(); j++)   //обхожда колоните
                {
                    if(j != this -> get_num_columns() - 1)
                        os << (*this)[i][j] << ", ";             //извежда елементите, без последния
                    else
                        os << (*this)[i][j] << ")" << endl;      // ако е последния елемент
                }
        }
    return os;
}

template <typename T>
ostream& Cursor<T>::row_decrease(ostream& os)
{
    for(int i = 0; i < this -> get_num_rows(); i++)                 //обхожда редовете
        {
            os << "(";
            for(int j = this -> get_num_columns() - 1; j >= 0; j--) //обхожда колоните
                {
                    if(j != 0)
                        os << (*this)[i][j] << ", ";                //извежда елементите, без последния
                    else
                       os << (*this)[i][j] << ")" << endl;           //извежда последния елемент
                }
        }
    return os;
}

template <typename T>
ostream& Cursor<T>::column_increase(ostream& os)
{
    unsigned num_rows = this -> get_num_rows(),
             num_columns = this -> get_num_columns();
    os << "(";
    for(int p = 0, i = 0, j = 0, k = 0; p < num_rows * num_columns; p++) //p определя колко пъти да се завърти цикъла
    {                                                                    //i, j определят елемента, който трябва да се изведе
        while(j >= num_columns)                                          //k определя от кой пореден елемент трябва
        {                                                                //да започне новия ред
            i++;
            j -= num_columns;
        }
        os << (*this)[i][j];
        if((p + 1) % num_columns != 0)
            os << ", ";
        j += num_rows;
        if((p + 1) % num_columns == 0)
        {
            os << ")" << endl;
            k++;
            i = 0;
            j = k;
        }
        if(p + 1 != num_rows * num_columns && (p + 1) % num_columns == 0)
            os << "(";
    }
    return os;
}

template <typename T>
ostream& Cursor<T>::column_decrease(ostream& os)
{
    unsigned num_rows = this -> get_num_rows(),
             num_columns = this -> get_num_columns();
    os << "(";
    for(int p = 0, i = 0, j = num_rows - 1, k = num_rows - 1; p < num_rows * num_columns; p++)  //р определя колко пъти да се завърти цикъла
    {                                                                                           //i, j определят елемента, който трябва да се изведе
        while(j >= num_columns)                                                                 //k определя от кой пореден елемент трябва
        {                                                                                       //да започне новия ред
            i++;
            j-= num_columns;
        }
        os << (*this)[i][j];
        if((p + 1) % num_columns != 0)
            os << ", ";
        j += num_rows;
        if((p + 1) % num_columns == 0)
        {
            os << ")" << endl;
            i = 0;
            k--;
            j = k;
        }
        if((p + 1) % num_columns == 0 && p + 1 != num_rows * num_columns)
            os << "(";
    }
    return os;
}

template <typename T1>
ostream& operator <<(ostream& os, Cursor<T1>& object)           //извеждане
{
    int choice;
    os << "Примери: 1:\n(1, 2, 3)\n(4, 5, 6)\n(7, 8, 9)\n\n"
                 <<"2:\n(3, 2, 1)\n(6, 5, 4)\n(9, 8, 7)\n\n"
                 <<"3:\n(1, 4, 7)\n(2, 5, 8)\n(3, 6, 9)\n\n"
                 <<"4:\n(3, 6, 9)\n(2, 5, 8)\n(1, 4, 7)\n\n";
    do
    {
        os << "Изберете начин на извеждане: ";
        cin >> choice;                  //въвежда номера на избрания пример,
    }while(choice < 1 || choice > 4);   //докато не се въведе м/у  1 и 4
    system("CLS");
    switch(choice)
    {
        case 1:
            {
               object.row_increase(os);
            }break;
        case 2:
            {
                object.row_decrease(os);
            }break;
        case 3:
            {
                object.column_increase(os);
            }break;
        case 4:
            {
                object.column_decrease(os);
            }break;
    }
    return os;
}

