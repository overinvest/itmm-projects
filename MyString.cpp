// MyString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MyString.h"
#include <Windows.h>

using namespace std;

void localize() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main()
{
    localize();

    MyString A(" z.ad iuqw.asd , ..qw. da");
    MyString B;
    MyString C(A);
    MyString D("FYTGBU");
    MyString F(123);
    int count = 0;
    MyString* data;

    data = new MyString[A.GetCount()];

    A.string_split_smart(MyString("+-*.., "), data, count);

    for (int i = 0; i < count; i++) {
        cout << data[i] << endl;
    }

    for (int i = 0; i < A.GetCount(); i++) {
        cout << A[i];
    }
    cout << endl;

    for (int i = 0; i < B.GetCount(); i++) {
        cout << B[i];
    }
    cout << endl;

    B = A;

    for (int i = 0; i < B.GetCount(); i++) {
        cout << B[i];
    }
    cout << endl;

    for (int i = 0; i < C.GetCount(); i++) {
        cout << C[i];
    }
    cout << endl;

    B = A.copy(3, 4);

    for (int i = 0; i < B.GetCount(); i++) {
        cout << B[i];
    }
    cout << endl;

    int index = A.find(B);

    cout << "Вхождение B в А " << index << endl;

    index = A.find(D);

    cout << "Вхождение D в А " << index << endl;

    index = A.find('C');

    cout << "Вхождение 'C' в А " << index << endl;

    string _str = "BC1";

    index = A.find(_str);

    cout << "Вхождение \"B\" в А " << index << endl;

    B = A.copy(3, 20);

    for (int i = 0; i < B.GetCount(); i++) {
        cout << B[i];
    }
    cout << endl;

    C.del(3, 2);

    for (int i = 0; i < C.GetCount(); i++) {
        cout << C[i];
    }
    cout << endl;

    C = A + B;

    for (int i = 0; i < C.GetCount(); i++) {
        cout << C[i];
    }
    cout << endl;

    C = A;

    if (C == A) {
        cout << "C == A" << endl;
    }
    else {
        cout << "C != A" << endl;
    }

    cout << "F = " << F << endl;

    cout << 1 << " == " << (int)('1') << endl;

    return 0;
}
