#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#include "Vectors.h"


template <typename T>
Vectors<T>::Vectors(): vector(NULL), size(0){}  //����������� �� ������������

template <typename T>
Vectors<T>::Vectors(T* vector, unsigned size)   //�����������
{
    this -> vector = new T [size];
    for(int i = 0; i < size; i++)
        this -> vector[i] = vector[i];
    this -> size = size;
}

template <typename T>       //����������
Vectors<T>::~Vectors()
{
    delete []vector;
}

template <typename T>
Vectors<T>::Vectors(const Vectors<T>& other)  //���� �����������
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
Vectors<T>& Vectors<T>::operator=(const Vectors<T>& other) //�������� =
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

//������ �� ���� � �����
template <typename T1>
istream& operator >>(istream& is, Vectors<T1>& object)
{
    if(object.vector != NULL)
    {
        delete []object.vector;
        object.vector = NULL;
    }
    cout << "�������� ����������: ";
    is >> object.size;
    cout << "�������� ������: ";
    object.vector = new T1[object.size];    //�������� �����
    for(int i = 0; i < object.size; i++)
        is >> object[i];        //�������
    return is;
}

template <typename T1>
ostream& operator <<(ostream& os, const Vectors<T1>& object)
{
    os << "(";
    for(int i = 0; i < object.size; i++)    //������� �������
    {
        os << object.vector[i];         //������� ��������
        if(i < object.size - 1)
            os << ", ";
    }
    os << ")";
    return os;
}

//�������� �� �������� � ��������� �� �������
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
    if(size != other.size)      //�������� �� ������������
    {
        cout << "����� ������� �� � �������� �����������!" << endl;
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
    if(size != other.size)          //�������� �� ������������
    {
        cout << "����� ������� �� � �������� �����������!" << endl;
        return *this;
    }
    for(int i = 0; i < size; i++)
        vector[i] -= other.vector[i];
    return *this;
}

//�������� �� ��������, ���������, ��������� � ������� �� ������ � �����
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
        vector[i] += num;       //������� ������� ��� ������ �������� �� �������
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
        vector[i] -= num;       //������� ������� �� ������ �������� �� �������
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
        vector[i] *= num;       //�������� ����� ������� �� ������� � �������
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
        vector[i] /= num;       //���� ����� ������� �� ������ � �������
    return *this;
}

//�������� �� ������ �� ��������
template <typename T>
T& Vectors<T>::operator[](int num)
{
    // ��� �� ������ �����, �� �������, ����� �� ����������
    if(num >= size)
    {
        cout <<"������������� �������!" <<endl;
        return vector[size - 1];
    }
    if(num < 0)
    {
        cout <<"������������� �������!" << endl;
        return vector[0];
    }
    //��� ������ � �������� ����� ��������
    return vector[num];
}

//�������� �� �������� ������������ �� �������
template <typename T>
double Vectors<T>::operator*(const Vectors<T>& other)
{
    if(size != other.size) //�������� ���� ����� ������� �� � ������ ������
    {
        cout << "��������� �� � �������� �����������!" << endl;
        return 0;
    }
    double a = 0; //���������
    for(int i = 0; i < size; i++)
    {
        a+=vector[i]*other.vector[i];
    }
    return a;
}

//�������� �� �������� ������������ �� �������
template <typename T>
Vectors<T> Vectors<T>::operator^(const Vectors<T>& other)
{
    if(size != 3 || other.size != 3) //��� ������������, �� ����� �� ����� ������� � �������� �� 3
    {
        cout << "��������� �� �� ��������!";
        return *this;
    }
    Vectors<T> tmp = *this;
    tmp.vector[0] = vector[1]*other.vector[2] - vector[2]*other.vector[1];      //�������� ������������ �� ����� ������
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

 //�������� �� ������������� �� ������
template <typename T>
Vectors<T> Vectors<T>::operator!()
{
    double length = 0;
    for(int i = 0; i < size; i++)
        length+= vector[i]*vector[i];   //������ ����� �� ���������� �� ������������
    length = sqrt(length);              // ������ ��������� �� �������
    if(length != 0)
        *this /= length;
    return *this;
}

 //�������� �� ��������� �� ������ � �������
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
    Vectors<T> arr[1];      //��������� ����� �� 1 ������
    arr[0] = *this;         //��������� ������� � ���������� �����
    Matrices<T> tmp(arr, 1);    //��������� ������� � 1 ����(�� ������)
    tmp*=other;         //���������� ����� �������
    *this = tmp[0];
    return *this;
}
