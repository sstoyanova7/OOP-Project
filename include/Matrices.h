#ifndef MATRICES_H
#define MATRICES_H

#include "Vectors.h"
#include "Submatrix.h"
#include "Cursor.h"

template <typename T>
class Vectors;

template <typename T>
class Submatrix;

template <typename T>
class Cursor;

template <typename T>
class Matrices
{
private:
    Vectors<T>* matrix;
    unsigned num_rows, num_columns;
    Matrices<T> help_det(int); //���� ��� � ������
public:
    Matrices();
    Matrices(const Vectors<T>*, unsigned);
    ~Matrices();
    Matrices(const Matrices<T>&);
    Matrices<T>& operator=(const Matrices<T>&);

    Matrices(const Submatrix<T>);
    Matrices<T>& operator=(const Submatrix<T>);

    Matrices(const Cursor<T>);
    Matrices<T>& operator=(const Cursor<T>);

    void set_num_columns(unsigned);
    void set_num_rows(unsigned);
    unsigned get_num_columns()const;
    unsigned get_num_rows()const;

    //������ �� ���� � �����
    template <typename T1>
    friend istream& operator >> (istream&, Matrices<T1>&);
    template <typename T1>
    friend ostream& operator << (ostream&, const Matrices<T1>&);

    //�������� �� �������� � ��������� �� �������
    Matrices<T> operator+(const Matrices<T>&);
    Matrices<T>& operator+=(const Matrices<T>&);
    Matrices<T> operator-(const Matrices<T>&);
    Matrices<T>& operator-=(const Matrices<T>&);

    //�������� �� �������� � ��������� �� ����� ��� ������ �������� �� ���������
    Matrices<T> operator+(double);
    Matrices<T>& operator+=(double);
    Matrices<T> operator-(double);
    Matrices<T>& operator-=(double);

    //�������� �� ��������� �� �������
    Matrices<T> operator*(const Matrices<T>&);
    Matrices<T>& operator*=(const Matrices<T>&);

    //�������� �� ��������� �� ������� � ������
    Matrices<T> operator*(const Vectors<T>&);
    Matrices<T>& operator*=(const Vectors<T>&);

    //�������� �� ��������� � ������� �� ������� � �����
    Matrices<T> operator*(double);
    Matrices<T>& operator*=(double);
    Matrices<T> operator/(double);
    Matrices<T>& operator/=(double);

    //�������� �� ������ �� ��������
    Vectors<T>& operator[](int);

    //�������� �� ������������� �� �������
    Matrices<T> operator~();

    //�������� �� ������������ �� �������
    double det();

    //�������� �� ������� �� ������� �������
    Matrices<T> operator!();
};

#endif // MATRICES_H
