#include <stdio.h>

void bubbleSort(int array[], int size) {
    int isSorted = 0;
    
    for ( int i = size; i > 0 && isSorted == 0; i-- ) {
        isSorted = 1;
        for ( int j = 1; j <= i; j++ ) {
            int prev = j - 1;
            
            if ( array[j] < array[prev] ) {
                int temp = array[j];
                
                array[j] = array[prev];
                array[prev] = temp;
                isSorted = 0;
            }
        }
    }
}

int main() {
    int len= 10;
    int last = 9;
    int seq[] = {9, 3, 4, -6, 1, 3, 4, -7, 0, 4};
    
    bubbleSort(seq, len);
    
    printf("Sorted array: (");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", seq[i]);
    }
    printf("%d)\n", seq[last]);
    
    return 0;
}
