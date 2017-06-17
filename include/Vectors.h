#ifndef VECTORS_H
#define VECTORS_H

#include "Matrices.h"
template <typename T>
class Matrices;


template <typename T>
class Vectors
{
private:
    T* vector;
    unsigned size;
public:
    Vectors();
    Vectors(T*, unsigned);
    ~Vectors();
    Vectors(const Vectors<T>&);
    Vectors<T>& operator=(const Vectors<T>&);

    unsigned get_size()const;
    void set_size(unsigned);

    //������ �� ���� � �����
    template <typename T1>
    friend istream& operator >>(istream&, Vectors<T1>&);

    template <typename T1>
    friend ostream& operator <<(ostream&, const Vectors<T1>&);

    //�������� �� �������� � ��������� �� �������
    Vectors<T> operator+(const Vectors<T>&);
    Vectors<T>& operator+=(const Vectors<T>&);
    Vectors<T> operator-(const Vectors<T>&);
    Vectors<T>& operator-=(const Vectors<T>&);

    //�������� �� ��������, ���������, ��������� � ������� �� ������ � �����
    Vectors<T> operator+(double);
    Vectors<T>& operator+=(double);
    Vectors<T> operator-(double);
    Vectors<T>& operator-=(double);
    Vectors<T> operator*(double);
    Vectors<T>& operator*=(double);
    Vectors<T> operator/(double);
    Vectors<T>& operator/=(double);

    //�������� �� ������ �� ��������
    T& operator[](int);

    //�������� �� �������� ������������ �� �������
    double operator*(const Vectors<T>&);

    //�������� �� �������� ������������ �� �������
    Vectors<T> operator^(const Vectors<T>&);
    Vectors<T>& operator^=(const Vectors<T>&);

    //�������� �� ������������� �� ������
    Vectors<T> operator!();

    //�������� �� ��������� �� ������ � �������
    Vectors<T> operator*(const Matrices<T>&);
    Vectors<T>& operator*=(const Matrices<T>&);
};

#endif // VECTORS_H
