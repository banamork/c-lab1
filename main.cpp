#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main(){
    Matrix* matr = new Matrix;
    int length, heigth;
    cout << "Введите ширину вашей матрицы" << " " << endl;
    cin >> length;
    cout << "Введите высоту вашей матрицы" << " " << endl;
    cin >> heigth;
    inputMatrix(*matr, length, heigth);
    printMatrix(*matr);
    generateVector(*matr);
    cout << "Это все! Пока!" << " " << endl;
    delete matr;
    return 0;
}