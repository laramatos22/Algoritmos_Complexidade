#include<stdio.h>
#include<assert.h>

int numOperacoes;           //variavel global que indica o numero de operacoes
int numCopias;              //variavel global que indica o numero de vezes que um numero aparece repetido


void func2(int a[], int* n);

int main (void)
{

    int n = 10;

    numOperacoes = 0;
    numCopias=0;
    int array0[] = {2, 2, 2, 3, 3, 4, 5, 8, 8, 9};  //Array Final: {2, 3, 5}
    printf("Array0: \n");
    func2(array0, &n);

    n=10;
    numOperacoes = 0;
    numCopias=0;
    int array1[] = {7, 8, 2, 2, 3, 3, 3, 8, 8, 9};  //Array Final: {7, 8, 3}
    printf("Array1: \n");
    func2(array1, &n);

    n=10;
    numOperacoes = 0;
    numCopias=0;
    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  //Array Final: {1}
    printf("Array2: \n");
    func2(array2, &n);

    n=10;
    numOperacoes = 0;
    numCopias=0;
    int array3[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};  //Array Final: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
    printf("Array3: \n");
    func2(array3, &n);

    n=10;
    numOperacoes = 0;
    numCopias=0;
    int array4[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};  //Array Final: {1}
    printf("Array4: \n");
    func2(array4, &n);

}

/**Pretende-se eliminar os elementos da sequência que sejam iguais ou múltiplos ou submúltiplos
de algum dos seus predecessores, sem fazer a sua ordenação e sem alterar a posição relativa dos
elementos.*/

void func2(int* a, int* n) 
{
    int s = *n;
    assert (s > 1);
    //int s = *n;

    for (int i = 0; i < s; i++)
    {
        for (int j = i+1; j < s; )
        {
            numOperacoes++;

            if ((a[j] % a[i]) == 0 )
            {
                numCopias++;

                for (int k = j; k < s; k++)
                {
                    a[k] = a[k+1];
                }
                s--;        //retira valor 
            } else {

                if(a[i]%a[j]== 0) {
                    numCopias++;

                    for (int k = j; k < s; k++)
                    {
                        a[k] = a[k+1];
                    }
                    s--;        //diminui o tamanho do array
                }
                else
                {
                    j++;        //acrescenta valor
                }
            } 
            
        }
    }
    
    *n = s;

    //Para imprimir o array alterado:
    printf("Array Final: ");
    printf("{ ");
    for (int x = 0; x < *n; x++)
    {
        printf("%d ", a[x]);
    }
    printf("}\n");
    
    printf("Total de copias: %d \n", numCopias);
    printf("Numero de Operacoes: %d \n\n", numOperacoes);

}

