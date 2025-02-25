#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t Str_getLength(const char s[])
{
    size_t uLength = 0;
    assert(s != NULL);
    while (s[uLength] != '\0')
        uLength++;
    return uLength;
}

char *Str_copy(char s1[], const char s2[]) {
    size_t i;
    assert(s1 != NULL && s2 != NULL);
    for(i = 0; s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return s1;
}

char *Str_concat(char s1[], const char s2[]) {
    size_t i = 0;
    size_t j = 0;
    assert(s1 != NULL && s2 != NULL);
    while(s1[i] != '\0') {
        i++;
    }
    while (s2[j] != '\0') {
        s1[i++] = s2[j++];
    }
    s1[i] = '\0';
    return s1;
}

int Str_compare(const char s1[], const char s2[]) {
    size_t i = 0;
    assert(s1 != NULL && s2 != NULL);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (int)(s1[i] - s2[i]);
        }
        i++;
    }
    return (int)(s1[i] - s2[i]);
}

const char *Str_search(const char s1[], const char s2[]) {
    size_t i;
    size_t j;
    assert(s1 != NULL && s2 != NULL);
    
    if (s2[0] == '\0') {
        return (char *)s1;
    }
    
    for (i = 0; s1[i] != '\0'; i++) {
        j = 0;
        while (s1[i+j] != '\0' && s2[j] != '\0' && s1[i+j] == s2[j]) {
            j++;
        }
        if (s2[j] == '\0') {
            return &s1[i];
        }
    }
    return NULL;
}