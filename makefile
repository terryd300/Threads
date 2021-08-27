a.out:		HW5.o
		gcc -o a.out HW5.o

HW5.o:		HW5.c
		gcc -c HW5.c

clean:
		rm *.o
		rm a.out
