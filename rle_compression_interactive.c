/*
 * rle_compression.c
 *
 * This program implements a simple Run-Length Encoding (RLE) algorithm for file compression and decompression.
 * It interactively prompts the user to choose the operation and enter the filenames.
 *
 * To compile: gcc rle_compression.c -o rle_compression
 * To run: ./rle_compression
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void compressFile(const char *inputFile, const char *outputFile);
void decompressFile(const char *inputFile, const char *outputFile);

int main()
{
    char mode[20];
    char inputFile[100], outputFile[100];

    // Get the operation mode from the user
    printf("Enter mode (compress/decompress): ");
    scanf("%19s", mode);

    // Get filenames for input and output
    printf("Enter the input filename: ");
    scanf("%99s", inputFile);
    printf("Enter the output filename: ");
    scanf("%99s", outputFile);

    if (strcmp(mode, "compress") == 0)
    {
        compressFile(inputFile, outputFile);
    }
    else if (strcmp(mode, "decompress") == 0)
    {
        decompressFile(inputFile, outputFile);
    }
    else
    {
        fprintf(stderr, "Invalid mode. Please use 'compress' or 'decompress'.\n");
        return EXIT_FAILURE;
    }

    return 0;
}

// Compress a file using run-length encoding
void compressFile(const char *inputFile, const char *outputFile)
{
    FILE *fin = fopen(inputFile, "r");
    if (fin == NULL)
    {
        perror("Error opening input file for compression");
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(outputFile, "w");
    if (fout == NULL)
    {
        perror("Error opening output file for compression");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    int count;
    char curr, prev;
    prev = fgetc(fin);
    if (prev == EOF)
    { // Handle empty file
        fclose(fin);
        fclose(fout);
        return;
    }

    count = 1;
    while ((curr = fgetc(fin)) != EOF)
    {
        if (curr == prev)
        {
            count++;
        }
        else
        {
            // Write the character followed by its count
            fprintf(fout, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }
    // Write the final sequence
    fprintf(fout, "%c%d", prev, count);

    fclose(fin);
    fclose(fout);
    printf("File compressed successfully to '%s'\n", outputFile);
}

// Decompress a file encoded with run-length encoding
void decompressFile(const char *inputFile, const char *outputFile)
{
    FILE *fin = fopen(inputFile, "r");
    if (fin == NULL)
    {
        perror("Error opening input file for decompression");
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(outputFile, "w");
    if (fout == NULL)
    {
        perror("Error opening output file for decompression");
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    char ch;
    int count;
    // Read each character and its following count
    while ((ch = fgetc(fin)) != EOF)
    {
        if (fscanf(fin, "%d", &count) != 1)
        {
            fprintf(stderr, "Error reading count for character '%c'\n", ch);
            break;
        }
        for (int i = 0; i < count; i++)
        {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    printf("File decompressed successfully to '%s'\n", outputFile);
}
