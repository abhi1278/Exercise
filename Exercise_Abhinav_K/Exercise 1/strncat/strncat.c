/*
    Program that takes two string inputs
    from command line concatenate them
    using " - " delimiter and print final
    result on stdout
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macros */
#define MAX_LEN 20
#define DELIMITER " - "
#define DELIMITER_SIZE 3

/* Global vars */
const size_t num_cmd_lin_arg = 3;

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
     Use of strncat
     ******************************************************
     */
    if (fst_cmd_lin_arg_size + sec_cmd_lin_arg_size > MAX_LEN)
    {
        printf("Concatination size overflow!\n");
        exit(EXIT_FAILURE);
    }

    strncat(concatenation_result, fst_cmd_lin_arg, fst_cmd_lin_arg_size);
    strcat(concatenation_result, DELIMITER);
    strncat(concatenation_result, sec_cmd_lin_arg, sec_cmd_lin_arg_size);

    /*
     ******************************************************
     Result
     ******************************************************
     */
    printf("%s\n", concatenation_result);
}