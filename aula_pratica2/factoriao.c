#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Um factorião, para uma dada base, é um número inteiro positivo n que é igual à soma do factorial de
//cada um dos seus algarismos.
//Escreva um programa eficiente que lhe permita listar, para a base 10, todos os factoriões menores que
//10⁶.

int factoriao( void ) 
{
    int x = 0;
    printf("Factoriais menores que 10⁶:\n");

    while (x < pow(10, 6))
    {
        int y = x;
        int w = 0;

        while (y)
        {
            int r = y % 10;
            int z = 1;

            while (r >= 1)
            {
                z = r*z;
                r--;
            }

            w += z;
            y /= 10;
            
        }

        if (x == w && w != 0)
        {
            printf("--> %d\n", w);
        }

        x++;        
        
    }

    return 0;
    
}

int main ( void )
{
    factoriao();
}

