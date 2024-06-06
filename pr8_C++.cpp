

#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    HINSTANCE load;
    load = LoadLibrary(L"DynLib.dll");
    typedef int (*found) (string, string);
    found Found;

    Found = (found)GetProcAddress(load, "Found");

    string mainstr;
    string substr;
    cout << "Введите строку: ";
    cin >> mainstr;
    cout << "Введите что в ней искать: ";
    cin >> substr;
    cout << "Содержит ли строка " << mainstr << " символы " << substr << " ?" << endl;

    bool check = Found(mainstr, substr);

    if (check) {
        cout << "есть такое" << endl;
    }
    else {
        cout << "нет такого" << endl;
    }
    FreeLibrary(load);
}

