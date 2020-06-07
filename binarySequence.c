#include <stdio.h>

int sequenceLen(FILE *in) {
    int size = 0;
    
    for ( char digit; fscanf(in, "%c", &digit) == 1; size++ );
    return size;
}

int binarySequence(FILE *in, int size) {
    char seq[size];
    int count = 0;
    
    for ( int i = 0; i < size; i++ ) {
        fscanf(in, "%c", &seq[i]);
    }
    
    for ( int i = 0, j = size - 1; i < j; ) {
        for ( ; seq[i] == '0'; i++ );
        for ( ; seq[j] == '1'; j-- );
        if ( i < j ) {
            seq[i] = '0';
            seq[j] = '1';
            count += 1;
        }
    }
    return count;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size;
    
    size = sequenceLen(in);
    fclose(in);
    
    in = fopen("task.in", "r");
    
    fprintf(out, "%d\n", binarySequence(in, size));
    
    fclose(in);
    fclose(out);
    
    return 0;
}
