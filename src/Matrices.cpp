#include <iostream>
#include <cstring>
using namespace std;
#include "Matrices.h"

template <typename T>
Matrices<T>::Matrices():matrix(NULL),num_rows(0), num_columns(0){} //конструктор по подразбиране

template <typename T>
Matrices<T>::Matrices(const Vectors<T>* matrix, unsigned num_rows) //конструктор
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
            cout << "Редовете са с различен брой елементи!";
            delete [] this -> matrix;
            this -> num_rows = 0;
            num_columns = 0;
            this -> matrix = NULL;
        }
    }
}

template <typename T>
Matrices<T>::~Matrices()    //деструктор
{
    delete []matrix;
}

template <typename T>
Matrices<T>::Matrices(const Matrices<T>& other) //копи конструктор
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
Matrices<T>& Matrices<T>::operator=(const Matrices<T>& other) //оператор =
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
Matrices<T>::Matrices(const Submatrix<T> other):Matrices((Matrices<T>&)other){} //копи конструктор със субматрица

template <typename T>
Matrices<T>& Matrices<T>::operator=(const Submatrix<T> other) //оператор = със субматрица
{
    *this = (Matrices<T>&)other;
}

template <typename T>
Matrices<T>::Matrices(const Cursor<T> other):Matrices((Matrices<T>&)other){} //копи конструктор с курсор

template <typename T>
Matrices<T>& Matrices<T>::operator=(const Cursor<T> other) //оператор = с курсор
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

//потоци за вход и изход
template <typename T1>
istream& operator >>(istream& is, Matrices<T1>& object)
{
    if(object.matrix != NULL)
    {
        delete []object.matrix;
        object.matrix = NULL;
    }
    //въвеждат се размерностите на матрицата
    cout <<"Въведете брой редове на матрицата: ";
    is >> object.num_rows;
    cout << "Въведете брой колони на матрицата: ";
    is >> object.num_columns;

    //заделяме памет за матрицата
    T1* array = new T1[object.num_columns];
    Vectors<T1> tmpV(array, object.num_columns);
    Vectors<T1>* tmpArr = new Vectors<T1>[object.num_rows];
    for(int i = 0; i < object.num_rows; i++)
        tmpArr[i] = tmpV;
    Matrices<T1> tmpM(tmpArr, object.num_rows);
    tmpM.num_columns = object.num_columns;
    object = tmpM;

    //въвеждаме елементите на матрицта
    cout << "Въведете елементите на матрицата ";
    for(int i = 0; i < object.num_rows; i++)
        for(int j = 0; j < object.num_columns; j++)
            is >> object[i][j];
    return is;
}

template <typename T1>
ostream& operator <<(ostream& os, const Matrices<T1>& object)
{
    for(int i = 0; i < object.num_rows; i++) //обхожда редовете
    {
        os << object.matrix[i];     //извежда вектора
        if(i < object.num_rows - 1)
            os << endl;
    }
    return os;
}

//операции за събиране и изваждане на матрици
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
    //проверка на размерностите
    if(num_rows != other.num_rows || num_columns != other.num_columns)
    {
        cout << "Двете матрици са с различни размерности!" << endl;
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
    //проверка на размерностите
    if(num_rows != other.num_rows || num_columns != other.num_columns)
    {
        cout << "Двете матрици са с различни размерности!" << endl;
        return *this;
    }
    for(int i = 0; i < num_rows; i++)
            matrix[i] -= other.matrix[i];
    return *this;
}

//операции за добавяне и изваждане на число към всички елементи на матрицата
template <typename T>
Matrices<T> Matrices<T>::operator+(double num)  //добавяне на число към всички елементи на матрицата
{
    Matrices<T> tmp = *this;
    tmp+=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator+=(double num) //добавяне на число към всички елементи наматрицата
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] += num;
    return *this;
}

template <typename T>
Matrices<T> Matrices<T>::operator-(double num)      //изваждане на число от всички елементи на матрицата
{
    Matrices<T> tmp = *this;
    tmp-=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator-=(double num)    //изваждане на число от всички елементи на матрицата
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] -= num;
    return *this;
}

//операции за умножение на матрици
template <typename T>
Matrices<T> Matrices<T>::operator*(const Matrices<T>& other)
{
    //проверка на размерностите
    if(num_columns != other.num_rows)
    {
        cout << "Двете матрици не могат да се умножат!" << endl;
        return *this;
    }

    Matrices<T> product; //създаваме матрица
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

//операции за умножение на матрица с вектор
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
    Vectors<T> arr[1];      //създаваме масив от 1вектор
    arr[0] = other;         //записваме вектора в масива
    Matrices<T> tmp(arr, 1);  //създаваме матрица по масива
    ~tmp;                       //транспонираме матрицата
    *this*=tmp;     //умножаваме двете матрици
    return *this;
}

//операции за умножение и деление на матрица с число
template <typename T>
Matrices<T> Matrices<T>::operator*(double num)      //умножение на всички елементи на матрицата с число
{
    Matrices<T> tmp = *this;
    tmp*=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator*=(double num)    //уможение на всички елементи на матрицата с число
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] *= num;
    return *this;
}

template <typename T>
Matrices<T> Matrices<T>::operator/(double num)      //деление на всички елементи на матрицата с число
{
    Matrices<T> tmp = *this;
    tmp/=num;
    return tmp;
}

template <typename T>
Matrices<T>& Matrices<T>::operator/=(double num)    //деление на всички елементи на матрицата с число
{
    for(int i = 0; i < num_rows; i++)
        matrix[i] /= num;
    return *this;
}

//операция за достъп до елементи
template <typename T>
Vectors<T>& Matrices<T>::operator[](int num)
{
    //проверка дали елемент с такъв номер съществува
    if(num >= num_rows)
    {
        cout <<"Несъществуващ елемент!"<<endl;
        return matrix[num_rows - 1];
    }
    if(num < 0)
    {
        cout <<"Несъществуващ елемент!"<<endl;
        return matrix[0];
    }
    //връщаме елемента
    return matrix[num];
}

//операция за транспониране на матрица
template <typename T>
Matrices<T> Matrices<T>::operator~()
{
    Matrices<T> tmp;            //създаваме нова матрица
    tmp.num_rows = num_columns; //задаваме брой редове на новата матрица
    tmp.num_columns = num_rows; //задаваме брой колони на новата матрица
    tmp.matrix = new Vectors<T>[tmp.num_rows]; //заделяме памет за новата матрица
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

//помощна функция за det()
template <typename T>
Matrices<T> Matrices<T>::help_det(int column)               //трие ред и колона от матрицата
{
    T* array = new T[num_rows - 1];                         //създаваме масив от числа
    Vectors<T> tmpV(array, num_rows - 1);                   //създаваме вектор с конструкора за вектори
    Vectors<T>* tmpArr = new Vectors<T>[num_rows - 1];      //създаваме масив от вектори
    for(int i = 0; i < num_rows - 1; i++)                   //запълваме масива от вектори със вече създадения вектор(заради размрността)
        tmpArr[i] = tmpV;
    Matrices<T> tmpM(tmpArr, num_rows - 1);                 //създаваме матрица с конструктора за матрици
    tmpM.num_columns = num_columns - 1;                     //задаваме брой колони на матрицата

    for(int i = 1; i < num_rows; i++)                       //записва подадената матрица без първия ред и колоната, с чийто номер
        for(int j = 0, k = 0; j < num_rows; j++)            //сме влезли
            if(j != column)
            {
                tmpM[i-1][k] = (*this)[i][j];
                k++;
            }
    return tmpM;
}

//намиране на детерминанта на матрица
template <typename T>
double Matrices<T>::det()
{
    if(num_rows != num_columns)
    {
        cout << "Матрицата не е квадратна!" << endl;
        return 0;
    }
    double determinant = 0;
    if(num_rows == 1)               //ако матрицата е 1х1
        return (*this)[0][0];
    if(num_rows == 2)               //ако матрицата е 2х2
        return (*this)[0][0]*(*this)[1][1] - (*this)[0][1]*(*this)[1][0];
    if(num_rows == 3)               //ако матрицата е 3х3
    {
        double a = (*this)[0][0]*(*this)[1][1]*(*this)[2][2] +      //положителните
                   (*this)[0][1]*(*this)[1][2]*(*this)[2][0] +
                   (*this)[0][2]*(*this)[1][0]*(*this)[2][1];

        double b = (*this)[0][2]*(*this)[1][1]*(*this)[2][0] +      //отрицателните
                   (*this)[0][1]*(*this)[1][0]*(*this)[2][2] +
                   (*this)[0][0]*(*this)[1][2]*(*this)[2][1];
        return a-b;
    }
                    //ако матрицара е 4х4 или по-голяма
    for(int i = 0; i < num_rows; i++)
    {
        Matrices<T> tmp = this->help_det(i);        //развиваме по първи ред
        if(i%2 == 1)                                //ако коефициента е отрицателен
            determinant-=((*this)[0][i]*tmp.det());
        else                                        //ако коефициента е положителен
            determinant+=((*this)[0][i]*tmp.det());

    }
    return determinant;
}

//операция за намране на обратна матрица
template <typename T>
Matrices<T> Matrices<T>::operator!()
{
    if((*this).det() == 0)                       //проверяваме дали матрицата е обратима (det != 0)
    {
        cout << "Матрицата не е обратима!" << endl;
        return *this;
    }

    Matrices<T> result = *this;                //създаваме матрица същата като подадената
    for(int i = 0; i < result.num_rows; i++)   //правим създадената матрица единична матрица
        for(int j = 0; j < result.num_columns; j++)
        {
            if(i == j)
                result[i][j] = 1;
            else
                result[i][j] = 0;
        }
    Matrices<T> tmp = *this;              //създаваме матрица същата като подадената

    bool flag = 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i < result.num_rows; i++)
            if(tmp[i][i] == 0)              //проверяваме дали има нули по главния диагонал
            {                               //и ако има правим флаг = 1
                flag = 1;
                for(int j = 0; j < result.num_rows; j++) //търсим ред, в който на i-тата колона няма 0
                {
                    if(tmp[j][i]!=0)            //търсим ред, в който на i-тата колона няма 0
                    {
                        Vectors<T> copy = tmp[i];       //разменяме i-тия ред с j-тия
                        tmp[i] = tmp[j];
                        tmp[j] = copy;
                        break;
                    }
                }
            }
    }

    for(int i = 0; i < num_rows; i++)
    {
        result[i]/=tmp[i][i];           //разширената матрица е tmp|result
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


