# G BRENT HURST
# Makefile for NumberConversion

CC = g++
LANGUAGE = cpp
CFLAGS = -Wall

INCLUDEDIR = $(HOME)/include
HEADERDIR = $(INCLUDEDIR)/headers

NAME = "NumberConversion"

ARCHIVE = $(INCLUDEDIR)/lib$(NAME).a
HEADER = $(HEADERDIR)/$(NAME).h
OBJECTS = RomanNumeral.o

all: $(ARCHIVE)

$(ARCHIVE): $(OBJECTS)
	ar -vr $(ARCHIVE) $(OBJECTS)

%.o: %.$(LANGUAGE) $(HEADER)
	$(CC) $(CFLAGS) -c $*.$(LANGUAGE)

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: cleanall
cleanall:
	rm -f $(OBJECTS) $(ARCHIVE)
