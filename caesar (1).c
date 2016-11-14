#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
/*
This program encrypts messages using Caesar’s cipher. 
It accepts a single command-line argument: a non-negative integer.
*/
int main(int argc, string argv[])
{
//Check that user provided one command-line argument.
    if (argc != 2) 
    {    
        printf("Please enter one command-line argument.\n");
        return 1;
    }
//Convert the string provided to an int.
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Please enter a non-negative integer as your key at the command-line.\n");
        return 1;
    }
//Obtain and encode plaintext, then print ciphertext.
//This request causes an error in check50: 
//printf("Please provide the plaintext you would like encoded:");
    string plaintext = GetString();
    int ciphertext;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if isalpha (plaintext[i])
        {
            if islower (plaintext[i])
            {
                ciphertext = 97 + (plaintext[i] - 97 + key) % 26;
                printf("%c", (char)ciphertext);
            }
            if isupper (plaintext[i])
            {
                ciphertext = 65 + (plaintext[i] - 65 + key) % 26;
                printf("%c", (char)ciphertext);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
