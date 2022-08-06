/*
    Program that takes a string input
    from stdin (say 'str'), allocate memory
    of same length (as of 'str') and copy
    content of content of 'str' into new
    allocated memory using strncpy

    Use of custom strncpy
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macros */
#define MAX_LEN 50

// Custom strncpy function
char *mystrncpy(char *dest, const char *src, size_t num)
{
    // if destination has no memory
    if (dest == NULL)
    {
        return NULL;
    }

    // ptr points to beginning of destination
    char *ptr = dest;

    // copy first `num` characters from dest to src
    while (*src != '\0' && num--)
    {
        *dest++ = *src++;
    }

    // terminate dest
    *dest = '\0';

    // return result
    return ptr;
}

/* Driver code */
int main()
{
    /*
     ******************************************************
     Local Variables
     ******************************************************
     */
    char buffer[MAX_LEN];
    char *input_string = NULL;

    /*
     ******************************************************
     Receive input in buffer
     ******************************************************
     */
    printf("\nEnter a string: ");
    fgets(buffer, MAX_LEN, stdin);
    buffer[strlen(buffer) - 1] = '\0';

    /*
     ******************************************************
     Allocate memory for string
     ******************************************************
     */
    input_string = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

    /*
     ******************************************************
     Use of strncpy
     ******************************************************
     */
    mystrncpy(input_string, buffer, strlen(buffer));

    /*
    ******************************************************
    Print result
    ******************************************************
    */
    printf("Your string is: %s\n", input_string);
    free(input_string);
}