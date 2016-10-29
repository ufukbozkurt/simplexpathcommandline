PROG = sXPath
CC = gcc
CCFLAGS = -Wall
INCLUDE_PATHS = -I /usr/local/opt/libxml2/include/libxml2
LIB_PATHS = -L /usr/local/opt/libxml2/lib
LIBS = -lxml2
OBJS = main.o 

$(PROG) : $(OBJS)
	$(CC) $(CCFLAGS) $(LIB_PATHS) $(LIBS) -o $(PROG) $(OBJS)

main.o : main.c
	$(CC) $(INCLUDE_PATHS) -c main.c

clean:
	rm -f $(OBJS)
clean-all :
	rm -f $(PROG) $(OBJS)