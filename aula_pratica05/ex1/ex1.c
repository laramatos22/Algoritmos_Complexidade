#include<stdio.h>
#include<assert.h>

static int numComparacoes;         //variavel global para o numero de comparacoes / operacoes

int func1(int a[], int n);

int main(void)
{
    int n=10;
    numComparacoes=0;
    int array0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Resultado Array0: %d\n", func1(array0, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array1[] = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10};
    printf("Resultado Array1: %d\n", func1(array1, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array2[] = {1, 2, 4, 8, 5, 6, 7, 8, 9, 10};
    printf("Resultado Array2: %d\n", func1(array2, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array3[] = {1, 2, 4, 8, 16, 6, 7, 8, 9, 10};
    printf("Resultado Array3: %d\n", func1(array3, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array4[] = {1, 2, 4, 8, 16, 32, 7, 8, 9, 10};
    printf("Resultado Array4: %d\n", func1(array4, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);

    numComparacoes=0;
    int array5[] = {1, 2, 4, 8, 16, 32, 64, 8, 9, 10};
    printf("Resultado Array5: %d\n", func1(array5, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array6[] = {1, 2, 4, 8, 16, 32, 64, 128, 9, 10};
    printf("Resultado Array6: %d\n", func1(array6, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array7[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 10};
    printf("Resultado Array7: %d\n", func1(array7, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);
    
    numComparacoes=0;
    int array8[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    printf("Resultado Array8: %d\n", func1(array8, n));
    printf("Nº de operacoes: %d \n\n", numComparacoes);

}

int func1(int* a, int n)
{
    assert (n > 2);
    int res = 1;                // elemento neutro da conjuncao
    int r = a[1] / a[0];        // razao da progressão geométrica

    numComparacoes++;

    for (int i = 2; i < n; i++)
    {
        numComparacoes++;

        if (a[i] != r*a[i-1])
        {
            res = 0;
            break;
        } 
    }
    
    return res;

}