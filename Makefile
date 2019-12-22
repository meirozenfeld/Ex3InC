# -*- makefile -*-
# CC=gcc
# AR=ar
# OBJECTS_mainisort=mainisort.o
# OBJECTS_isort=isort.o
# OBJECTS_maintxtfind=maintxtfind.o
# OBJECTS_txtfind=txtfind.o
# FLAGS= -Wall -g

# all: libmylib libmylib2 isort txtfind

# libmylib: $(OBJECTS_isort)
# 	$(AR) -rcs libmylib $(OBJECTS_isort)	
       
# isort: $(OBJECTS_isort) $(OBJECTS_mainisort) 
# 	$(CC) $(FLAGS) -o isort $(OBJECTS_isort) $(OBJECTS_mainisort) 	

# isort.o: isort.c isort.h
# 	$(CC) $(FLAGS) -c isort.c
	
# mainisort.o: mainisort.c isort.h  
# 	$(CC) $(FLAGS) -c mainisort.c





# libmylib2: $(OBJECTS_txtfind)
# 	$(AR) -rcs libmylib2 $(OBJECTS_txtfind)	
       
# txtfind: $(OBJECTS_txtfind) $(OBJECTS_maintxtfind) 
# 	$(CC) $(FLAGS) -o txtfind $(OBJECTS_txtfind) $(OBJECTS_maintxtfind) 	

# txtfind.o: txtfind.c txtfind.h
# 	$(CC) $(FLAGS) -c txtfind.c
	
# maintxtfind.o: maintxtfind.c txtfind.h  
# 	$(CC) $(FLAGS) -c maintxtfind.c

# .PHONY: clean all

# clean:
# 	rm -f *.o isort txtfind

all: isort txtfind

txtfind: txtfind.o maintxtfind.o
	gcc -Wall -fPIC -o txtfind maintxtfind.o txtfind.o

maintxtfind.o: maintxtfind.c txtfind.h
	gcc -Wall -c maintxtfind.c

txtfind.o: txtfind.c txtfind.h
	gcc -Wall -fPIC -c txtfind.c	

isort: isort.o mainisort.o
	gcc -Wall -fPIC -o isort mainisort.o isort.o

mainisort.o: mainisort.c isort.h
	gcc -Wall -c mainisort.c

isort.o: isort.c isort.h
	gcc -Wall -fPIC -c isort.c	

.PHONY: clean all 

clean:
	rm -f *.o isort txtfind
