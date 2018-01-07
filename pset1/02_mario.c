#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i,j,k,n;

    do
    {
        n = get_int("Height: ");
    } while (n>23 || n<0);

    for (j=1; j<=n; j++)
    {
        for (k=1; k<=n-j; k++)
        {
            printf(" ");
        }
        for (i=1; i<=j+1; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}