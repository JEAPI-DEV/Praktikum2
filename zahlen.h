#ifndef ZAHLEN_H
#define ZAHLEN_H

#define CASE_HEX_SMALL "0x"
#define CASE_HEX_BIG "0X"
#define CASE_OCTAL "0"

/** Verwendune zur Darstellung maximal
 * DIGITS lange Zeichenkette
 */
#define DIGITS 8 /* As bytes */

/* Groesste erlaubte Zahl mit DIGITS Stellen */
#define MAXZAHL (1<<DIGITS) /* convert bytes to bits (2^DIGITS) */

/** Initialisiere /loesche str mit c. */
void clear(char c, char str[]);

/**
 * Bilde aus der eichenkette str eine positive
 * Ganzzahl und gebe diese zurueck oder -1
 * im Fehlerfall einer ungueltingen Zeichenkette.
 */
int str2int(char str[]);

/**
 * Bilde aus der eichenkette str eine positive
 * Ganzzahl und gebe diese zurueck oder -1
 * im Fehlerfall einer ungueltingen Zeichenkette.
 */
int str2intEX(char str[]);

/**
 * Schreibt die Binnaerdartellung der
 * Ganzzahl i in die Zeichenkette str.
 */
void int2Binaer(int i, char str[]);


/**
 * Extra fun, convert string to float.
 * does only accept the Base 10 8 and 16 systems.
 */
float str2float(char str[]);

#endif