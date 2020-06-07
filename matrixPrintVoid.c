#include <stdio.h>

#define SIZE 5

void matrixPrint(FILE *out, int matrix[SIZE][SIZE], int size) {
    int last = size - 1;
    
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < last; col++ ) {
            fprintf(out, "%d ", matrix[col][row]);
        }
        fprintf(out, "%d\n", matrix[last][row]);
    }
}

// end for Bender

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            fscanf(in, "%d", &matrix[col][row]);
        }
    }
}

void matrixMultiply(int matrix[SIZE][SIZE], int size, int multiplier) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            matrix[col][row] *= multiplier;
        }
    }
}

int main() {
    int size = 5;
    int chess[size][size];
    int lastIndex;
    FILE *input = fopen("task.in", "r");
    FILE *output = fopen("task.out", "w");
    
    matrixScan(input, chess, size);
    matrixMultiply(chess, size, 5);
    matrixPrint(output, chess, size);
    
    fclose(input);
    fclose(output);
    
    return 0;
}
