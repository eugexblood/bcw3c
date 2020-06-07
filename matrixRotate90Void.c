#include <stdio.h>

#define SIZE 3

void matrixRotate90(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int targetRow = 0; targetRow < size; targetRow++ ) {
        for ( int targetCol = 0, sourceCol = size - 1; targetCol < size; targetCol++, sourceCol-- ) {
            target[targetCol][targetRow] = source[targetRow][sourceCol];
        }
    }
}

// end for bender

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            fscanf(in, "%d", &matrix[col][row]);
        }
    }
}

int main() {
    int size = SIZE;
    int lastIndex = size - 1;
    int matrix[SIZE][SIZE];
    int matrixNew[SIZE][SIZE];
    FILE *in = fopen("task.in", "r");
    
    matrixScan(in, matrix, size);
    matrixRotate90(matrixNew, matrix, size);
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < lastIndex; col++ ) {
            printf("%d ", matrixNew[col][row]);
        }
        printf("%d\n", matrixNew[lastIndex][row]);
    }
    
    fclose(in);
    
    return 0;
}
