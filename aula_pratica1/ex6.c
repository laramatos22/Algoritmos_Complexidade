#include<stdio.h>

//EXEMPLO DE UTILIZAÇÃO DE ARRAYS

void print_Array(char *s, int a[]) 
{

    int i;
    printf( "%s : ", s );

    for ( i = 0; i < 12; i++)
    {
        printf("%d\n", a[i]);
    }
    
}

void cum_Sum(int a[12], int b[12])
{

    int c=0;
    int i;

    for ( i = 0; i < 12; i++)
    {
        c += a[i];
        b[i] = c;
    }
    

}

int main ( void )
{
    
    int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    print_Array("a", a);

    int b[12];
    cum_Sum(a, b);
    print_Array("b", b);

    return 0;

}


