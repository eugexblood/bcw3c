#include <stdio.h>

int main() {
    int maxJump, cell;
    unsigned long long ways = 0;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d %d", &maxJump, &cell);
    
    if ( cell <= maxJump ) {
        ways = 1 << (cell - 1);
    } else {
        unsigned long long array[cell];
        
        for ( int i = 0; i < maxJump; i++ ) {
            array[i] = 1 << i;
        }
        for ( int i = maxJump; i < cell; i++ ) {
            array[i] = 0;
            for ( int j = i - maxJump; j < i; j++ ) {
                array[i] += array[j];
            }
        }
        ways = array[cell-1];
    }
    
    fprintf(out, "%llu\n", ways);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
