#include <stdio.h>
#include <stdlib.h>

/* This function computes the length of the passed in string parameter 
s. The function attempts to compute the length of s and returns the 
number of characters, not including the null character. */
size_t Str_getLength(const char s[])
{
    size_t uLength = 0;
    assert(s != NULL);
    while (s[uLength] != '\0')
        uLength++;
    return uLength;
}

/* Copies the first n characters of the array pointed to by s2 into the 
array pointed to by s1. If it encounters a null character in the array 
pointed to by s2, the function adds null characters to the array pointed
by s1 until a total of n characters have been written. s1, a pointer 
to the destination, is returned.*/
char *Str_copy(char restrict s1[], const char restrict s2[], size_t n) {
    size_t i;
    for(i = 0; i < n && s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    while(i < n) {
        s1[i++] = '\0';
    }
    return s1;
}

/* This function appends a copy of the parameter string s2 to the end of
 the parameter string s1. The function returns the pointer s1. */
char *Str_concat(char * restrict s1[], const char restrict s2[], size_t n) {
    size_t i = 0;
    size_t j = 0;
    while(s1[i] != '\0') {
        i++;
    }
    while (j < n && s[2] != '\0') {
        s1[i++] = s2[j++];
    }
    return s1;
}


/* This function lexicographically compares the passed in strings s1 
and s2. A negative, zero, or positive integer is returned, depending on
whether the first n characters of the array pointed to by s1 are less
than, equal to, or greater than the first n characters of the array
pointed to by s2. Comparison stops if a null character is encountered
in either array. */
int Str_compare(const char s1[], const char s2[], size_t n) {
    size_t i; 
    for(i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if(s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        if(i < n) {
            return s1[i] - s2[i];
        }
        return 0;
    }
}

/* A pointer to the first occurrence in the string pointed to by s1 of
the sequence of characters in the string pointed to by s2. Returns a
null pointer if no match is found. */
char *Str_search(const char s1[], const char s2[]) {
    size_t i;
    size_t j;

    if(s2[0] != '\0') {
        return (char *)s1;
    }
    for(j = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0' && s1[i+j] == s2[j]; j++) {
            if(s2[j] == '\0') {
                return &s1[i];
            }
        }
    }
    return NULL;
}