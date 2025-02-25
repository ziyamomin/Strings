#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Try to use array notation as much as possible nad traverse each
string sing an index rleative to the beginning of the string */

/* This function computes the length of the passed in string parameter
s. The function attempts to compute the length of s and returns the
number of characters, not including the null character. */
size_t Str_getLength(const char *s)
{
    const char *end;
    assert(s != NULL);
    end = s;
    while (*end != '\0')
        end++;
    return (size_t)(end - s);
}

/* Copies the first n characters of the array pointed to by s2 into the
array pointed to by s1. If it encounters a null character in the array
pointed to by s2, the function adds null characters to the array pointed
by s1 until a total of n characters have been written. s1, a pointer
to the destination, is returned.*/
char  *Str_copy(char * s1, const char * s2) {
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

/* This function appends characters form the array pointed to by s2 to
the string pointed to by s1. Copying stops when a null character is 
encountered or n characters have been copied. s1, a pointer to the
concatenated string is returned. */
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


/* This function lexicographically compares the passed in strings s1
and s2. A negative, zero, or positive integer is returned, depending on
whether the first n characters of the array pointed to by s1 are less
than, equal to, or greater than the first n characters of the array
pointed to by s2. Comparison stops if a null character is encountered
in either array. */
int Str_compare(const char *s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);

    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    int difference = (int)*s1 - *s2;
    return difference;
}

/* A pointer to the first occurrence in the string pointed to by s1 of
the sequence of characters in the string pointed to by s2.
Returns a null pointer if no match is found. */
const char *Str_search(const char *s1, const char *s2) {
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
            return s1;
        }

        s1++;
    }

    return NULL;
}
