/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
**========================================================================
*/
#ifndef RING_H
#define RING_H

typedef struct{
    char *Buffer;
    int Length;
    int Ini;
    int Outi;
} ring_t;

ring_t *init( int length );
int insert( ring_t *ring, char data );
int r_remove( ring_t *ring, char *data );
int entries( ring_t *ring );

#endif