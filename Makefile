# -*- makefile -*-
CC=gcc
AR=ar
OBJECTS_mainisort=mainisort.o
OBJECTS_isort=isort.o
OBJECTS_maintxtfind=maintxtfind.o
OBJECTS_txtfind=txtfind.o
FLAGS= -Wall -g

all: libmylib libmylib2 isort txtfind

libmylib: $(OBJECTS_isort)
	$(AR) -rcs libmylib $(OBJECTS_isort)	
       
isort: $(OBJECTS_isort) $(OBJECTS_mainisort) 
	$(CC) $(FLAGS) -o isort $(OBJECTS_isort) $(OBJECTS_mainisort) 	

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c
	
mainisort.o: mainisort.c isort.h  
	$(CC) $(FLAGS) -c mainisort.c





libmylib2: $(OBJECTS_txtfind)
	$(AR) -rcs libmylib2 $(OBJECTS_txtfind)	
       
txtfind: $(OBJECTS_txtfind) $(OBJECTS_maintxtfind) 
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_txtfind) $(OBJECTS_maintxtfind) 	

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c
	
maintxtfind.o: maintxtfind.c txtfind.h  
	$(CC) $(FLAGS) -c maintxtfind.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind

