#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    long long int card_number, card_number_length, number = card_number, number2 = card_number / 10, last_digit;
    int timesTwo, sum = 0;


//prompt user input
    do
    {
        card_number = get_long_long("Please insert the card number:");
    }
    while (card_number < 1);


//check credit card number lenght
    card_number_length = floor(1 + log10(llabs(card_number)));


//check two starting digits
    int first_two_digits = card_number / pow(10, card_number_length - 2);
    int first_digit = card_number / pow(10, card_number_length - 1);



//Checksum

    while (number > 0)
    {

        last_digit = number % 10;
        sum = sum + last_digit;
        number /= 100;

    }



    while (number2 > 0)
    {

        last_digit = number2 % 10;
        timesTwo = last_digit * 2;
        sum = sum + (timesTwo % 10) + (timesTwo / 10);
        number2 /= 100;

    }


    if (sum % 10 == 0)
    {
        //identify credit card
        if (card_number_length == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (card_number_length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((card_number_length == 13 || card_number_length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
