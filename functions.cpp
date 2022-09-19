#include <iostream>
#include <string>
#include "functions.h"
#include <vector>
#include <algorithm>


void inputMatrix(Matrix& matr, int length, int height){
    int n;
    matr.lenght = length;
    matr.height = height;
    matr.head = nullptr;
    matr.tail = nullptr;
    std::cout << "Введите количество ненулевых элементов" << " " << std::endl;
    std::cin >> n;
    if(n == 0){
        std::cout << "Количество ненулевых элементов равно 0" << " " << std::endl;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                std::cout << 0 << " ";
            }
        std::cout << std::endl;
        }
    }
    else{
        while(n!= 0){
            int y;

            do{
                std::cout << "Введите координату Y элемента матрицы" << " " << std::endl;
                std::cin >> y;
                if(y <= height) break;
                else std::cout << "Координата больше размера матрицы" << " " << std::endl;
            }while(y > height);

            Line* ptr = matrixSearch(matr, y);
            if (ptr == nullptr){
                ptr = new Line;
                ptr->head = nullptr;
                ptr->next = nullptr;
                ptr->tail = nullptr;
                ptr->prev = matr.tail;
                ptr->y = y;
                if (matr.tail != nullptr)
                    matr.tail->next = ptr;
                if (matr.head == nullptr)
                    matr.head = ptr;
                matr.tail = ptr;
            }
            Node* node = new Node;
            node->next = nullptr;

            do{
            std::cout << "Введите координату X элемента матрицы" << " " << std::endl;
            std::cin >> node->x;
            if(node->x <= length) break;
            else std::cout << "Координата больше размера матрицы" << " " << std::endl;
            }while(node->x > length);

            std::cout << "Введите информацию" << " " << std::endl;
            std::cin >> node->info;
            if (ptr->tail != nullptr)
                ptr->tail->next = node;
            node->prev = ptr->tail;
            ptr->tail = node;
            if (ptr->head == nullptr)
                ptr->head = node;
            n--;
        }
    }
}


Line* matrixSearch(Matrix& matr, int searched){
    Line* ptr = matr.head;
    while(ptr!= nullptr){
        if(ptr->y == searched)
            return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

int comparisonLines(Matrix& matr){
    int *b = new int[2];
    for (int i = 0; i < 2; i++) {
        Line* ptr = matr.head;
        Node* lptr = ptr->head;
        while (ptr != NULL){
            while(lptr != NULL){
                b[i] = b[i] + 1;
                lptr = lptr->next;
            }
            if (ptr->next != nullptr) {
                lptr = ptr->next->head;
            }
            ptr = ptr->next;
        }
    }
    if (b[1] > b[2]) return 1;
    else if (b[1] < b[2]) return 2;
    else if (b[1] == b[2]) return -1;
    return 0;
}

void printMatrix(Matrix& matr){
    std::cout << "Ваша матрица" << " " << std::endl;
    Line* ptr1 = matr.head;
    while(ptr1 != nullptr){
        Node* ptr2 = ptr1->head;
        while (ptr2 != nullptr) {
            if(ptr2->info != 0){
                std::cout << ptr2->info << "[" << ptr2->x << "][" << ptr1->y << "] ";
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
        std::cout << std::endl;
    }
}

void generateVector(Matrix& matr){
    Line* ptr = matr.head;
    Node* lptr = ptr->head;
    int b = 0;
    std::vector <int> ivector;
    int type = comparisonLines(matr);
    while (ptr != NULL){
        while(lptr != NULL){
            b++;
            lptr = lptr->next;
        }
        ivector.push_back(b);
        if (ptr->next != nullptr) {
            lptr = ptr->next->head;
        }
        ptr = ptr->next;
        b = 0;
    }
    if(type == -1){
        std::reverse(ivector.begin(), ivector.end());
        for (int i = 0; i < ivector.size(); i++){
            std::cout << ivector[i] << " ";
        }
        std::cout << std::endl << "Вектор оставлен без изменений" << " " << std::endl;
    }
    else if(type == 1){
        std::sort(ivector.begin(), ivector.end(), std::greater<int>());
        for (int i = 0; i < ivector.size(); i++){
            std::cout << ivector[i] << " ";
            }
        std::cout << std::endl << "Вектор отсортирован по убыванию" << " " << std::endl;
    }
    else if(type == 2){
        std::sort(ivector.begin(), ivector.end());
        for (int i = 0; i < ivector.size(); i++){
            std::cout << ivector[i] << " ";
        }            
        std::cout << std::endl << "Вектор отсортирован по возрастанию" << " " << std::endl;
    }
}


