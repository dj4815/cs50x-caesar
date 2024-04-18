#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc == 2)
    {
        // Make sure every character in argv[1] is a digit
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // If characters are not digit
            if (!isdigit(argv[1][i]))
            {
                // Remind user of usage
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // Convert argv[1] from a `string` to an `int`
        int key = atoi(argv[1]);

        // Prompt user for plaintext
        string plaintext = get_string("plaintext: ");

        // For each character in the plaintext:
        char ciphertext[strlen(plaintext) + 1];
        for (int i = 0; i < strlen(plaintext); i++)
        {
            // If character is uppercase:
            if (isalpha(plaintext[i]) && isupper(plaintext[i]))
            {
                // Rotate by -65 + value of key
                ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
            }
            // Else if character is lowercase
            else if (isalpha(plaintext[i]) && islower(plaintext[i]))
            {
                // Rotate by -97 + value of key
                ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
            }
            // If its not an alphabetic character
            else
            {
                // Just copy it
                ciphertext[i] = plaintext[i];
            }
        }
        // Null terminate the thing for some reason
        ciphertext[strlen(plaintext)] = '\0';

        // Print the ciphertext
        printf("ciphertext: %s\n", ciphertext);
    }
    // If input is more than one argument
    else
    {
        // Remind user of usage
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
