#ifndef CURSOR_H
#define CURSOR_H

#include "Matrices.h"
#include "Submatrix.h"

template <typename T>
class Cursor;

template <typename T>
class Submatrix;

template <typename T>
class Matrices;

template <typename T>
class Vectors;

template <typename T>
class Cursor:public Matrices<T>
{
private:
    //видове обхождания
    ostream& row_increase(ostream&);
    ostream& row_decrease(ostream&);
    ostream& column_increase(ostream&);
    ostream& column_decrease(ostream&);

public:
    Cursor();
    Cursor(const Vectors<T>*, unsigned);

    Cursor(const Matrices<T>);
    Cursor<T>& operator=(const Matrices<T>);

    Cursor(const Submatrix<T>);
    Cursor<T>& operator=(const Submatrix<T>);

    //оператор за изход
    template <typename T1>
    friend ostream& operator <<(ostream&, Cursor<T1>&);
};

#endif // CURSOR_H
