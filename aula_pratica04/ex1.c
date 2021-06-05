# include<stdio.h>
# include<assert.h>

// array [i] =array [i–1]+ array [i + 1], para 0 < i < (n –1)

int numComparacoes;     //variavel global para o numero de comparacoes/operacoes

int somaArray(int array[], int n);

int main(void)
{
    int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int len = 10;
    numComparacoes = 0; //para reiniciar no final de um "ciclo"

    printf("Resultado: %d \n", somaArray(array, len));
    printf("Número de comparações: %d\n", numComparacoes);
    
}

int somaArray(int* array, int n)
{
    assert (n > 2);
    int res = 0;
    //numComparacoes = 0;

    for (int i = 1; i < (n - 1); i++)
    {
        numComparacoes++;
        if (array[i] == array[i-1] + array[i+1]) // se a propriedade se verificar
        {
            res++;
        }
    }
    return res;
    
}

