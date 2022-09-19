#include <iostream>
#include <string>
#include "functions.h"
#include <vector>
#include <algorithm>

// 5 4 3 1 2 5 1 4 56 2 3 45

//int inputMatrix(Matrix& matr, int length, int height){
    // std::cin>>matr.length;
    // std::cin>>matr.height;
    // matr.head = NULL;   
    // for(int i = 0; i< matr.height; i++){
    //     for(int j = 0; j< matr.length; j++){
    //         int a;
    //         std::cin>>a;
    //         if (a!=0){
    //             Node* n = new Node;
    //             n->info = a;
    //             n->y = i;
    //             n->x = j;
    //             n->next = matr.head;
    //             n->prev = NULL;
    //             if(matr.head != NULL)
    //                 matr.head->prev = n;
    //             else
    //                 matr.tail = n;
    //             matr.head = n;
    //         }
    //     }   
    // }
    // сооздашь ввод количества не нулевых элементов
    // цикл с количеством итераций равный количеству не нулл элементов
    // вводишь новый элемент: его координаты x, y и информацию по этим координатам
    // ищешь в списке matrix есть ли там линия с такой координатой y
    // если нет, тогда создаешь через new
    // и закидываешь туда новый элемент Node, тоже созданный черз new
    // не забывай, что список дву связный
//}  


int inputMatrix(Matrix& matr, int length, int height){
    int n;
    matr.lenght = length;
    matr.height = height;
    matr.head = nullptr;
    matr.tail = nullptr;
    std::cout << "Введите количество ненулевых элементов" << " " << std::endl;
    std::cin>>n;
    if(n == 0){
        std::cout << "Количество ненулевых элементов равно 0" << " " << std::endl;
        return 1;
    }
    while(n!= 0){
        int y;
        std::cout << "Введите координату Y элемента матрицы" << " " << std::endl;
        std::cin>>y;
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
        std::cout << "Введите координату X элемента матрицы" << " " << std::endl;
        std::cin>> node->x;
        std::cout << "Введите информацию" << " " << std::endl;
        std::cin>> node->info;
        if (ptr->tail != nullptr)
            ptr->tail->next = node;
        node->prev = ptr->tail;
        ptr->tail = node;
        if (ptr->head == nullptr)
            ptr->head = node;
        n--;
    }
    return 0;
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

/*
Если количество ненулевых элементов 0
if (max == 0) {
    for (int i =0; i < strok; i++) {
        for (int j = 0; j < columns; j++) {
            cout << 0 << " ";
        }
        cout << endl;
    }
}
*/

/*void printMatrix(Matrix& matr){
    auto p = matr.tail;
    int count = p->y;
    while (p!= NULL){
        if (count != p->y)
            std::cout << std::endl;
        count = p->y;
        std::cout << p->info << " ";
        p->prev;
    }
    создаешь указатель на первую строку 
    цикл, пока этот указатель не NULL
    в нем создаешь указатель на первый элемент строки 
    цикл, пока указатель на элемент строки не равен NULL
}

int scanLine(Matrix& matr){                        //0 - if b1 > b2 
    int* myVector = new int[matr.height];          //1 - if b1 < b2
    int b;                                         //2 - if b1 = b2
    int n;                                          
    for(int j = 0; j < matr.height; j++){
        for(int i = 0; i < matr.length; i++){
            ///getline(n , string ," ");
        myVector[j] = b;
        }    
    if (myVector[j] > myVector[j++] || myVector[matr.height--] > myVector[0]){
        return 0;    
    }
    else if (myVector[j] < myVector[j++] || myVector[matr.height--] < myVector[0]){
        return 1;
    }
    else if (myVector[j] == myVector[j++] || myVector[matr.height--] == myVector[0]){
        return 2;
    }
    }
    создаешь указатель на первую строку в матрице, ptr1
    и указаетль на след строку, ptr2
    цикл, пока ptr1 не равен NULL
    смотришь какие элементы есть в ptr1, но нет в ptr2
    записываешь в вектор результат 
    делаешь ptr1 = ptr1->next; ptr2 = ptr2->next;
    проверяешь, что ptr2 != NULL
    Если равно, тогда ptr2 = matr.head
    после это цикл завершиться

    НАПОМИНАЮ, то что ты создал с помощью new надо удалить с помощью delete
    И для new нет realloc как в си, поэтому ты копирушь массив в новый массив, который больше, и удаляешь старый
    и нужно организовать проверку ввода!!!!

    try {
        int* arr = new int[10]
    }

}*/
