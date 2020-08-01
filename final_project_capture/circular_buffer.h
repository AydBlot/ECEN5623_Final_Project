/*
 * aesd-circular-buffer.h
 *
 *  Created on: March 1st, 2020
 *      Author: Dan Walkes
 */

#ifndef CIRCULAR_BUFFER_H 
#define CIRCULAR_BUFFER_H 

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stddef.h> // size_t
#include <stdint.h> // uintx_t
#include <stdbool.h>
#include <time.h>
#endif

//#define AESDCHAR_MAX_WRITE_OPERATIONS_SUPPORTED 10
#define CIRCULAR_BUFFER_SIZE 16
#define PIXEL_BUF_LENGTH 614400

struct buffer 
{
        void   *start;
        size_t  length;
	
	//timespec for frame time
	struct timespec *time;
};

struct aesd_circular_buffer
{
	/**
	 * An array of pointers to memory allocated for the most recent write operations
	 */
	struct buffer *pixel_data[CIRCULAR_BUFFER_SIZE];
	/**
	 * The current location in the entry structure where the next write should
	 * be stored.
	 */
	uint8_t in_offs;
	/**
	 * The first location in the entry structure to read from
	 */
	uint8_t out_offs;
	/**
	 * set to true when the buffer entry structure is full
	 */
	bool full;

};

extern void aesd_circular_buffer_add_entry(struct aesd_circular_buffer *buffer, struct buffer *add_entry, int buffer_size);

extern void aesd_circular_buffer_init(struct aesd_circular_buffer *buffer);

extern uint8_t get_current_entry_location(struct aesd_circular_buffer *buffer);

/**
 * Create a for loop to iterate over each member of the circular buffer.
 * Useful when you've allocated memory for circular buffer entries and need to free it
 * @param entryptr is a struct aesd_buffer_entry* to set with the current entry
 * @param buffer is the struct aesd_buffer * describing the buffer
 * @param index is a uint8_t stack allocated value used by this macro for an index
 * Example usage:
 * uint8_t index;
 * struct aesd_circular_buffer buffer;
 * struct aesd_buffer_entry *entry;
 * AESD_CIRCULAR_BUFFER_FOREACH(entry,&buffer,index) {
 * 		free(entry->buffptr);
 * }
 */
#define AESD_CIRCULAR_BUFFER_FOREACH(entryptr,buffer,index) \
	for(index=0, entryptr=&((buffer)->entry[index]); \
			index<AESDCHAR_MAX_WRITE_OPERATIONS_SUPPORTED; \
			index++, entryptr=&((buffer)->entry[index]))



#endif /* CIRCULAR_BUFFER_H */
