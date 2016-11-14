#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
/* This program takes a fullname and provides the associated initials.
*/
int main(void)
{
    string name = GetString();
//Check that a name was provided and print capitalized first initial.
    if (name !=NULL)
        printf("%c", toupper(name[0]));
        for (int i = 0, n =strlen(name); i<n; i++)
//Find middle and last names and print capitalized initials.       
        {
            if (name[i-1] == ' ')
                printf("%c",toupper(name[i]));
        }
    printf("\n");
    return 0;
}