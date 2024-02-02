memory-test:	memory-test.o memory.o
				gcc memory-test.o memory.o -o memory-test
memory-test.o: 	memory-test.c
				gcc -c memory-test.c
memory.o:		memory.c
				gcc -c memory.c
clean:		
				rm memory.o memory-test.o memory-test