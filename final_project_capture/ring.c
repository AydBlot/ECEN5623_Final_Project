/*========================================================================
** Circular buffer
** 
*========================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <ring.h>

pthread_t threads[2];
ring_t *ring = NULL;
int data = 0; 
int info = 1;

ring_t *init( int length )
{
    ring_t *ring = malloc(sizeof(int)*length);
    
    ring->Buffer = malloc(sizeof(ring_t));
    ring->Length = length;
    ring->Ini = 0;
    ring->Outi = 0;
    
    return (ring);
}

int insert( ring_t *ring, int data )
{
    int iniPlus = ring->Ini + 1;
    int ret = -1;
    
    if (iniPlus >= ring->Length ) iniPlus = 0;
    if (iniPlus != ring->Outi)
    {
        ring->Buffer[ring->Ini] = data;
        ring->Ini = iniPlus;
        ret = 0;
        printf("\nIni = %d, data = %d", ring->Ini, ring->Buffer[ring->Ini - 1]);
    }
    else 
    {
        printf("\nBuffer is full");
    }
    
    return ret;
}

int r_remove( ring_t *ring, int *data )
{
    int ret = 0;
    
    if(ring == NULL) 
    {
        ret = -1;
        printf("No buffer initialized");
    }
    else
    {
        *data = ring->Buffer[ring->Outi];
        ring->Outi = (ring->Outi+1) % ring->Length;
        printf("\ndata removed = %d", *data);
    }
    
    return ret;
}

int entries( ring_t *ring )
{
    int number = 0;
    
    if (ring->Ini >= ring->Outi)
    {
        number = ring->Ini - ring->Outi;
        //printf("\nNumber of chars in buffer = %d", number);
        return number;
    }
    else
    {
        number = (ring->Ini + ring->Length) - ring->Outi;
        //printf("\nNumber of chars in buffer = %d", number);
        return number;
    }
}

void *dataadd(void *threadp)
{
	for(info = 1; info <= 100; info++) 
	{
		usleep(rand());
		insert(ring, info);	
	}

}

void *dataprint(void *threadp)
{
	int count = 0;

	while (count<100)
	{
		if (ring->Ini != ring->Outi)
		{
			r_remove(ring, &data);
		}
	}

}

int main(void)
{

	ring = init(100);
	if (ring == 0){printf("ring failed")};

	int rc = pthread_create(&threads[0], NULL, dataadd, NULL);
	if (rc) {printf("ERROR; pthread_create() rc is %d\n", rc); perror(NULL); exit(-1);}
   	printf("Thread 1 spawned\n");

	usleep(100000);

	rc = pthread_create(&threads[1], NULL, dataprint, NULL);
  	if (rc) {printf("ERROR; pthread_create() rc is %d\n", rc); perror(NULL); exit(-1);}
   	printf("Thread 2 spawned\n");

	if(pthread_join(threads[0], NULL) == 0)
       	printf("Thread 1: %x done\n", (unsigned int)threads[0]);
     	else perror("Thread 1");

  	if(pthread_join(threads[1], NULL) == 0)
     	printf("Thread 2: %x done\n", (unsigned int)threads[1]);
   	else perror("Thread 2");
	

}
