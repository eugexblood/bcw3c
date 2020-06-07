#include <stdio.h>

void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int indexMin = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[indexMin] ) {
                indexMin = j;
            }
        }
        if ( indexMin != i ) {
            int temp = array[i];
            
            array[i] = array[indexMin];
            array[indexMin] = temp;
        }
    }
}

int main() {
    int len= 10;
    int last = 9;
    int seq[] = {9, 3, 4, -6, 1, 3, 4, -7, 0, 4};
    
    selectSort(seq, len);
    
    printf("Sorted array: (");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", seq[i]);
    }
    printf("%d)\n", seq[last]);
    
    return 0;
}
