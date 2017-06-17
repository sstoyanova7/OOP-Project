#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#include "Submatrix.h"


template <typename T>
Submatrix<T>::Submatrix(const Vectors<T>* arr, unsigned size):Matrices<T>(arr,size){} //�����������

template <typename T>
Submatrix<T>::Submatrix():Matrices<T>::Matrices(){} //����������� �� ������������

template <typename T>
Submatrix<T>::Submatrix(Matrices<T> matrix, unsigned row1, unsigned column1, unsigned row2, unsigned column2) //�����������
{
    if(row1 > row2)             //��� ������� ����� ������
    {                           //� ����� ������ ���
        unsigned tmp = row1;
        row1 = row2;
        row2 = tmp;
    }
    if(column1 > column2)       //��� ������� ����� �������
    {                           //� ����� ������ ������
        unsigned tmp = column1;
        column1 = column2;
        column2 = tmp;
    }

    // ��� �� �������� �� ������� ���, ����� �� � �� ���������
    if(row1 < 0)
    {
        cout << "������ ��� ���������� ���!";
        row1 = 0;
    }
    if(column1 < 0)
    {
        column1 = 0;
        cout << "������ ��� ���������� ������!";
    }
    if(row2 >= matrix.get_num_rows())
    {
        cout << "������ ��� ���������� ���!";
        row2 = matrix.get_num_rows();
    }
    if(column2 >= matrix.get_num_columns())
    {
        cout << "������ ��� ���������� ������!";
        row2 = matrix.get_num_columns();
    }

    unsigned num_columns = column2 - column1 + 1;  //���� �� �������� �� ������������
    unsigned num_rows = row2 - row1 + 1;           //���� �� �������� �� ������������
    T* array = new T[num_columns];                 //��������� ����� �� ����� �� ���������� ��� � ������ = ���� �� ��������
    Vectors<T> tmpV(array, num_columns);           //��������� ������
    Vectors<T>* tmpArr = new Vectors<T>[num_rows]; //��������� ����� �� ������� � ������ = ���� �� ��������
    for(int i = 0; i < num_rows; i++)              //� �� ��������� � ���� ���������� ������
        tmpArr[i] = tmpV;                          //�� �� �������� ������ ������ �� �� � ��������� ���� ����������
    Submatrix<T> tmpM(tmpArr, num_rows);           //��������� ����������
    tmpM.set_num_columns(num_columns);             //�������� ���� �� �������� �� ������������

    for(int i = row1, k = 0; i <= row2; i++, k++)   //������� ��������� �� i-��� �� j-��� ���
        for(int j = column1, p = 0; j <=  column2; j++, p++)    //������� ��������� �� i-���� �� j-���� ������
            tmpM[k][p] = matrix[i][j];              //������� � ������������
    *this = tmpM;
}

template <typename T>
Submatrix<T>::Submatrix(const Matrices<T> other)    //���� ����������� � �������
{
    (Matrices<T>&)*this = other;
}

template <typename T>
Submatrix<T>& Submatrix<T>::operator=(const Matrices<T> other) //�������� = � �������
{
    (Matrices<T>&)*this = other;
}

template <typename T>
Submatrix<T>::Submatrix(const Cursor<T> other)  //���� ����������� � ������
{
    (Matrices<T>&)*this = (Matrices<T>&)other;
}

template <typename T>
Submatrix<T>& Submatrix<T>::operator=(const Cursor<T> other) //�������� = � ������
{
    (Matrices<T>&)*this = (Matrices<T>&)other;
}
