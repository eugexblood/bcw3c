#include <stdio.h>

#define SIZE 3

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            fscanf(in, "%d", &matrix[col][row]);
        }
    }
}

// end for Bender

int main() {
    int size = 3;
    int chess[size][size];
    int lastIndex;
    FILE *input = fopen("task.in", "r");
    
    matrixScan(input, chess, size);
    
    fclose(input);
    
    lastIndex = size - 1;
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < lastIndex; col++ ) {
            printf("%d ", chess[col][row]);
        }
        printf("%d\n", chess[lastIndex][row]);
    }
    
    return 0;
}
