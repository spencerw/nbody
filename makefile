CC = g++
CFLAGS = -Wall -g

STRUCTURES_PATH = ../utility/structures

INCLUDES = -I ../utility/structures
LFLAGS = 
LIBS = $(STRUCTURES_PATH)/libTipsy.a

SRCS = Integrator.cpp MainLoop.cpp Output.cpp ParamManager.cpp SimManager.cpp Particle.cpp TipsyInput.cpp
OBJS = $(SRCS:.c=.o)
MAIN = nbody

.PHONY: depend clean

all: $(MAIN)

$(MAIN): $(OBJS) $(STRUCTURES_PATH)/libTipsy.a
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

$(STRUCTURES_PATH)/libTipsy.a:
	cd $(STRUCTURES_PATH); $(MAKE) libTipsy.a

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
