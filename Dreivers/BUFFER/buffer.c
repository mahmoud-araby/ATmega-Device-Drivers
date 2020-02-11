#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
int main()
{
    BUFFER_WRITE ( 3 , TX );
 printf("%d \n" ,BUFFER_READ ( TX));
    BUFFER_WRITE ( 4 , TX );
    BUFFER_WRITE ( 7 , TX );
    BUFFER_WRITE ( 5 , TX );
       printf("%d \n" , BUFFER_WRITE ( 7 , TX ));
    printf("%d \n" ,BUFFER_READ ( TX));
    printf("%d \n" ,BUFFER_READ ( TX));
    printf("%d \n" ,BUFFER_READ ( TX));
    printf("%d \n" ,BUFFER_READ ( RX));
    printf("%d \n" ,BUFFER_READ ( TX));
    return 0;
}


/*
tBUFFER_ERORR BUFFER_WRITE ( tbuffer_DataType DATA , buffer_name buffer );
tbuffer_DataType
tbyte BUFFER_COUNT ( buffer_name buffer);
*/
