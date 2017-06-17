#include <iostream>
#include <cstring>

using namespace std;
#include "src/Matrices.cpp"
#include "src/Vectors.cpp"
#include "src/Submatrix.cpp"
#include "src/Cursor.cpp"


int main()
{
    setlocale(LC_ALL, "Bulgarian");

    double num = 5;   // ще го използваме при събиране, изваждане, умножение, деление на вектор или матрица с число
    int i = 0, j = 2; // ще го използваме при достъп до елемент на вектор и на матрица

    //създаваме матрици, вектори, субматрица и курсор
    double a[4] = {1, 2, 3, 4},
           b[4] = {5, 6, 7, 8},
           c[4] = {9, 0, 1, 2},
           d[4] = {3, 1, 8, 1},
           e[3] = {3, 2, 1},
           f[3] = {4, 5, 6};
    Vectors <double> A(a, 4),
                     B(b, 4),
                     C(c, 4),
                     D(d, 4),
                     E(e, 3),
                     F(f, 3);

    Vectors <double> k[3] = {A, B, C},
                     l[3] = {D, B, A},
                     m[2] = {E, F},
                     n[4] = {A, B, C, D};
    Matrices <double> K(k, 3),
                      L(l, 3),
                      M(m, 2),
                      N(n, 4);

    Submatrix <double> Q(N, 1, 1, 3, 3);

    Cursor <double> Z = K;

    //събиране и изваждане на два вектора с еднакви размерности
    cout << "Събиране и изваждане на два вектора: " << endl
         << "A = " << A << endl                 //проверяваме само + и -
         << "B = " << B << endl                 //защото те използват
         << "A + B = " << (A + B) << endl       //съответно с += и -=
         << "A - B = " << (A - B) << endl << endl;
    system("pause");
    system("CLS");

    //събиране, изваждане, умножение, деление на вектор с число
    cout << "Събиране, изваждане, умножение, деление на вектор с число: " << endl
         << "A = " << A << endl                           //отново проверяваме
         << "A + " << num << " = " << (A+num) << endl     //само +, -, * и /
         << "A - " << num << " = " << (A-num) << endl     //защото те използват
         << "A * " << num << " = " << (A*num) << endl     //съответно +=, -=,
         << "A / " << num << " = " << (A/num) << endl;    //*= и /=
    system("pause");
    system("CLS");

    //достъп до елемет на вектор
    cout << "Достъп до елемент на вектор: "
         << "B = " << B << endl;
    B[i] += num;                                          //променяме i-тия елемент
    cout << "След промяната на елемент с номер " << i << ": " // и извеждаме новия вектор
         << "B = " << B << endl;
    system("pause");
    system("CLS");


    //скаларно произведение на два вектора
    cout << "Скаларно произведение на два вектора: " << endl
         << "A = " << A << endl
         << "B = " << B << endl
         << "A * B = " << (A * B) << endl;
    system("pause");
    system("CLS");

    //векторно произведение на 2 вектора
    cout << "Векторно произведение на два вектора: " << endl
         << "E = " << E << endl         //проверяваме само ^=
         << "F = " << F << endl;        //зашото то изплозва ^
    E^=F;
    cout << "E ^ F = " << E << endl;
    system("pause");
    system("CLS");

    //нормализиране на вектор
    cout << "Нормализиране на вектор: " << endl
         << "A = " << A << endl;
    !A;
    cout << "След нормалзирането: А = " << A << endl;
    system("pause");
    system("CLS");

    //умножение на вектор с матрица
    cout << "Умножение на вектор с матрица: " << endl
         << "E = " << E << endl                     //има само*,
         << "K: " << endl << K << endl << endl     //защото връща матрица
         << "E * K: " <<  endl << (E * K) << endl;
    system("pause");
    system("CLS");

    //събиране и изваждане на матрици
    cout << "Събиране и изваждане на матрици: " << endl
          << "K: " << endl << K << endl << endl            //проверяваме само + и -
          << "L: " << endl << L << endl << endl            //защото те използват
          << "K + L: " << endl << (K + L) << endl << endl  //съответно += и -=
          << "K - L: " << endl << (K - L) << endl;
    system("pause");
    system("CLS");

    //добавяне, изваждане на число към всички елементи на матрица
    cout << "Добавяне, изваждане на число към всички елементи на матрица: " << endl
         << "K: " << endl << K << endl << endl         //проверяваме само + и -
         << "K + " << num << ": " << endl              //защото те използват
         << (K + num) << endl << endl                  //съответно += и -=
         << "K - " << num << ": " << endl
         << (K - num) << endl << endl;
    system("pause");
    system("CLS");

    //умножение на две матрици
    cout << "Умножение на две матрици: " << endl   //проверяваме само *=,
         << "M: " << endl << M << endl << endl     //защото то използва *
         << "L: " << endl << L << endl << endl;
         M*=L;
    cout << "M * L: " << endl << M;
    system("pause");
    system("CLS");

    //умножение на матрица с вектор
    cout << "Умножение на матрица с вектор: " << endl
         << "K: " << endl << K << endl << endl     //проверяваме само *
         << "A = " << A << endl << endl            //защото то използва *=
         << "K * A: " << endl << (K * A) << endl << endl;

    system("pause");
    system("CLS");

    //умножение и деление на матрица с число
    cout << "Умножение и деление на матрица с число: " << endl
         << "K: " << endl << K << endl << endl     //проверяваме само * и /
         << "К * " << num << ": " << endl          //защото те използват *= и /=
         << (K * num) << endl << endl
         << "К / " << num << ": " << endl
         << (K / num) << endl << endl;
    system("pause");
    system("CLS");

    //достъп до елементи на матрица
    cout << "Достъп до елементи на матрица: " << endl
         << "K: " << endl << K << endl << endl;
    K[i][j] += num;
    cout << "След промяната на елементa К[" << i << "][" << j << "]:"
         << endl << K << endl << endl;
    system("pause");
    system("CLS");

    //транспониране на матрица
    cout << "Tранспониране на матрица: " << endl
         << "K: " << endl << K << endl << endl;
    ~K;
    cout << "Транспонираната матрица е: " << endl << K;
    system("pause");
    system("CLS");
    // намиране на детерминанта на матрица
    cout << "Намиране на детерминанта на матрица: " << endl
         << "N: " << endl << N << endl << endl
         << "Детерминантата на N е: "
         << (N.det()) << endl;
    system("pause");
    system("CLS");

    // намиране на обратна матрица
    cout << "Намиране на обратна матрица: " << endl
         <<"N: " << endl << N << endl << endl
         << "Обратната матрица на N е: "
         << (!N) << endl << endl;
    system("pause");
    system("CLS");

    //подматрица
    cout << "Подматрица: " << endl << Q << endl << endl;
    system("pause");
    system("CLS");

    //курсор
    cout << "Kурсор: " << endl << Z;
    system("pause");
    system("CLS");

    return 0;
}

