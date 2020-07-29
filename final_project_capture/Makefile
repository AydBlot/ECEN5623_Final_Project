INCLUDE_DIRS = 
LIB_DIRS = 
CC=gcc

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS= -lrt -lpthread -Wall -g

HFILES= 
CFILES= final_project_capture.c circular_buffer.c 

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	final_project_continuous_transform

clean:
	-rm -f *.o *.d *.ppm *.pgm
	-rm -f final_project_continuous_transform

distclean:
	-rm -f *.o *.d

final_project_continuous_transform: final_project_capture.o circular_buffer.o
	      $(CC) $(CFLAGS) final_project_capture.o circular_buffer.o -o final_project_continuous_transform $(LIBS)

final_project_capture.c: final_project_capture.c circular_buffer.h
	$(CC) $(CFLAGS) -c final_project_capture.c 

circular_buffer: sharpen.c sharpen.h
	$(CC) $(CFLAGS) -c circular_buffer.c 
