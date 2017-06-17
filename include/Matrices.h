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
    Matrices<T> help_det(int); //трие ред и колона
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

    //потоци за вход и изход
    template <typename T1>
    friend istream& operator >> (istream&, Matrices<T1>&);
    template <typename T1>
    friend ostream& operator << (ostream&, const Matrices<T1>&);

    //операции за събиране и изваждане на матрици
    Matrices<T> operator+(const Matrices<T>&);
    Matrices<T>& operator+=(const Matrices<T>&);
    Matrices<T> operator-(const Matrices<T>&);
    Matrices<T>& operator-=(const Matrices<T>&);

    //операции за добавяне и изваждане на число към всички елементи на матрицата
    Matrices<T> operator+(double);
    Matrices<T>& operator+=(double);
    Matrices<T> operator-(double);
    Matrices<T>& operator-=(double);

    //операции за умножение на матрици
    Matrices<T> operator*(const Matrices<T>&);
    Matrices<T>& operator*=(const Matrices<T>&);

    //операции за умножение на матрица с вектор
    Matrices<T> operator*(const Vectors<T>&);
    Matrices<T>& operator*=(const Vectors<T>&);

    //операции за умножение и деление на матрица с число
    Matrices<T> operator*(double);
    Matrices<T>& operator*=(double);
    Matrices<T> operator/(double);
    Matrices<T>& operator/=(double);

    //операция за достъп до елементи
    Vectors<T>& operator[](int);

    //операция за транспониране на матрица
    Matrices<T> operator~();

    //намиране на детерминанта на матрица
    double det();

    //операция за намране на обратна матрица
    Matrices<T> operator!();
};

#endif // MATRICES_H
