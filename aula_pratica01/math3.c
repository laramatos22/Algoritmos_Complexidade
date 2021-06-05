#include<stdio.h>
#include<math.h>

int main ( void )
{
    int i;
    printf( "Number | Square | Square Root\n" );

    for (i = 0; i <= 10; i++)
    {
        printf( " %4d  |  %5d |   %.2f\n", i, (i*i), sqrt((i)) );
    }

    return 0;

}