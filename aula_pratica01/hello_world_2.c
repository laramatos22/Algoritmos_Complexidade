#include<stdio.h>

int main ( void )
{
    char name[50]; //declarar uma string com 50 caracteres

    puts ( "What is your name?" );
    scanf( "%[^\n]", name ); 
    printf( "Hello %s !!\n", name );

    return 0;
}