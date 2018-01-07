#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int p,q,j,i,r,n;
    float money;
    do
    {
        money = get_float("Change owed: ");
    } while (money<0);

    n = round(money*100);
    p = n/25;
    q = (n-25*p)/10;
    j = (n-25*p-10*q)/5;
    i = n-25*p-10*q-5*j;

    r = p+q+j+i;
    printf("%i\n", r);
    //printf("%i,%i,%i,%i,%i\n", n, p, q, j, i);
}