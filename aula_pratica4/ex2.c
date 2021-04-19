#include<stdio.h>
#include<assert.h>

// array [k] = array [i] + array [j], para i < j < k

int numComparacoes;     //variavel global

int sequenciaArray(int *array, int length);

int main(void)
{
    int array[10] = {0,0,0,0,0,0,0,0,0,0};

    int len = 10;
    numComparacoes = 0;

    printf("Resultado: %d \n", sequenciaArray(array, len));
    printf("Número de comparações: %d\n", numComparacoes);
}

int sequenciaArray(int *array, int n)
{
    assert (n > 2);
    int res = 0;

    for (int k = 2; k < n; k++)
    {
        for (int j = 1; j < k; j++)
        {
            for (int i = 0; i < j; i++)
            {
                numComparacoes++;
                if (array [k] == array [i] + array [j])
                {
                    res++;
                }
            }
        }
    }

    return res;

}