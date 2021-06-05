#include <stdio.h>
#include <math.h>
#include "elapsed_time.h"

//variavel que conta o numero de iteracoes
static long it = 0;

//solucao recursiva
int fibo1 (int n) 
{
    int res, i;

    for ( i = 0; i <= n; i++)
    {
        if (n == 0)
        {
            res = 0;
        }
        else if (n == 1)
        {
            res = 1;
        }
        else
        {
            res = 3*(fibo1(n-1)) + 2*(fibo1(n-2));
            it += 2;        // quando ja tem pelo menos 2 iterações
        }        
    }

    printf("%ld iteracoes\n", it);
    return res;
    
}

//solucao iterativa- ordem de complexidade: O(n) -> linear
int fibo2 (int n) 
{
    it = 0;
    int i, res;

    int p0 = 0;
    int p1 = 1;

    for ( i = 0; i <= n; i++)
    {
        res = 3*p1 + 2* p0; // terceiro valor (q depois passa a ser o quarto valor)
        p1 = p0;            // o valor do primeiro passa a ser o segundo valor
        p0 = res;           // o segundo valor passa a ser o terceiro 
        it += 2;            
    }

    printf("%ld iteracoes\n", it);
    return res;
    
}

// equacao de recorrencia
int fibo3 (int n)
{
    int i;
    double res;

    for ( i = 0; i <= n; i++)
    {
        double r1 = pow((0.5)*(3+sqrt(17)),i);
        double r2 = pow((0.5)*(3-sqrt(17)),i);
        res = (r1 - r2) / sqrt(17);
        it += 2;
    }

    printf("%ld iteracoes\n", it);
    return res;
    
}

// termo mais importante da equacao de recorrencia
int fibo4 (int n)
{
    int i;
    double res;

    for ( i = 0; i <= n; i++)
    {
        double r1 = pow((0.5)*(3+sqrt(17)),i);
        double r2 = 1/(sqrt(17));
        res = round(r2 * r1);
        it += 2;
    }


    printf("%ld iteracoes\n", it);
    return res;
    
}

// formula fechada usando a funcao exponencial
int fibo5 (int n)
{
    it = 0;
    int i;
    double c1 = 0.24253562503633297352;
    double c2 = 1.27019663313689157536;
    double res;

    for ( i = 0; i <= n; i++)
    {
        res = round(c1 * exp(c2 * i));
        it++;
    }

    printf("%ld iteracoes\n", it);
    return res;
    
}


//funcao main

int main(void)
{
    it = 0;
    elapsed_time();

    int res1 = fibo1(5);
    double time1 = elapsed_time();
    printf("Fibo1: %d\t %f \n",res1,time1);
    printf("\n");

    int res2 = fibo2(5);
    double time2 = elapsed_time();
    printf("Fibo2: %d\t %f \n",res2,time2);
    printf("\n");

    int res3 = fibo3(5);
    double time3 = elapsed_time();
    printf("Fibo3: %d\t %f \n",res3,time3);
    printf("\n");

    int res4 = fibo4(5);
    double time4 = elapsed_time();
    printf("Fibo4: %d\t %f \n",res4,time4);
    printf("\n");

    int res5 = fibo5(5);
    double time5 = elapsed_time();
    printf("Fibo5: %d\t %f \n",res5,time5);
    printf("\n");

}