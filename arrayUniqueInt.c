#include <stdio.h>

int arrayUnique(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int key = array[i];
        
        for ( int j = i + 1; j < size; ) {
            if ( array[j] == key ) {
                for ( int k = j + 1; k < size; k++ ) {
                    array[k-1] = array[k];
                }
                size -= 1;
            } else {
                j += 1;
            }
        }
    }
    return size;
}

void arrayPrint(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
}

int main() {
    int len = 10;
    int seq[] = {1, 1, 1, 1, 1, 7, 1, 1, 2, 1};
    
    arrayPrint(seq, len);
    len = arrayUnique(seq, len);
    printf("New length is %d.\n", len);
    arrayPrint(seq, len);
    
    return 0;
}
