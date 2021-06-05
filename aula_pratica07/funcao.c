#include<stdio.h>

int counter=0;          // variavel global -> contador de operacoes
//int valores[200];       // array valores que guarda os valores das multiplicacoes feitas anteriormente pela funcao dinamica  

int funcaoRecursiva (unsigned int n)
{
    int result=0;
    if (n==0 || n==1 || n==2)
    {
        result = 1;
    }
    else
    {
        int k;
        int sum=0;
        for (k = 0; k <= n-3; k++)
        {
            counter++;
            sum += funcaoRecursiva(k)*funcaoRecursiva(n-3-k);
        }
        result = funcaoRecursiva(n-1) + funcaoRecursiva(n-2) + sum;
    }
    return result;
}

int funcaoIterativa (unsigned int n)
{
    int valores[n+1];
    valores[0] = 1;
    valores[1] = 1;
    valores[2] = 1;
    int result = 0;

    if (n==0 || n==1 || n==2)
    {
        return valores[n];
    }
    if (n>2)
    {
        //int res = 0;
        for (int i = 3; i <= n; i++)
        {
            result = valores[i-1] + valores[i-2];
            for (int k = 0; k <= i-3; k++)
            {
                counter++;
                result += valores[k] * valores[i-3-k];
            }
            
            valores[i] = result;
        }
        
    }
    
    return result;

}

int main(void)
{
    printf("Funcao Recursiva: \n");
    for (int i = 0; i <= 25; i++)
    {
        counter = 0;
        int res = funcaoRecursiva(i);
        printf("n= %d   | resultado= %d   | Num_Ops: %d \n", i, res, counter);
    }

    printf("\n");
    printf("Funcao Iterativa: \n");
    for (int i = 0; i <= 25; i++)
    {
        counter = 0;
        int res = funcaoIterativa(i);
        printf("n= %d   | resultado= %d   | Num_Ops: %d \n", i, res, counter);
    }
    
    return 0;
}