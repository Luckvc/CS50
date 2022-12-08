#include "..\include\cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string var);

int main(int argc, string argv[])
{
    //Check if it has only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //check if the command-line argument is a number
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    char ciphertext[(strlen(plaintext))];

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        //Check if it is a letter on the alphabet
        if (isalpha(plaintext[i]))
        {
            //Cipher the uppercase letters
            if (isupper(plaintext[i]))
            {
                char cipherchar = ((((int) plaintext[i] - 64) + key) % 26) + 64;
                ciphertext[i] = cipherchar;
            }
            //Cipher the lowercase letters
            if (islower(plaintext[i]))
            {
                char cipherchar = ((((int) plaintext[i] - 96) + key) % 26) + 96;
                ciphertext[i] = cipherchar;
            }
        }
        //Keep special characters
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    //Had to add a array terminator to stop printf from printing random characters
    ciphertext[(strlen(plaintext))] = 0;
    printf("ciphertext: %s\n", ciphertext);

}


bool only_digits(string var)
{
    for (int i = 0, l = strlen(var); i < l; i++)
    {
        if (isdigit(var[i]) == false)
        {
            return 0;
        }
    }
    return 1;
}