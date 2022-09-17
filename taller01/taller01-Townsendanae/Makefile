GCC=gcc
CFLAGS=-c -I.

programa: main.o functions.o
	$(GCC) -o programa  main.o functions.o

main.o: main.c functions.h
	$(GCC) $(CFLAGS) main.c 

functions.o: functions.c functions.h
	$(GCC) $(CFLAGS) functions.c 


.PHONY: clean
clean:
	rm -f *.o programa


