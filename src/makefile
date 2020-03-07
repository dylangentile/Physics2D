CC=clang++
CFLAGS= -std=c++11 -Wall -Wextra -Weffc++ -pedantic -g -I../include
LPATH= -F/Library/Frameworks 
LIBS= -framework SDL2
MFLAGS=-DSDL_MAIN_HANDLED
RM=rm

all: game

game: main.o log.o render.o
	$(CC) $(CFLAGS) $(LPATH) $(LIBS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(MFLAGS) -o $@ -c $<


.PHONY: clean
clean:
	$(RM) *.o
	$(RM) game