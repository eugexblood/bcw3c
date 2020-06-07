#include <stdio.h>

#define ALPHABET 26

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char symbol;
    int letter[ALPHABET];
    int index;
    
    for ( int i = 0; i < ALPHABET; i++ ) {
        letter[i] = 0;
    }
    for ( ; fscanf(in, "%c", &symbol) == 1; ) {
        if ( symbol >= 'A' && symbol <= 'Z' ) {
            index = symbol - 'A';
            letter[index] += 1;
        } else if ( symbol >= 'a' && symbol <= 'z' ) {
            index = symbol - 'a';
            letter[index] += 1;
        }
    }
    
    for ( int i = 0; i < ALPHABET; i++ ) {
        if ( letter[i] != 0 ) {
            fprintf(out, "%c %d\n", i+'a', letter[i]);
        }
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
