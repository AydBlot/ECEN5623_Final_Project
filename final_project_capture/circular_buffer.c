/**
 * @file aesd-circular-buffer.c
 * @brief Functions and data related to a circular buffer imlementation
 *
 * @author Dan Walkes
 * @date 2020-03-01
 * @copyright Copyright (c) 2020
 *
 */

#ifdef __KERNEL__
#include <linux/string.h>
#else
#include <string.h>
#include <stdio.h>
#include <time.h>
#endif

#include "circular_buffer.h"
#include <stdlib.h>
#include <linux/videodev2.h>


//Inline allows this function to be placed inside a .h file to be used by other files, if not placed the static function could not be placed anywhere else
static inline uint8_t aesd_circular_buffer_next_offs(uint8_t offs){
	if(++offs >= CIRCULAR_BUFFER_SIZE){
		offs = 0;
	} 
	return offs;
}

/**
* Adds entry @param add_entry to @param buffer in the location specified in buffer->in_offs.
* If the buffer was already full, overwrites the oldest entry and advances buffer->out_offs to the
* new start location.
* Any necessary locking must be handled by the caller
* Any memory referenced in @param add_entry must be allocated by and/or must have a lifetime managed by the caller.
*/
void aesd_circular_buffer_add_entry(struct aesd_circular_buffer *buffer, struct buffer *add_entry, int buffer_size)
{

    /**
    * TODO: implement per description 
    */
	//First account for the fact that the buffer could go past 10 entries
	/*
	if( (buffer->in_offs + 1) > AESDCHAR_MAX_WRITE_OPERATIONS_SUPPORTED){
		buffer->in_offs = 0;	
		buffer->full = true;
	}
	if( (buffer->out_offs + 1) > AESDCHAR_MAX_WRITE_OPERATIONS_SUPPORTED){
		buffer->out_offs = 0;
	}
	*/
	//---Account for a full buffer---
	if((buffer->full == true) ){
		//printf("MADE IT TO FULL\r\n");
		//buffer->pixel_data[buffer->in_offs] = add_entry;
		//buffer->pixel_data[buffer->in_offs]->start = malloc(buffer_size);
	        memcpy(buffer->pixel_data[buffer->in_offs]->start, add_entry->start, buffer_size);
		//call static inline lecture 17 slide 10
		buffer->in_offs = aesd_circular_buffer_next_offs(buffer->in_offs);
		buffer->out_offs = aesd_circular_buffer_next_offs(buffer->out_offs);
		//printf("buff in pos:%d\r\n", buffer->in_offs);
		//printf("buff out pos:%d\r\n", buffer->in_offs);
		//buffer->in_offs++;
		//buffer->out_offs++;
	}
	else{
		//buffer->pixel_data[buffer->in_offs] = add_entry;
		//buffer->pixel_data[buffer->in_offs]->start = malloc(buffer_size);
		printf("made mempy circular buffer\r\n");
	        memcpy(buffer->pixel_data[buffer->in_offs]->start, add_entry->start, buffer_size);
		clock_gettime(CLOCK_REALTIME, buffer->pixel_data[buffer->in_offs]->time);
		buffer->in_offs = aesd_circular_buffer_next_offs(buffer->in_offs);
		
		//buffer->in_offs++;		
		//if in==ofss set true
		if(buffer->in_offs == buffer->out_offs){
			buffer->full = true;
		}
	}
}

/**
* Initializes the circular buffer described by @param buffer to an empty struct
*/
void aesd_circular_buffer_init(struct aesd_circular_buffer *buffer)
{
    struct v4l2_buffer buf;
    struct buffer *buffers;
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;

    memset(buffer,0,sizeof(struct aesd_circular_buffer));
    for(int i = 0; i<CIRCULAR_BUFFER_SIZE; i++){
    	buffer->pixel_data[i] = calloc(1, sizeof(*buffers));	
    	buffer->pixel_data[i]->start = malloc(153600);
        buffer->pixel_data[i]->time = malloc(sizeof(struct timespec));	
    }
}
