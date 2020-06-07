#include <stdio.h>

#define RATE 1001

int main() {
    int farmerQuantity;
    int amountNeeded;
    int amount, price;
    unsigned long long minPrice = 0;
    unsigned long long farmers[RATE];
    unsigned long long amountCurrent = 0;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d %d", &farmerQuantity, &amountNeeded);
    
    for ( int i = 0; i < RATE; i++ ) {
        farmers[i] = 0;
    }
    
    for ( int i = 0; i < farmerQuantity; i++ ) {
        fscanf(in, "%d %d", &amount, &price);
        farmers[price] += amount;
    }
    
    for ( int i = 1; i < RATE; i++ ) {
        amountCurrent += farmers[i];
        minPrice += farmers[i] * i;
        if ( amountCurrent > amountNeeded ) {
            minPrice = minPrice - (amountCurrent - amountNeeded) * i;
            i = RATE;
        }
    }
    
    if ( amountCurrent < amountNeeded ) {
        minPrice = 0;
    }
    
    fprintf(out, "%llu\n", minPrice);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
