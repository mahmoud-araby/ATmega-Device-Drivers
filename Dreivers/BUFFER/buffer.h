#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

typedef char tbyte ;

#define BUFFER_TX_SIZE 3
#define BUFFER_RX_SIZE 4
typedef char tbuffer_DataType ;

typedef enum {
    BUFFER_OK ,
    BUFFER_FULL = -3,
    BUFFER_EMPTY= -2,
    BUFFER_ERROR= -1
}tBUFFER_ERORR;

typedef enum {
TX ,
RX  }buffer_name;

tBUFFER_ERORR BUFFER_WRITE ( tbuffer_DataType DATA , buffer_name buffer );
tbuffer_DataType BUFFER_READ ( buffer_name buffer);
tbyte BUFFER_COUNT ( buffer_name buffer);


#endif // BUFFER_H_INCLUDED
