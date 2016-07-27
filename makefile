CC = g++
CFLAGS = -Wall -g

INCLUDES = -I ~/boost
LFLAGS = 
LIBS = 

SRCS = Integrator.cpp MainLoop.cpp Output.cpp ParamManager.cpp SimManager.cpp Particle.cpp
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
