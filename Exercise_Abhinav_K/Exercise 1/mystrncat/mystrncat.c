/*
    Program that takes two string inputs
    from command line concatenate them
    using " - " delimiter and print final
    result on stdout

    Use of custom strncat function
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Macros */
#define MAX_LEN 20
#define DELIMITER " - "
#define DELIMITER_SIZE 3

/* Global vars */
const size_t num_cmd_lin_arg = 3;

/* Implementation of mystrncat */
char *mystrncat(char *dest, char *src, size_t num)
{
    /* Local variables */
    size_t dest_len = strlen(dest);

    // ptr point to end of dest
    char *ptr = dest + dest_len;

    // Append src to dest
    while (*src != '\0' && num--)
    {
        *ptr++ = *src++;
    }

    // terminate dest
    *ptr = '\0';

    // return result of concatenation
    return dest;
}

/* Driver code */
int main(int argc, char *argv[])
{
    /* Receive two words */
    if (argc != num_cmd_lin_arg)
    {
        printf("Provide only two arguments!\n");
        exit(EXIT_FAILURE);
    }

    /*
     ******************************************************
     Local Variables
     ******************************************************
     */
    char concatenation_result[MAX_LEN];
    char *fst_cmd_lin_arg = argv[1];
    char *sec_cmd_lin_arg = argv[2];
    unsigned int fst_cmd_lin_arg_size = strlen(fst_cmd_lin_arg);
    unsigned int sec_cmd_lin_arg_size = strlen(sec_cmd_lin_arg);

    /*
     ******************************************************
     Use of mystrncat
     ******************************************************
     */
    if (fst_cmd_lin_arg_size + sec_cmd_lin_arg_size > MAX_LEN)
    {
        printf("Concatination size overflow!\n");
        exit(EXIT_FAILURE);
    }

    mystrncat(concatenation_result, fst_cmd_lin_arg, fst_cmd_lin_arg_size);
    strcat(concatenation_result, DELIMITER);
    mystrncat(concatenation_result, sec_cmd_lin_arg, sec_cmd_lin_arg_size);
    printf("%s\n", concatenation_result);
}
