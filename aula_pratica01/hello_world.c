#include<stdio.h>

int main ( void )
{
    char name[50]; //declarar uma string com 50 caracteres

    puts(  "Hello World!" );

    puts ( "What is your name?" );
    fgets (name, 50, stdin);
    printf ( "Hello %s !\n", name);

    puts( "What is your first name?" );
    scanf ( "%s", name ); //quando aparece um espaço no scanf ele só lê a 1ª palavra

    return 0;
}
