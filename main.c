#include <stdio.h>
#include <stdlib.h>

#include "zahlen.h"

/**
 * Why can't I tell the true shape of Mount Lu?
 * Because I myself am in the mountains.
 * - Su Shi (1036 - 1101)
 */


void convert2float(char input[]);

int main(int argc, char** argv) {
    char buffer[DIGITS+1];
    int zahl;

    if(argc<2) {
        printf("Aufrufen mit einer Zahl zwischen 0 und %d\n", MAXZAHL-1);
        return 1;
    }
    printf("Input String: \"%s\" \n", argv[1]);

    zahl = str2int(argv[1]);

    if(zahl < 0) {
        printf("Invalid Input: %s \n", argv[1]);
        return 1;
    }

    int2Binaer(zahl, buffer);

    printf("dezi: %d \nbinaer: %s \noktal: 0%o \nhexa: 0x%X \n", zahl, buffer, zahl, zahl);

    if(argc==3) {
        /* Not needed for Praktikum 2 but was bored.*/
        convert2float(argv[2]);
    }

    return 0;
}

void convert2float(char input[]) {
    float number;

    printf("\n\nInput String: \"%s\" \n", input);

    number = str2float(input);

    if(number < 0 || MAXZAHL <= number) {
        printf("Invalid Input: %s \n", input);
        return;
    }

    printf("float %f \n", number);
}
