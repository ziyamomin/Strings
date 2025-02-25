#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>


/* This function computes the length of the passed in string parameter s. The function attempts to compute the length of s and returns the number of characters, not including the trailing null character.*/
size_t Str_getLength(const char *pcSrc);

/* This function copies the first n characters of the array pointed to by parameter s2 into the array pointed to by parameter s1. If it encounters a null character in the array pointed to by s2, the function adds null characters to the array pointed by s1 until a total of n characters have been written. s1, a pointer to the destination, is returned.*/
char *Str_copy(char *pcDest, const char *pcSrc)

/* This function appends a copy of the parameter string s2 to the end of the parameter string s1. The function returns the pointer s1. */
char *Str_concat(char * s1, const char * s2);

/* This function lexigraphically compares the passed in strings s1 and s2. A negative integer is returned if s1 is lexicographically less than s2. Zero is returned if s1 is lexicographically equal to s2. A positive integer is returned if s1 is lexicographically greater than s2. */
int Str_compare(const char *s1, const char *s2);

/* A pointer to the first occurrence in the string pointed to by parameter s1 of the sequence of characters in the string pointed to by parameter s2. Returns a null pointer if no match is found. */
char *Str_search(const char *pcHaystack, const char *pcNeedle);

#endif