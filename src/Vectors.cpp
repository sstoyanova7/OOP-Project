#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#include "Vectors.h"


template <typename T>
Vectors<T>::Vectors(): vector(NULL), size(0){}  //конструктор по подразбиране

template <typename T>
Vectors<T>::Vectors(T* vector, unsigned size)   //конструктор
{
    this -> vector = new T [size];
    for(int i = 0; i < size; i++)
        this -> vector[i] = vector[i];
    this -> size = size;
}

template <typename T>       //деструктор
Vectors<T>::~Vectors()
{
    delete []vector;
}

template <typename T>
Vectors<T>::Vectors(const Vectors<T>& other)  //копи конструктор
{
    size = other.size;
    if(other.vector == NULL)
        vector = NULL;
    else
    {
        vector = new T [size];
        for(int i = 0; i < size; i++)
            vector[i] = other.vector[i];
    }
}

template <typename T>
Vectors<T>& Vectors<T>::operator=(const Vectors<T>& other) //оператор =
{
    if(this == &other)
        return *this;
    size = other.size;
    if(vector != NULL)
        delete []vector;
    if(other.vector == NULL)
        vector = NULL;
    else
    {
        vector = new T [size];
        for(int i = 0; i < size; i++)
            vector[i] = other.vector[i];
    }
    return *this;
}

template <typename T>
unsigned Vectors<T>::get_size()const
{
    return size;
}

template <typename T>
void Vectors<T>::set_size(unsigned size)
{
    this->size = size;
}

//потоци за вход и изход
template <typename T1>
istream& operator >>(istream& is, Vectors<T1>& object)
{
    if(object.vector != NULL)
    {
        delete []object.vector;
        object.vector = NULL;
    }
    cout << "Въведете размерност: ";
    is >> object.size;
    cout << "Въведете вектор: ";
    object.vector = new T1[object.size];    //заделяме памет
    for(int i = 0; i < object.size; i++)
        is >> object[i];        //въвежда
    return is;
}

template <typename T1>
ostream& operator <<(ostream& os, const Vectors<T1>& object)
{
    os << "(";
    for(int i = 0; i < object.size; i++)    //обхожда вектора
    {
        os << object.vector[i];         //извежда елемента
        if(i < object.size - 1)
            os << ", ";
    }
    os << ")";
    return os;
}

//операции за събиране и изваждане на вектори
template <typename T>
Vectors<T> Vectors<T>::operator+(const Vectors<T>& other)
{
    Vectors tmp = *this;
    tmp+=other;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator+=(const Vectors<T>& other)
{
    if(size != other.size)      //проверка за размерността
    {
        cout << "Двата вектора са с различни размерности!" << endl;
        return *this;
    }
    for(int i = 0; i < size; i++)
        vector[i] += other.vector[i];
    return *this;
}

template <typename T>
Vectors<T> Vectors<T>::operator-(const Vectors<T>& other)
{
    Vectors<T> tmp = *this;
    tmp-=other;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator-=(const Vectors<T>& other)
{
    if(size != other.size)          //проверка за размерността
    {
        cout << "Двата вектора са с различни размерности!" << endl;
        return *this;
    }
    for(int i = 0; i < size; i++)
        vector[i] -= other.vector[i];
    return *this;
}

//операции за събиране, изваждане, умножение и деление на вектор с число
template <typename T>
Vectors<T> Vectors<T>::operator+(double num)
{
    Vectors<T> tmp = *this;
    tmp+=num;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator+=(double num)
{
    for(int i = 0; i < size; i++)
        vector[i] += num;       //прибавя числото към всички елементи на вектора
    return *this;
}

template <typename T>
Vectors<T> Vectors<T>::operator-(double num)
{
    Vectors<T> tmp = *this;
    tmp-=num;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator-=(double num)
{
    for(int i = 0; i < size; i++)
        vector[i] -= num;       //изважда числото от всички елементи на вектора
    return *this;
}

template <typename T>
Vectors<T> Vectors<T>::operator*(double num)
{
    Vectors<T> tmp = *this;
    tmp*=num;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator*=(double num)
{
    for(int i = 0; i < size; i++)
        vector[i] *= num;       //умноцава всеки елемент на вектора с числото
    return *this;
}

template <typename T>
Vectors<T> Vectors<T>::operator/(double num)
{
    Vectors<T> tmp = *this;
    tmp/=num;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator/=(double num)
{
    for(int i = 0; i < size; i++)
        vector[i] /= num;       //дели всеки елемент на ветора с числото
    return *this;
}

//операция за достъп до елементи
template <typename T>
T& Vectors<T>::operator[](int num)
{
    // ако се подаде номер, на елемент, който не съществува
    if(num >= size)
    {
        cout <<"Несъществуващ елемент!" <<endl;
        return vector[size - 1];
    }
    if(num < 0)
    {
        cout <<"Несъществуващ елемент!" << endl;
        return vector[0];
    }
    //ако номера е коректен връща елемента
    return vector[num];
}

//операция за скаларно произведение на вектори
template <typename T>
double Vectors<T>::operator*(const Vectors<T>& other)
{
    if(size != other.size) //проверка дали двата вектора са с еднаъв размер
    {
        cout << "Векторите са с различни размерности!" << endl;
        return 0;
    }
    double a = 0; //резултата
    for(int i = 0; i < size; i++)
    {
        a+=vector[i]*other.vector[i];
    }
    return a;
}

//операция за векторно произведение на вектори
template <typename T>
Vectors<T> Vectors<T>::operator^(const Vectors<T>& other)
{
    if(size != 3 || other.size != 3) //ако размерността, на някой от двата вектора е различна от 3
    {
        cout << "Векторите не са тримерни!";
        return *this;
    }
    Vectors<T> tmp = *this;
    tmp.vector[0] = vector[1]*other.vector[2] - vector[2]*other.vector[1];      //пресмята координатите на новия вектор
    tmp.vector[1] = vector[2]*other.vector[0] - vector[0]*other.vector[2];
    tmp.vector[2] = vector[0]*other.vector[1] - vector[1]*other.vector[0];
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator^=(const Vectors<T>& other)
{
    *this = *this^other;
    return *this;
}

 //операция за нормализиране на вектор
template <typename T>
Vectors<T> Vectors<T>::operator!()
{
    double length = 0;
    for(int i = 0; i < size; i++)
        length+= vector[i]*vector[i];   //намира сбора на квадратите на координатите
    length = sqrt(length);              // намира дължината на вектора
    if(length != 0)
        *this /= length;
    return *this;
}

 //операция за умножение на вектор с матрица
template <typename T>
Vectors<T> Vectors<T>::operator*(const Matrices<T>& other)
{
    Vectors<T> tmp = *this;
    tmp*=other;
    return tmp;
}

template <typename T>
Vectors<T>& Vectors<T>::operator*=(const Matrices<T>& other)
{
    Vectors<T> arr[1];      //създаваме масив от 1 вектор
    arr[0] = *this;         //записваме вектора в създадения масив
    Matrices<T> tmp(arr, 1);    //създаваме матрица с 1 редЦ(по масива)
    tmp*=other;         //умножаваме двете матрици
    *this = tmp[0];
    return *this;
}
