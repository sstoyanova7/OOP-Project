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

    //потоци за вход и изход
    template <typename T1>
    friend istream& operator >>(istream&, Vectors<T1>&);

    template <typename T1>
    friend ostream& operator <<(ostream&, const Vectors<T1>&);

    //операции за събиране и изваждане на вектори
    Vectors<T> operator+(const Vectors<T>&);
    Vectors<T>& operator+=(const Vectors<T>&);
    Vectors<T> operator-(const Vectors<T>&);
    Vectors<T>& operator-=(const Vectors<T>&);

    //операции за събиране, изваждане, умножение и деление на вектор с число
    Vectors<T> operator+(double);
    Vectors<T>& operator+=(double);
    Vectors<T> operator-(double);
    Vectors<T>& operator-=(double);
    Vectors<T> operator*(double);
    Vectors<T>& operator*=(double);
    Vectors<T> operator/(double);
    Vectors<T>& operator/=(double);

    //операция за достъп до елементи
    T& operator[](int);

    //операция за скаларно произведение на вектори
    double operator*(const Vectors<T>&);

    //операция за векторно произведение на вектори
    Vectors<T> operator^(const Vectors<T>&);
    Vectors<T>& operator^=(const Vectors<T>&);

    //операция за нормализиране на вектор
    Vectors<T> operator!();

    //операция за умножение на вектор с матрица
    Vectors<T> operator*(const Matrices<T>&);
    Vectors<T>& operator*=(const Matrices<T>&);
};

#endif // VECTORS_H
