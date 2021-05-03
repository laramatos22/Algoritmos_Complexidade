#include<stdio.h>
#include<math.h>
#include<assert.h>

int func1(int n);
int func2(int n);
int func3(int n);

int counter;        //contador global que conta o numero 

int main (void)
{
    int i;

    printf("\nFuncao T1(n):\n");
    for (i = 0; i < 1001; i++)
    {
        counter = 0;
        func1(i);
        printf("n: %d   |    T1(n): %d   |   Nº de Chamadas Recursivas: %d    \n", i, func1(i), counter);
    }

    printf("\nFuncao T2(n):\n");
    for (i = 0; i < 1001; i++)
    {
        counter = 0;
        func2(i);
        printf("n: %d   |    T2(n): %d   |   Nº de Chamadas Recursivas:   %d    \n", i, func2(i), counter);
    }

    printf("\nFuncao T3(n):\n");
    for (i = 0; i < 29; i++)
    {
        counter = 0;
        func3(i);
        printf("n: %d   |    T3(n): %d   |   Nº de Chamadas Recursivas:   %d    \n", i, func3(i), counter);
    }

}

int func1(int n)
{
    assert (n>=0);
    //counter++;
    if(n == 0)  return 0;
    else 
    {
        counter++;
        return func1(n/4) + n;
    }

}

int func2(int n)
{
    assert (n>=0);
    if(n == 0 || n == 1 || n ==2 || n == 3) 
    {
        counter++;
        return n;
    }
    else
    {
        counter++;
        return func2(n/4) + func2((n+3)/4) + n;
    }
    
}

int func3(int n)
{
    assert (n>=0);
    if(n == 0 || n == 1 || n == 2 || n == 3) 
    {
        counter ++;
        return n;
    }    
    else if ((n%4) == 0)
    {
        counter++;
        return 2 * func3(n/4) + n;
    }
    else
    {
        counter++;
        return func3(n/4) + func3((n+3)/4) + n;
    } 
    
}

