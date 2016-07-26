CC = g++
CFLAGS = -Wall -g

INCLUDES = 
LFLAGS = 
LIBS = 

SRCS = main.cpp input.cpp
OBJS = $(SRCS:.c=.o)
MAIN = nbody

.PHONY: depend clean

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
