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

    double num = 5;   // �� �� ���������� ��� ��������, ���������, ���������, ������� �� ������ ��� ������� � �����
    int i = 0, j = 2; // �� �� ���������� ��� ������ �� ������� �� ������ � �� �������

    //��������� �������, �������, ���������� � ������
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

    //�������� � ��������� �� ��� ������� � ������� �����������
    cout << "�������� � ��������� �� ��� �������: " << endl
         << "A = " << A << endl                 //����������� ���� + � -
         << "B = " << B << endl                 //������ �� ���������
         << "A + B = " << (A + B) << endl       //��������� � += � -=
         << "A - B = " << (A - B) << endl << endl;
    system("pause");
    system("CLS");

    //��������, ���������, ���������, ������� �� ������ � �����
    cout << "��������, ���������, ���������, ������� �� ������ � �����: " << endl
         << "A = " << A << endl                           //������ �����������
         << "A + " << num << " = " << (A+num) << endl     //���� +, -, * � /
         << "A - " << num << " = " << (A-num) << endl     //������ �� ���������
         << "A * " << num << " = " << (A*num) << endl     //��������� +=, -=,
         << "A / " << num << " = " << (A/num) << endl;    //*= � /=
    system("pause");
    system("CLS");

    //������ �� ������ �� ������
    cout << "������ �� ������� �� ������: "
         << "B = " << B << endl;
    B[i] += num;                                          //��������� i-��� �������
    cout << "���� ��������� �� ������� � ����� " << i << ": " // � ��������� ����� ������
         << "B = " << B << endl;
    system("pause");
    system("CLS");


    //�������� ������������ �� ��� �������
    cout << "�������� ������������ �� ��� �������: " << endl
         << "A = " << A << endl
         << "B = " << B << endl
         << "A * B = " << (A * B) << endl;
    system("pause");
    system("CLS");

    //�������� ������������ �� 2 �������
    cout << "�������� ������������ �� ��� �������: " << endl
         << "E = " << E << endl         //����������� ���� ^=
         << "F = " << F << endl;        //������ �� �������� ^
    E^=F;
    cout << "E ^ F = " << E << endl;
    system("pause");
    system("CLS");

    //������������� �� ������
    cout << "������������� �� ������: " << endl
         << "A = " << A << endl;
    !A;
    cout << "���� ��������������: � = " << A << endl;
    system("pause");
    system("CLS");

    //��������� �� ������ � �������
    cout << "��������� �� ������ � �������: " << endl
         << "E = " << E << endl                     //��� ����*,
         << "K: " << endl << K << endl << endl     //������ ����� �������
         << "E * K: " <<  endl << (E * K) << endl;
    system("pause");
    system("CLS");

    //�������� � ��������� �� �������
    cout << "�������� � ��������� �� �������: " << endl
          << "K: " << endl << K << endl << endl            //����������� ���� + � -
          << "L: " << endl << L << endl << endl            //������ �� ���������
          << "K + L: " << endl << (K + L) << endl << endl  //��������� += � -=
          << "K - L: " << endl << (K - L) << endl;
    system("pause");
    system("CLS");

    //��������, ��������� �� ����� ��� ������ �������� �� �������
    cout << "��������, ��������� �� ����� ��� ������ �������� �� �������: " << endl
         << "K: " << endl << K << endl << endl         //����������� ���� + � -
         << "K + " << num << ": " << endl              //������ �� ���������
         << (K + num) << endl << endl                  //��������� += � -=
         << "K - " << num << ": " << endl
         << (K - num) << endl << endl;
    system("pause");
    system("CLS");

    //��������� �� ��� �������
    cout << "��������� �� ��� �������: " << endl   //����������� ���� *=,
         << "M: " << endl << M << endl << endl     //������ �� �������� *
         << "L: " << endl << L << endl << endl;
         M*=L;
    cout << "M * L: " << endl << M;
    system("pause");
    system("CLS");

    //��������� �� ������� � ������
    cout << "��������� �� ������� � ������: " << endl
         << "K: " << endl << K << endl << endl     //����������� ���� *
         << "A = " << A << endl << endl            //������ �� �������� *=
         << "K * A: " << endl << (K * A) << endl << endl;

    system("pause");
    system("CLS");

    //��������� � ������� �� ������� � �����
    cout << "��������� � ������� �� ������� � �����: " << endl
         << "K: " << endl << K << endl << endl     //����������� ���� * � /
         << "� * " << num << ": " << endl          //������ �� ��������� *= � /=
         << (K * num) << endl << endl
         << "� / " << num << ": " << endl
         << (K / num) << endl << endl;
    system("pause");
    system("CLS");

    //������ �� �������� �� �������
    cout << "������ �� �������� �� �������: " << endl
         << "K: " << endl << K << endl << endl;
    K[i][j] += num;
    cout << "���� ��������� �� �������a �[" << i << "][" << j << "]:"
         << endl << K << endl << endl;
    system("pause");
    system("CLS");

    //������������� �� �������
    cout << "T������������ �� �������: " << endl
         << "K: " << endl << K << endl << endl;
    ~K;
    cout << "��������������� ������� �: " << endl << K;
    system("pause");
    system("CLS");
    // �������� �� ������������ �� �������
    cout << "�������� �� ������������ �� �������: " << endl
         << "N: " << endl << N << endl << endl
         << "�������������� �� N �: "
         << (N.det()) << endl;
    system("pause");
    system("CLS");

    // �������� �� ������� �������
    cout << "�������� �� ������� �������: " << endl
         <<"N: " << endl << N << endl << endl
         << "��������� ������� �� N �: "
         << (!N) << endl << endl;
    system("pause");
    system("CLS");

    //����������
    cout << "����������: " << endl << Q << endl << endl;
    system("pause");
    system("CLS");

    //������
    cout << "K�����: " << endl << Z;
    system("pause");
    system("CLS");

    return 0;
}

