#include <stdio.h>
#include "cs50.h"

int main(void)
{
    //store the input on the variable name
    string name = get_string("What's your name? ");
    //print the text with the variable
    printf("hello, %s\n", name);
}