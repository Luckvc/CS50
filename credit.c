#include "cs50.h"
#include <stdio.h>
int main(void)
{
    int i = 0;
    int sumeven = 0;
    int sumodd = 0;
    int everyother = 0;
    int digit = 0;
    int counter = 0;
    int seconddigit;
    //Get the card number.
    long card = get_long("Insert card number: ");
    while (card != 0)
    {
        //We store de digit before the current, at the end will give me the second digit of the number.
        seconddigit = digit;
        //To go through every number, we divide it by 10 and the remainder will be the last digit.
        digit = card % 10;
        //When we divede it by 10, we make de last digit become a decimal, and since it is an interger, the decimal number is deleted.
        card = card / 10;
        //A counter to verify the number of digits
        counter += 1;
        //If the inverse index of the number that we are on is even, so every other digit starting from the last one, we will just sum it to a variable.
        if ((i % 2) == 0)
        {
            sumeven += digit;
        }
        //Else if the inverse index of the number is odd, so every other digit starting from the second to last, we will multiply it by 2.
        else
        {
            everyother = 2 * digit;
            //if we get a number 10 or higher, we aply the same concept of getting the remainder then dividing it by 10 to get all digits.
            if (everyother >= 10)
            {
                while (everyother != 0)
                {
                    int y = everyother % 10;
                    everyother = everyother / 10;
                    //And then sum each digit.
                    sumodd += y;
                }
            }
            //If it is a number smaller than 10, we just add it to the sum
            else
            {
                sumodd += everyother;
            }
        }
        i += 1;
    }
    //We add the sum of both sums
    int totalsum = sumeven + sumodd;
    if ((totalsum % 10) == 0)
    {
        //We check if it has 15 digits and if it starts with 34 or 37 to return AMEX
        if (digit == 3 && counter == 15 && (seconddigit == 4 || seconddigit == 7))
        {
            printf("AMEX\n");
            return 0;
        }
        //We check if it has 13 or 16 digits and if it starts with 4 return VISA
        if (digit == 4 && (counter == 13 || counter == 16))
        {
            printf("VISA\n");
            return 0;
        }
        /*if (digit == 4 && counter == 16)
        {
            printf("VISA\n");
            return 0;
        }*/
        //We check if it has 16 digits and if it starts with 51 through 55 to return MASTERCARD
        if (digit == 5 && counter == 16 && (seconddigit == 1 || seconddigit == 2 || seconddigit == 3 || seconddigit == 4
                                            || seconddigit == 5))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        //Otherwise we return invalid
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }


}