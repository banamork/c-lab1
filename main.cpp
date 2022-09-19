#include <iostream>
#include "functions.h"
#include <string>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main(){
    Matrix* matr = new Matrix;
    Vector* vect = new Vector;
    int length, heigth;
    std::cout << "Введите ширину вашей матрицы" << " " << std::endl;
    std::cin >> length;
    std::cout << "Введите высоту вашей матрицы" << " " << std::endl;
    std::cin >> heigth;
    inputMatrix(*matr, length, heigth);
    printMatrix(*matr);
    generateVector(*matr, *vect);
    std::cout << "Это все! Пока!";
    return 0;
}