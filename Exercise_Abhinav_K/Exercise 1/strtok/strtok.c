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
#define DELIMITER " "
#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"
#define READ_MODE "r"
#define WRITE_MODE "w"

/* Display word count and print each word in new line */
void display_sentence(char *input_string, FILE *fp_out)
{
    /* Local variable */
    unsigned int word_count = 0;

    /* Extract each word and print them in separate line */
    char *curr_word = strtok(input_string, DELIMITER);

    while (curr_word != NULL)
    {
        fprintf(fp_out, "%s\n", curr_word);
        curr_word = strtok(NULL, DELIMITER);
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