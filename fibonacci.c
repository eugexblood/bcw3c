#include <stdio.h>

int main() {
    int index;
    int fibonacci = 1;
    int sign = 1;
    
    scanf("%d", &index);
    
    if ( index == 0 ) {
        fibonacci = 0;
    } else {
        if ( index < 0 ) {
            index *= -1;
            if ( index % 2 == 0 ) {
                sign = -1;
            }
        }
        for ( int i = 2, n2 = 0, n1 = 0; i <= index; i++ ) {
            n2 = n1;
            n1 = fibonacci;
            fibonacci = n2 + n1;
        }
    }
    
    printf("%d\n", sign*fibonacci);
    
    return 0;
}
