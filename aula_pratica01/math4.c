#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main( void ) 
{
    // O utilizador deve indicar o menor valor e o maior valor do ângulo, e o espaçamento entre
    // sucessivos valores intermédios
    int min, max, esp;
    printf( "ângulo: menor e maior valores\n" );
    printf( "Menor:" );
    scanf( "%d", &min );
    printf( "Maior: " );
    scanf( "%d", &max );
    printf( "Espaçamento: " );
    scanf( "%d", &esp );

    double val = PI/180;
    FILE *file;
    file = fopen("file4.txt", "w"); //abrir ficheiro

    if (file == NULL)
    {
        printf( "Ficheiro não existe!" );
    }

    printf("\n");
    printf("  ang  sing(ang)   cos(ang)\n");
    fprintf(file,"  ang  sin(ang)   cos(ang)\n");
	printf("---- --------   --------\n");
	fprintf(file,"---- --------   --------\n");

    int i;
    for ( i = min; i <= max ; i++)
    {
        printf(" %2d | %f  | %f\n",i,sin(i*val),cos(i*val)); //aparece no terminal
		fprintf(file, " %2d | %f  | %f\n",i,sin(i*val),cos(i*val)); //escreve no ficheiro
    }
    
    fclose(file);

    return 0;

}