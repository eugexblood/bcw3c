#include <stdio.h>

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int i = 0;
    int j = 0;
    int k = 0;
    
    for ( ; i < len1 && j < len2; k++ ) {
        if ( src1[i] <= src2[j] ) {
            target[k] = src1[i];
            i += 1;
        } else {
            target[k] = src2[j];
            j += 1;
        }
    }
    for ( ; i < len1; i++, k++ ) {
        target[k] = src1[i];
    }
    for ( ; j < len2; j++, k++ ) {
        target[k] = src2[j];
    }
}

int main() {
    int size1 = 5;
    int size2 = 3;
    int lastIndex = size1 + size2 - 1;
    int array1[] = {0, 3, 3, 5, 9};
    int array2[] = {-2, 0, 5};
    int array3[size1 + size2];
    
    arrayMerge(array3, array1, size1, array2, size2);
    
    
    printf("new array is {");
    for ( int i = 0; i < lastIndex; i++ ) {
        printf("%d, ", array3[i]);
    }
    printf("%d}\n", array3[lastIndex]);
    
    return 0;
}
