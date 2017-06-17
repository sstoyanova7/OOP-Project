#ifndef SUBMATRIX_H
#define SUBMATRIX_H

#include "Matrices.h"
#include "Cursor.h"

template <typename T>
class Cursor;

template <typename T>
class Matrices;

template <typename T>
class Vectors;

template <typename T>
class Submatrix:public Matrices<T>
{
private:
    Submatrix(const Vectors<T>*, unsigned);
public:
    Submatrix();
    Submatrix(Matrices<T>, unsigned, unsigned, unsigned, unsigned);

    Submatrix(const Matrices<T>);
    Submatrix<T>& operator=(const Matrices<T>);

    Submatrix(const Cursor<T>);
    Submatrix<T>& operator=(const Cursor<T>);
};
#endif // SUBMATRIX_H
