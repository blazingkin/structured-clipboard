CC=gcc
CFLAGS=-ansi -Wall -pedantic -g -Og

FILES=clip
SOURCE_FOLDER=src

OBJECTS=$(addsuffix .o, $(FILES))
C_FILES=$(addprefix $(SOURCE_FOLDER)/, $(addsuffix .c, $(FILES)))
HEADERS=$(addprefix $(SOURCE_FOLDER)/, $(addsuffix .h, $(FILES)))

all: clip clean

clean:
	-rm *.o

clip: $(OBJECTS)

%.o: $(addprefix $(SOURCE_FOLDER)/, %.c)
	$(CC) -c -o $@ $< $(CFLAGS)