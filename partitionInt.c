#include <stdio.h>

#define LIMIT 100

void arrayScan(FILE *in, int array[], int len) {
    for ( int i = 0; i < len; i++ ) {
        fscanf(in, "%d", &array[i]);
    }
}

void arrayPrint(FILE *out, int array[], int len) {
    int last = len - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int partition(int array[], int start, int end) {
    int mid = (start + end) / 2;
    int pivot = array[mid];
    int pivotIndex;
    
    array[mid] = array[end];
    array[end] = pivot;
    
    for ( pivotIndex = start; array[pivotIndex] < array[end]; pivotIndex++ );
    for ( int i = pivotIndex + 1; i < end; i++ ) {
        if ( array[i] < pivot ) {
            int temp = array[i];
            
            array[i] = array[pivotIndex];
            array[pivotIndex] = temp;
            pivotIndex += 1;
        }
    }
    
    array[end] = array[pivotIndex];
    array[pivotIndex] = pivot;
    
    return pivotIndex;
}

int main() {
    int array[LIMIT];
    int len;
    FILE *in;
    FILE *out;
    
    in = fopen("task.in", "r");
    out = fopen("task.out", "w");
    
    fscanf(in, "%d", &len);
    arrayScan(in, array, len);
    
    printf("Partition pivot element index is %d.\n", partition(array, 0, len));
    
    arrayPrint(out, array, len);
    
    fclose(in);
    fclose(out);
    
    
    return 0;
}
