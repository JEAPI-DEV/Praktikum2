#include <stdio.h>
#include <string.h>
#include "zahlen.h"

#include <stdbool.h>

void clear(char c, char str[]) {
    memset(str, c, DIGITS);
    str[DIGITS] = '\0';
}

void int2Binaer(int i, char str[]) {
    int position;
    clear('0', str);

    position = DIGITS - 1;

    while (position >= 0) {
        if (i % 2 == 1) {
            str[position] = '1';
        }
        i /= 2;
        position--;
    }
}

int str2int(char str[]) {
    int result = 0, i;
    /* hexadecimal */
    if (strstr(str, CASE_HEX_SMALL) || strstr(str, CASE_HEX_BIG)) {
        for (i = 2; str[i] != '\0'; i++) {  /* Start after "0x" */
            if (str[i] >= '0' && str[i] <= '9')
                result = result * 16 + (str[i] - '0'); /* 0 = 48 */
            else if (str[i] >= 'a' && str[i] <= 'f')
                result = result * 16 + ((str[i] - 'a') + 10); /* a = 97 */
            else if (str[i] >= 'A' && str[i] <= 'F')
                result = result * 16 + ((str[i] - 'A') + 10); /* A = 65 */
            else return -1;
        }
        if (result >= MAXZAHL) return -1;
        return result;
    }

    /* octal */
    if (str[0] == CASE_OCTAL) {
        for (i = 1; str[i] != '\0'; i++) {  /* Start after "0" */
            if (str[i] < '0' && str[i] > '7') return -1;
            result = result * 8 + (str[i] - '0');
        }
        if (result >= MAXZAHL) return -1;
        return result;
    }

    /* decimal */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return -1;
        result = result * 10 + (str[i] - '0'); /* 0 = 48 in ascii */
    }
    if (result >= MAXZAHL) return -1;
    return result;
}

float str2float(const char str[]) {
    float result = 0, afterDot = 0;
    int i = 0;

    /* fist part before the decimal point */
    for (; str[i] != '\0' && str[i] != '.' && str[i] != ','; i++) {
        if (str[i] < '0' || str[i] > '9') return -1;
        result = result * 10 + (float) (str[i] - '0');
    }

    if (result >= MAXZAHL) return -1;
    if (str[i] == '\0') return result;

    for (i++ ; str[i] != '\0'; i++) { /* convert second part of the float after . or , */
        if (str[i] < '0' || str[i] > '9') return -1; /* verification to test if another . or , is in the string*/

        afterDot = afterDot * 10 + (float) (str[i] - '0');
    }
    while (afterDot >= 1)
        afterDot /= 10;

    return result += afterDot;
}

