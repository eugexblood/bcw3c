#include <stdio.h>

void insertSort(int array[], int len) {
    for ( int i = 1; i < len; i++ ) {
        int temp = array[i];
        int j = i;
        
        for ( int prev = j - 1; j > 0 && array[prev] > temp; j--, prev-- ) {
            array[j] = array[prev];
        }
        array[j] = temp;
    }
}

int main() {
    int len= 10;
    int last = 9;
    int seq[] = {9, 3, 4, -6, 1, 3, 4, -7, 0, 4};
    
    insertSort(seq, len);
    
    printf("Sorted array: (");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", seq[i]);
    }
    printf("%d)\n", seq[last]);
    
    return 0;
}
