#include <iostream>

// typedef struct Node{
//     int x,y, info;
//     struct Node *next;
//     struct Node *prev;
// }Node;

// typedef struct Matrix{
//     int length, height;
//     Node *head, *tail;
// }Matrix;

// typedef struct Vector{
//     int *info, size; 
// }Vector;

typedef struct Node {
    int x, info;
    struct Node* next, * prev;
}Node;

typedef struct Line {
    int y;
    Node* head, * tail;
    struct Line* next, * prev;
}Line;

typedef struct Matrix {
    int lenght, height;
    Line* head, * tail;
}Matrix;

/*typedef struct Vector {
    int size, * info;
}Vector;*/


Line* matrixSearch(Matrix& matr, int searched);
int inputMatrix(Matrix& matr, int length, int height);
void printMatrix(Matrix& matr);
int comparisonLines(Matrix& matr);
void generateVector(Matrix& matr /*Vector& vect*/);
