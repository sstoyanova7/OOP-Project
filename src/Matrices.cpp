#include <iostream>
#include <cstring>
using namespace std;
#include "Matrices.h"

template <typename T>
Matrices<T>::Matrices():matrix(NULL),num_rows(0), num_columns(0){} //����������� �� ������������

template <typename T>
Matrices<T>::Matrices(const Vectors<T>* matrix, unsigned num_rows) //�����������
{
    if(matrix == NULL)
    {
        this -> num_rows = 0;
        num_columns = 0;
        this -> matrix = NULL;
    }
    else
    {
        num_columns = matrix[0].get_size();
        this -> num_rows = num_rows;
        this -> matrix = new Vectors<T> [num_rows];
        bool flag = 1;
        for(int i = 0; i < num_rows && flag; i++)
        {
            if(matrix[i].get_size() != num_columns)
                flag = 0;
            else
                this -> matrix[i] = matrix[i];
        }
        if(flag == 0)
        {
            cout << "�������� �� � �������� ���� ��������!";
            delete [] this -> matrix;
            this -> num_rows = 0;
            num_columns = 0;
            this -> matrix = NULL;
        }
    }
}

template <typename T>
Matrices<T>::~Matrices()    //����������
{
    delete []matrix;
}

template <typename T>
Matrices<T>::Matrices(const Matrices<T>& other) //���� �����������
{
    num_rows = other.num_rows;
    num_columns = other.num_columns;
    if(other.matrix == NULL)
        matrix = NULL;
    else
    {
        matrix = new Vectors<T> [num_rows];
        for(int i = 0; i < num_rows; i++)
            matrix[i] = other.matrix[i];
    }
}

template <typename T>
Matrices<T>& Matrices<T>::operator=(const Matrices<T>& other) //�������� =
{
    if(this == &other)
        return *this;
    num_rows = other.num_rows;
    num_columns = other.num_columns;
    if(matrix != NULL)
        delete []matrix;
    if(other.matrix == NULL)
        matrix = NULL;
    else
    {
        matrix = new Vectors<T> [num_rows];
        for(int i = 0; i < num_rows; i++)
            matrix[i] = other.matrix[i];
    }
    return *this;
}

template <typename T>
Matrices<T>::Matrices(const Submatrix<T> other):Matrices((Matrices<T>&)other){} //���� ����������� ��� ����������

template <typename T>
Matrices<T>& Matrices<T>::operator=(const Submatrix<T> other) //�������� = ��� ����������
{
    *this = (Matrices<T>&)other;
}

template <typename T>
Matrices<T>::Matrices(const Cursor<T> other):Matrices((Matrices<T>&)other){} //���� ����������� � ������

template <typename T>
Matrices<T>& Matrices<T>::operator=(const Cursor<T> other) //�������� = � ������
{
    *this = (Matrices<T>&)other;
}

template <typename T>
void Matrices<T>::set_num_columns(unsigned num_columns)
{
    this->num_columns = num_columns;
}

template <typename T>
void Matrices<T>::set_num_rows(unsigned num_rows)
{
    this->num_rows = num_rows;
}

template <typename T>
unsigned Matrices<T>::get_num_columns()const
{
    return num_columns;
}

template <typename T>
unsigned Matrices<T>::get_num_rows()const
{
    return num_rows;
}

//������ �� ���� � �����
template <typename T1>
istream& operator >>(istream& is, Matrices<T1>& object)
{
    if(object.matrix != NULL)
    {
        delete []object.matrix;
        object.matrix = NULL;
    }
    //�������� �� ������������� �� ���������
    cout <<"�������� ���� ������ �� ���������: ";
    is >> object.num_rows;
    cout << "�������� ���� ������ �� ���������: ";
    is >> object.num_columns;

    //�������� ����� �� ���������
    T1* array = new T1[object.num_columns];
    Vectors<T1> tmpV(array, object.num_columns);
    Vectors<T1>* tmpArr = new Vectors<T1>[object.num_rows];
    for(int i = 0; i < object.num_rows; i++)
        tmpArr[i] = tmpV;
    Matrices<T1> tmpM(tmpArr, object.num_rows);
    tmpM.num_columns = object.num_columns;
    object = tmpM;

    //��������� ���������� �� ��������
    cout << "�������� ���������� �� ��������� ";
    for(int i = 0; i < object.num_rows; i++)
        for(int j = 0; j < object.num_columns; j++)
            is >> object[i][j];
    return is;
}

template <typename T1>
ostream& operator <<(ostream& os, const Matrices<T1>& object)
{
    for(int i = 0; i < object.num_rows; i++) //������� ��������
    {
        os << object.matrix[i];     //������� �������
        if(i < object.num_rows - 1)
            os << endl;
    }
    return os;
}

//�������� �� �������� � ��������� �� �������
template <typename T>
Matrices<T> Matrices<T>::operator+(const Matrices<T>& other)
{
    Matrices<T> tmp = *this;
    tmp+=other;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator+=(const Matrices<T>& other)
{
    //�������� �� �������������
    if(num_rows != other.num_rows || num_columns != other.num_columns)
    {
        cout << "����� ������� �� � �������� �����������!" << endl;
        return *this;
    }
    for(int i = 0; i < num_rows; i++)
            matrix[i] += other.matrix[i];
    return *this;
}

template <typename T>
Matrices<T> Matrices<T>::operator-(const Matrices<T>& other)
{
    Matrices<T> tmp = *this;
    tmp-=other;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator-=(const Matrices<T>& other)
{
    //�������� �� �������������
    if(num_rows != other.num_rows || num_columns != other.num_columns)
    {
        cout << "����� ������� �� � �������� �����������!" << endl;
        return *this;
    }
    for(int i = 0; i < num_rows; i++)
            matrix[i] -= other.matrix[i];
    return *this;
}

//�������� �� �������� � ��������� �� ����� ��� ������ �������� �� ���������
template <typename T>
Matrices<T> Matrices<T>::operator+(double num)  //�������� �� ����� ��� ������ �������� �� ���������
{
    Matrices<T> tmp = *this;
    tmp+=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator+=(double num) //�������� �� ����� ��� ������ �������� �����������
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] += num;
    return *this;
}

template <typename T>
Matrices<T> Matrices<T>::operator-(double num)      //��������� �� ����� �� ������ �������� �� ���������
{
    Matrices<T> tmp = *this;
    tmp-=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator-=(double num)    //��������� �� ����� �� ������ �������� �� ���������
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] -= num;
    return *this;
}

//�������� �� ��������� �� �������
template <typename T>
Matrices<T> Matrices<T>::operator*(const Matrices<T>& other)
{
    //�������� �� �������������
    if(num_columns != other.num_rows)
    {
        cout << "����� ������� �� ����� �� �� �������!" << endl;
        return *this;
    }

    Matrices<T> product; //��������� �������
    product.num_rows = this -> num_rows;
    product.num_columns = other.num_columns;
    product.matrix = new Vectors<T>[product.num_rows];
    double arrvector[product.num_columns];
    Vectors<T> vector(arrvector, product.num_columns);
    Matrices<T> tmp = other;
    ~tmp;
    for(int i = 0; i < product.num_rows; i++)
    {
        product[i] = vector;
        for(int j = 0; j < product.num_columns; j++)
            product[i][j] = matrix[i]*tmp.matrix[j];
    }
    return product;
}

template <typename T>
Matrices<T>& Matrices<T>::operator*=(const Matrices<T>& other)
{
    *this = *this*other;
    return *this;
}

//�������� �� ��������� �� ������� � ������
template <typename T>
Matrices<T> Matrices<T>::operator*(const Vectors<T>& other)
{
    Matrices<T> tmp = *this;
    tmp*=other;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator*=(const Vectors<T>& other)
{
    Vectors<T> arr[1];      //��������� ����� �� 1������
    arr[0] = other;         //��������� ������� � ������
    Matrices<T> tmp(arr, 1);  //��������� ������� �� ������
    ~tmp;                       //������������� ���������
    *this*=tmp;     //���������� ����� �������
    return *this;
}

//�������� �� ��������� � ������� �� ������� � �����
template <typename T>
Matrices<T> Matrices<T>::operator*(double num)      //��������� �� ������ �������� �� ��������� � �����
{
    Matrices<T> tmp = *this;
    tmp*=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator*=(double num)    //�������� �� ������ �������� �� ��������� � �����
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] *= num;
    return *this;
}

template <typename T>
Matrices<T> Matrices<T>::operator/(double num)      //������� �� ������ �������� �� ��������� � �����
{
    Matrices<T> tmp = *this;
    tmp/=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator/=(double num)    //������� �� ������ �������� �� ��������� � �����
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] /= num;
    return *this;
}

//�������� �� ������ �� ��������
template <typename T>
Vectors<T>& Matrices<T>::operator[](int num)
{
    //�������� ���� ������� � ����� ����� ����������
    if(num >= num_rows)
    {
        cout <<"������������� �������!"<<endl;
        return matrix[num_rows - 1];
    }
    if(num < 0)
    {
        cout <<"������������� �������!"<<endl;
        return matrix[0];
    }
    //������� ��������
    return matrix[num];
}

//�������� �� ������������� �� �������
template <typename T>
Matrices<T> Matrices<T>::operator~()
{
    Matrices<T> tmp;            //��������� ���� �������
    tmp.num_rows = num_columns; //�������� ���� ������ �� ������ �������
    tmp.num_columns = num_rows; //�������� ���� ������ �� ������ �������
    tmp.matrix = new Vectors<T>[tmp.num_rows]; //�������� ����� �� ������ �������
    double vector[tmp.num_columns];
    Vectors<T> tmpvec(vector, tmp.num_columns);
    for(int i = 0; i < tmp.num_rows; i++)
    {
        tmp[i] = tmpvec;
        for(int j = 0; j < tmp.num_columns; j++)
            tmp[i][j] = matrix[j][i];
    }
    *this = tmp;
    return *this;
}

//������� ������� �� det()
template <typename T>
Matrices<T> Matrices<T>::help_det(int column)               //���� ��� � ������ �� ���������
{
    T* array = new T[num_rows - 1];                         //��������� ����� �� �����
    Vectors<T> tmpV(array, num_rows - 1);                   //��������� ������ � ����������� �� �������
    Vectors<T>* tmpArr = new Vectors<T>[num_rows - 1];      //��������� ����� �� �������
    for(int i = 0; i < num_rows - 1; i++)                   //��������� ������ �� ������� ��� ���� ���������� ������(������ �����������)
        tmpArr[i] = tmpV;
    Matrices<T> tmpM(tmpArr, num_rows - 1);                 //��������� ������� � ������������ �� �������
    tmpM.num_columns = num_columns - 1;                     //�������� ���� ������ �� ���������

    for(int i = 1; i < num_rows; i++)                       //������� ���������� ������� ��� ������ ��� � ��������, � ����� �����
        for(int j = 0, k = 0; j < num_rows; j++)            //��� ������
            if(j != column)
            {
                tmpM[i-1][k] = (*this)[i][j];
                k++;
            }
    return tmpM;
}

//�������� �� ������������ �� �������
template <typename T>
double Matrices<T>::det()
{
    if(num_rows != num_columns)
    {
        cout << "��������� �� � ���������!" << endl;
        return 0;
    }
    double determinant = 0;
    if(num_rows == 1)               //��� ��������� � 1�1
        return (*this)[0][0];
    if(num_rows == 2)               //��� ��������� � 2�2
        return (*this)[0][0]*(*this)[1][1] - (*this)[0][1]*(*this)[1][0];
    if(num_rows == 3)               //��� ��������� � 3�3
    {
        double a = (*this)[0][0]*(*this)[1][1]*(*this)[2][2] +      //�������������
                   (*this)[0][1]*(*this)[1][2]*(*this)[2][0] +
                   (*this)[0][2]*(*this)[1][0]*(*this)[2][1];

        double b = (*this)[0][2]*(*this)[1][1]*(*this)[2][0] +      //�������������
                   (*this)[0][1]*(*this)[1][0]*(*this)[2][2] +
                   (*this)[0][0]*(*this)[1][2]*(*this)[2][1];
        return a-b;
    }
                    //��� ��������� � 4�4 ��� ��-������
    for(int i = 0; i < num_rows; i++)
    {
        Matrices<T> tmp = this->help_det(i);        //��������� �� ����� ���
        if(i%2 == 1)                                //��� ����������� � �����������
            determinant-=((*this)[0][i]*tmp.det());
        else                                        //��� ����������� � �����������
            determinant+=((*this)[0][i]*tmp.det());

    }
    return determinant;
}

//�������� �� ������� �� ������� �������
template <typename T>
Matrices<T> Matrices<T>::operator!()
{
    if((*this).det() == 0)                       //����������� ���� ��������� � �������� (det != 0)
    {
        cout << "��������� �� � ��������!" << endl;
        return *this;
    }

    Matrices<T> result = *this;                //��������� ������� ������ ���� ����������
    for(int i = 0; i < result.num_rows; i++)   //������ ����������� ������� �������� �������
        for(int j = 0; j < result.num_columns; j++)
        {
            if(i == j)
                result[i][j] = 1;
            else
                result[i][j] = 0;
        }
    Matrices<T> tmp = *this;              //��������� ������� ������ ���� ����������

    bool flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i < result.num_rows; i++)
            if(tmp[i][i] == 0)              //����������� ���� ��� ���� �� ������� ��������
            {                               //� ��� ��� ������ ���� = 1
                flag = 1;
                for(int j = 0; j < result.num_rows; j++) //������ ���, � ����� �� i-���� ������ ���� 0
                {
                    if(tmp[j][i]!=0)            //������ ���, � ����� �� i-���� ������ ���� 0
                    {
                        Vectors<T> copy = tmp[i];       //��������� i-��� ��� � j-���
                        tmp[i] = tmp[j];
                        tmp[j] = copy;
                        break;
                    }
                }
            }
    }

    for(int i = 0; i < num_rows; i++)
    {
        result[i]/=tmp[i][i];           //����������� ������� � tmp|result
        tmp[i]/=tmp[i][i];
        for(int j = 0; j< num_rows; j++)
            if(i!=j)
            {
                result[j] = result[j] - result[i]*tmp[j][i];
                tmp[j] = tmp[j] - tmp[i]*tmp[j][i];
            }
    }
    return result;
}


