#include "..\include\cs50.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool char_check(string key);
bool unique_char(string key);

int main(int argc, string argv[])
{
    //Check if it has only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Check if it is 26 characters long
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    //Check if it has only alphabet letters
    if (char_check(argv[1]) == false)
    {
        printf("Key must contain 26 letters.\n");
        return 1;
    }
    //Check if it has 26 unique letters
    if (unique_char(argv[1]) == false)
    {
        printf("Key must contain 26 unique letters.\n");
        return 1;
    }

    //Create an array with the key
    char key[26];
    for (int i = 0; i < 26; i++)
    {
        key[i] = argv[1][i];
    }

    //Input for the text to be encrypted
    string plaintext = get_string("plaintext:  ");
    int string_length = strlen(plaintext);
    //Create the char array that will become the ciphertext
    char ciphertext[string_length];

    for (int i = 0, l = string_length; i < l; i++)
    {
        //For each letter on the plaintext it will get the alphabet position, match with the key index and replace with the corresponding encryption key.
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = toupper(key[(plaintext[i] - 65)]);
            }
            else
            {
                ciphertext[i] = tolower(key[(plaintext[i] - 97)]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    //Add a terminal character to the array
    ciphertext[string_length] = 0;
    printf("ciphertext: %s\n", ciphertext);



}

bool char_check(string key)
{
    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (isalpha(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool unique_char(string key)
{
    for (int base = 0, lenght = strlen(key); base < lenght; base++)
    {
        for (int compare = 0; compare < lenght; compare++)
        {
            if (base != compare)
            {
                if (key[base] == key[compare])
                {
                    return false;
                }
            }
        }
    }
    return true;
}