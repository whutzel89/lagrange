#############################################################################################
# Compiler commands and flags
#
#	Flag notes:
#	-g = debugging infor
#	-Wall = Turns on most compiler warnings
#############################################################################################

CC = gcc

CFLAGS = -g -Wall

#############################################################################################
# This next section is for libraries, local includes, and linker flags
#############################################################################################

LIBS =

LFLAGS = -L/usr/local/lib -lclapack -lcblas

INCLUDES = -I/Users/whutzel/local_code/development/c_code/lagrange_interp/lagrange/

##############################################################################################
#	Define source
#	$(SRCS) = these are source files
#	$(OBJS) = These are dependencis or *.o files made from sources
#	$(EXES) = These are the executables to be generated
#############################################################################################

SRCS = 	lagrange.c\
	fnc_lagrange.c

OBJS =	$(SRCS:.c=.o)

EXES = 	lagrange
#############################################################################################
# The next lnes are meant to be generic, modifying above, you can make any executable from
# these commands.
#############################################################################################

.PHONY: depend clean

all: $(EXES)
	@echo

$(EXES): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXES) $(OBJS) $(LFLAGS) $(LIBS)

#############################################################################################
# This next portion deals with the automatic variables. I do not fully understand this
# portion
#############################################################################################
%.o : %.c
	$(CC) $(CLFAGS) $(INCLUDES) -c  $<
#@echo

clean:
	$(RM) *.o *~ $(EXES)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
