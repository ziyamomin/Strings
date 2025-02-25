#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *pcDest, const char *pcSrc) {
    char *start = pcDest;
    assert(pcDest != NULL && pcSrc != NULL);
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0';
    return start; 
}

char *Str_concat(char *pcDest, const char *pcSrc)
{
    char *start = pcDest;
    assert(pcDest != NULL && pcSrc != NULL);
    while (*pcDest != '\0') {
        pcDest++;
    }
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }
    *pcDest = '\0';
    return start;
}


int Str_compare(const char *pcSrc1, const char *pcSrc2) {
    assert(pcSrc1 != NULL && pcSrc2 != NULL);

    while (*pcSrc1 != '\0' && *pcSrc2 != '\0' && *pcSrc1 == *pcSrc2) {
        pcSrc1++;
        pcSrc2++;
    }

    return (int)(*pcSrc1 - *pcSrc2);
}

char *Str_search(const char *pcHaystack, const char *pcNeedle) {
    assert(pcHaystack != NULL && pcNeedle != NULL);

    if (*pcNeedle == '\0') {
        return pcHaystack;
    }

    while (*pcHaystack != '\0') {
        const char *pcHaystack_copy = pcHaystack;
        const char *pcNeedle_copy = pcNeedle;

        while (*pcHaystack_copy != '\0' && *pcNeedle_copy != '\0' && *pcHaystack_copy == *pcNeedle_copy) {
            pcHaystack_copy++;
            pcNeedle_copy++;
        }

        if (*pcNeedle_copy == '\0') {
            /* Casting to match strstr return type */
            return (char*)pcHaystack;
        }

        pcHaystack++;
    }

    return NULL;
}
