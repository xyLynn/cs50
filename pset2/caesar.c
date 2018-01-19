#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, string argv[])
{
    int k, alpha_index, move, ascii_index;
    string p;

    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        p = get_string("plaintext: ");
        printf("ciphertext: ");
        k = atoi(argv[1]); //what if key > 26, transfer it to less than 26;
        k = k % 26;

        for (int i = 0, n = strlen(p); i < n; i++)
        {
            if (islower(p[i]))
            {
                alpha_index = (int) p[i] - 97;
                move = (alpha_index + k) % 26;
                ascii_index = move + 97;
                printf("%c", ascii_index);
            }
            else if (isupper(p[i]))
            {
                alpha_index = (int) p[i] - 65;
                move = (alpha_index + k) % 26;
                ascii_index = move + 65;
                printf("%c", ascii_index);
            }
            else
            {
                printf("%c", p[i]);
            }
        }

        printf("\n");
    }
}

