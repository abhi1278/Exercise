/*
    Program that take a single line
    input from file, extract each word
    separated by space, print them in
    newline and print total word count
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macros */
#define MAX_LEN 100
#define DELIMITER ' '
#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"
#define READ_MODE "r"
#define WRITE_MODE "w"

/* custom strtok implementation */
char *mystrtok(char *str, char delimiter)
{
    // string state
    static char *input = NULL;

    // initialize input string first time
    if (str != NULL)
        input = str;

    // final state of input
    if (input == NULL)
        return NULL;

    // stores the extracted string separated by delimiter
    char *result = malloc((strlen(input) + 1) * sizeof(char));
    int index = 0;

    // extract and store in array
    while (input[index] != '\0')
    {
        // if delimiter encountered
        if (input[index] == delimiter)
        {
            result[index] = '\0';      // trim previous word
            input = input + index + 1; // increment ptr to next word
            return result;
        }

        // Else extract char by char
        else
        {
            result[index] = input[index];
        }

        index++;
    }

    // if loop ends normally and delimiter not encountered
    result[index] = '\0';
    input = NULL;

    // return result string
    return result;
}

/* Display word count and print each word in new line */
void display_sentence(char *input_string, FILE *fp_out)
{
    /* Local variable */
    unsigned int word_count = 0;

    /* Extract each word and print them in separate line */
    char *curr_word = mystrtok(input_string, DELIMITER);

    while (curr_word != NULL)
    {
        fprintf(fp_out, "%s\n", curr_word);
        curr_word = mystrtok(NULL, DELIMITER);
        word_count++;
    }

    /* print total number of words */
    fprintf(fp_out, "\nTotal number of words: %u\n", word_count);
    return;
}

/* Driver code */
int main()
{
    /*
     ******************************************************
     Local variables
     ******************************************************
     */
    FILE *fp_in = NULL;
    FILE *fp_out = NULL;
    char *input_string = NULL;

    /*
     ******************************************************
     Open text files to read/write
     ******************************************************
     */

    fp_in = fopen(INPUT_FILE, READ_MODE);

    if (fp_in == NULL)
    {
        printf("Cannot open input file\n");
        exit(EXIT_FAILURE);
    }

    fp_out = fopen(OUTPUT_FILE, WRITE_MODE);

    if (fp_out == NULL)
    {
        printf("Cannot open output file\n");
        exit(EXIT_FAILURE);
    }

    /*
     ******************************************************
     Input string (currently assuming file has only 1 line)
     ******************************************************
     */
    char buffer[MAX_LEN];
    fgets(buffer, MAX_LEN, fp_in);

    /*
     ******************************************************
     Use of strtok
     ******************************************************
     */
    display_sentence(buffer, fp_out);

    /*
     ******************************************************
     Close pointer to avoid mem leak
     ******************************************************
     */
    fclose(fp_in);
    fclose(fp_out);
}