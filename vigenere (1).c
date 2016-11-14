#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
/*
This program encrypts messages using Vignere’s cipher. 
It accepts a single command-line argument: an alphabetic key.
*/
int main(int argc, string argv[])
{
//Check that user provided one command-line argument.
    if (argc != 2) 
    {    
        printf("Please enter one command-line argument.\n");
        return 1;
    }
//Check that key is only alphabetic characters. 
    else if (argv[1])
    {
        for (int k = 0; k < strlen(argv[1]); k++)
        {
            if (!isalpha(argv[1][k]))
            {
                printf("Please provide an alphabetic key.\n");
                return 1;
            }
        }
    }
//Obtain and encode plaintext, then print ciphertext.
//This request causes an error in check50: printf("Please provide the plaintext you would like encoded:");
    string key = argv[1];
    string plaintext = GetString();
    int m = strlen(key);
    int n = strlen(plaintext);
    for (int i = 0, j = 0; i < n; i++)
    {
        int ciphertext;
        if isalpha (plaintext[i])
        {
            if islower (plaintext[i])
            {
                if islower (key[j % m])
                {
                    ciphertext = 97 + ((plaintext[i] - 97 + key[j % m]-97) % 26);
                    printf("%c", (char)ciphertext);
                }
                else
                {
                    ciphertext = 97 + ((plaintext[i] - 97 + key[j % m]-65) % 26);
                    printf("%c", (char)ciphertext);
                }
            }
            if isupper (plaintext[i])
            {
                if islower (key[j % m])
                {
                    ciphertext = 65 + ((plaintext[i] - 65 + key[j % m]-97) % 26);
                    printf("%c", (char)ciphertext);
                }
                else
                {
                    ciphertext = 65 + ((plaintext[i] - 65 + key[j % m]-65) % 26);
                    printf("%c", (char)ciphertext); 
                }
            }
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
