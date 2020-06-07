#include <stdio.h>

void arrayShift(int array[], int size, int shift) {
    int shiftLeft;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    shiftLeft = size - shift;
    
    if ( shiftLeft > shift ) {
        int buffer[shift];
        int i = size - 1;
        int j = shiftLeft - 1;
        int k = shift - 1;
        
        for ( ; k >= 0; i--, j--, k-- ) {
            buffer[k] = array[i];
            array[i] = array[j];
        }
        for ( ; j >= 0; i--, j-- ) {
            array[i] = array[j];
        }
        for ( k = shift - 1; i >= 0; i--, k-- ) {
            array[i] = buffer[k];
        }
    } else {
        int buffer[shiftLeft];
        int i = 0;
        int j = shiftLeft;
        
        for ( ; i < shiftLeft; i++, j++ ) {
            buffer[i] = array[i];
            array[i] = array[j];
        }
        for ( ; j < size; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int k = 0; i < size; i++, k++ ) {
            array[i] = buffer[k];
        }
    }
}


int main() {
    int seq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;
    int value;
    int last = len - 1;
    
    scanf("%d", &value);
    
    arrayShift(seq, len, value);
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", seq[i]);
    }
    printf("%d\n", seq[last]);
    
    return 0;
}
