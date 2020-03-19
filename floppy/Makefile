all: switchto openfile

switchto: switchto.c
	gcc -static -o $@ $<

openfile: openfile.o yourcode.o
	gcc -static -o $@ openfile.o yourcode.o

%.o: %.c openfile.h
	gcc -c -o $@ $<

clean:
	rm -f *.o switchto openfile

