//*************************
 * Anthony Hay Jr.  
 * CPSC 2311 Summer 25
 * adhay@clemson.edu
 *************************/
 
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

OBJS = ppmDriver.c ppmUtil.c
EXEC = ppmDriver

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

clean:
	rm -f $(EXEC) *.o output1.ppm output2.ppm
