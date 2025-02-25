#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc)
{
    const char *end;
    assert(s != NULL);
    end = s;
    while (*end != '\0')
        end++;
    return (size_t)(end - s);
}

char *Str_copy(char *pcDest, const char *pcSrc) {
    char *start = s1;
    assert(s1 != NULL && s2 != NULL);
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return start; 
}

char *Str_concat(char *s1, const char *s2)
{
    char *start = s1;
    assert(s1 != NULL && s2 != NULL);
    while (*s1 != '\0') {
        s1++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return start;
}


int Str_compare(const char *s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);

    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return (int)(*s1 - *s2);
}

char *Str_search(const char *pcHaystack, const char *pcNeedle) {
    assert(s1 != NULL && s2 != NULL);

    if (*s2 == '\0') {
        return s1;
    }

    while (*s1 != '\0') {
        const char *s1_copy = s1;
        const char *s2_copy = s2;

        while (*s1_copy != '\0' && *s2_copy != '\0' && *s1_copy == *s2_copy) {
            s1_copy++;
            s2_copy++;
        }

        if (*s2_copy == '\0') {
            /* Casting to match strstr return type */
            return (char *)s1;
        }

        s1++;
    }

    return NULL;
}
