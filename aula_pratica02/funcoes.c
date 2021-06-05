#include<stdio.h>

unsigned int f1 ( unsigned int n)
{
    unsigned int i, j, r = 0;
    int num_ops = 0;    //numero de iterações -> variavel global contadora

    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            r += 1;
            num_ops++;
        }
    }

    printf("f1(n) = %d\n", r);
    printf("Número de iterações = %d\n", num_ops);

    return r;
}

// f1(n) -> n²
// nº de iterações -> n³

unsigned int f2 ( unsigned int n )
{
    unsigned int i, j, r = 0;
    int num_ops = 0;

    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= i; j++ )
        {
            r += 1;
            num_ops++;
        }
    }

    printf("f2(n) = %d\n", r);
    printf("Número de iterações = %d\n", num_ops);

    return r;
}

// f2(n) -> n²
// nº de iterações -> n²

unsigned int f3 ( unsigned int n ) 
{
    unsigned int i, j, r = 0;
    int num_ops = 0;

    for ( i = 1; i <= n; i++)
    {
        for ( j = i; j <= n; j++)
        {
            r += j;
            num_ops++;
        }
    }

    printf("f3(n) = %d\n", r);
    printf("Número de iterações = %d\n", num_ops);

    return r;
}

// f3(n) -> n³
// nº de iterações -> n²

unsigned int f4 ( unsigned int n ) 
{
    unsigned int i, j, r = 0;
    int num_ops = 0;

    for ( i = 1; i <= n; i++)
    {
        for ( j = i; j >= 1; j /= 10)
        {
            r += i;
            num_ops++;
        }
    }

    printf("f4(n) = %d\n", r);
    printf("Número de iterações = %d\n", num_ops);

    return r;
}

// f4(n) -> n² x log10(n)
// nº de iterações -> n x log10(n)

int main ()
{
    for (int i = 1; i <= 15; i++)
    {
        //descomentar consoante a função que se quiser executar 
        //f1(i);
        //f2(i);
        //f3(i);
        f4(i);
    }
    
}




