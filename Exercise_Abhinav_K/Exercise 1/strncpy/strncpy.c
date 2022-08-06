/*
    Program that takes a string input
    from stdin (say 'str'), allocate memory
    of same length (as of 'str') and copy
    content of content of 'str' into new 
    allocated memory using strncat
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macros */
#define MAX_LEN 50

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
    strncpy(input_string, buffer, strlen(buffer));

    /*
    ******************************************************
    Print result
    ******************************************************
    */
    printf("Your string is: %s\n", input_string);
    free(input_string);
}