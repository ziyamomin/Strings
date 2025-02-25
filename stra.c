#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "str.h"

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *Str_copy(char pcDest[], const char pcSrc[])
{   
    size_t i;
    assert(pcDest != NULL && pcSrc != NULL);
    for(i = 0; pcSrc[i] != '\0'; i++) {
        pcDest[i] = pcSrc[i];
    }
    pcDest[i] = '\0';
    return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[]) {
    size_t i = 0;
    size_t j = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    while(pcDest[i] != '\0') {
        i++;
    }
    while (pcSrc[j] != '\0') {
        pcDest[i++] = pcSrc[j++];
    }
    pcDest[i] = '\0';
    return pcDest;
}

int Str_compare(const char pcSrc1[], const char pcSrc2[]) {
    size_t i = 0;
    assert(pcSrc1 != NULL && pcSrc2 != NULL);
    while (pcSrc1[i] != '\0' && pcSrc2[i] != '\0') {
        if (pcSrc1[i] != pcSrc2[i]) {
            return (int)(pcSrc1[i] - pcSrc2[i]);
        }
        i++;
    }
    return (int)(pcSrc1[i] - pcSrc2[i]);
}

char *Str_search(const char pcHaystack[], const char pcNeedle[]) {
    size_t i;
    size_t j;
    pc = pcHaystack;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    
    if (pcNeedle[0] == '\0') {
        return (char *)pcHaystack;
    }
    
    for (i = 0; pcHaystack[i] != '\0'; i++) {
        j = 0;
        while (pcHaystack[i+j] != '\0' && pcNeedle[j] != '\0' && pcHaystack[i+j] == pcNeedle[j]) {
            j++;
        }
        if (pcNeedle[j] == '\0') {
            return &pc[i];
        }
    }
    return NULL;
}