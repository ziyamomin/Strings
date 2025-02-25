#ifndef STR_H
#define STR_H

#include <stdio.h>
#include <stdlib.h>


/* This function computes the length of the passed in string parameter pcSrc. The function attempts to compute the length of pcSrc and returns the number of characters, not including the trailing null character.*/
size_t Str_getLength(const char *pcSrc);

/* This function copies the characters from the string pointed to by pcSrc into the array 
   pointed to by pcDest. It copies characters until it encounters the null character in pcSrc, 
   then null-terminates pcDest. The string pcDest must have sufficient space to hold the result. 
   Returns a pointer to the destination, pcDest. */
char *Str_copy(char *pcDest, const char *pcSrc);

/* This function appends a copy of the null-terminated string pcSrc parameter to the end of the null-terminated string pcDest parameter, then adds a terminating ‘\0’.  The string pcDest must have sufficient space to hold the result. The pointer pcDest is returned. */
char *Str_concat(char *pcDest, const char *pcSrc);

/* This function lexicographically compares the two parameter strings pcSrc1 and pcSrc2. 
   It returns a negative value if pcSrc1 is less than pcSrc2, 
   zero if they are equal, and a positive value if pcSrc1 is greater than pcSrc2. */
int Str_compare(const char *pcSrc1, const char *pcSrc2);

/* This function searches for the first occurrence of the string parameter pcNeedle 
   within the string parameter pcHaystack. If found, it returns a pointer to the first matching substring 
   in pcHaystack. If no match is found, it returns a null pointer. */
const char *Str_search(const char *pcHaystack, const char *pcNeedle);

#endif

