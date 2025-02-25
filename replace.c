/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Ziya M                                                     */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine, const char *pcFrom, const char *pcTo) {
    size_t replacements = 0;
    size_t fromLength = Str_getLength(pcFrom);
    const char *pCurrent = pcLine;
    const char *pFound;

    assert(pcLine != NULL && pcFrom != NULL && pcTo != NULL);

    if (fromLength == 0) {
        printf("%s", pcLine);
        return 0;
    }

    while ((pFound = Str_search(pCurrent, pcFrom)) != NULL) {
        (void) fwrite(pCurrent, 1, (size_t)(pFound - pCurrent), stdout);
        printf("%s", pcTo);
        pCurrent = pFound + fromLength;
        replacements++;
    }

    printf("%s", pCurrent);
    return replacements;
}


/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096}; /* Defines the maximum line size */
   enum {PROPER_ARG_COUNT = 3}; /* Ensures there are exactly 3 arguments */

   char acLine[MAX_LINE_SIZE]; /* Array to store each line of input */
   char *pcFrom; /* The substring to find in the input. */
   char *pcTo; /* The substring to replace it with */
   size_t uReplaceCount = 0; /* Counter for the number of replacements */

   if (argc != PROPER_ARG_COUNT) /* Check if the correct number of arguments were passed */
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]); /* Print usage message */
      return EXIT_FAILURE; /* Return failure code since the correct number of arguments were not passed */
   }

   pcFrom = argv[1]; /* Assign the "from" string "*/
   pcTo = argv[2]; /* Assign the "to" string */

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) /* Read each line from stdin */
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo); /* Replace occurences of "from" with "to" */

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount); /* Print the total replacement count */
   return 0; /* Return success */
}