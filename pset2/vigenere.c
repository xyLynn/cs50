#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    string k, p;
    int num_key, len_key, alpha_index, move, ascii_index, temp, len_str;

    k = argv[1];

    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isalpha(k[i]) == false)
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
            break;
        }
    }

    p = get_string("plaintext: ");
    printf("ciphertext: ");

    len_key = strlen(k);
    len_str = strlen(p);

    for (int j = 0; j < len_str; j++)
    {
        int nchar = -1;
        for (int i = 0; i <= j; i++)
        {
           if(isalpha(p[i])) {
               nchar++;
           }
        }

        if (!isalpha(p[j]))
        {
            printf("%c", p[j]);
        }
        else
        {
            num_key = nchar % len_key;
            temp = (int) tolower(k[num_key]) - 97;

            if (islower(p[j]))
            {
                alpha_index = (int) p[j] - 97;
                move = (alpha_index + temp) % 26;
                ascii_index = move + 97;
                printf("%c", ascii_index);
            }
            else if (isupper(p[j]))
            {
                alpha_index = (int) p[j] - 65;
                move = (alpha_index + temp) % 26;
                ascii_index = move + 65;
                //printf("%i %i %i %c \n", alpha_index, temp, move, ascii_index);
                printf("%c", ascii_index);
            }
        }

    }
    printf("\n");

}