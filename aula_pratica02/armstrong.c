#include<stdio.h>
#include<stdlib.h>

//Um número de Armstrong, para uma dada base, é um número inteiro positivo de n algarismos que
//é igual à soma de cada um dos seus algarismos levantado à n-ésima potência.
//Escreva um programa eficiente que lhe permita listar, para a base 10, todos os números de Armstrong
//de 3 algarismos.

int main ( void )
{
     int n1, n2, n3, result, n = 99;

     for ( n3 = 1; n3 <= 9; n3++ )
     {
        for ( n2 = 0; n2 <= 9; n2++ )
        {
            for ( n1 = 0; n1 <= 9; n1++ )
            {
                n++;
                result = n1*n1*n1 + n2*n2*n2 + n3*n3*n3;

                if (n == result)
                {
                    printf("%d\n", n);
                }
                
            }
            
        }
        
     }
        

}