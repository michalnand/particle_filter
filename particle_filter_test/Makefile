ELF = bin/particle_filter.elf


INC+= -I.
INC+= -I../libs_particle_filter


LIBS+= ../libs_particle_filter/libs_particle_filter.a


CC = g++
LD = g++
OBJCOPY = objcopy
OBJDUMP = objdump
SIZE = size

# DEGUBFLAGS = -g -pg

CFLAGS = $(DEGUBFLAGS) -O2 -Os -s -Wall -Wextra -pedantic -std=c++11 $(INC)

LD_OPENGLFLAGS = -lglut -lGL -lGLU -lX11
#LD_CUDAFLAGS 	 = -L/usr/local/cuda/lib64 -lcuda -lcudart
#LD_COMMONFLAGS = -ljsoncpp 

LDFLAGS = $(DEGUBFLAGS) -lm -lpthread -pthread -std=c++11 $(LD_OPENGLFLAGS) $(LD_COMMONFLAGS) $(LD_CUDAFLAGS)


SRCS+= $(shell find -name '*.cpp')

OBJS = $(SRCS:.cpp=.o)

all: $(ELF)
	$(SIZE) $(ELF)

$(ELF): $(LIBS) $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm $(OBJS) -rf
	rm $(OBJS_CUDA) -rf
	rm $(ELF) -rf
