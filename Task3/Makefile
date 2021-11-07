default: solution

solution: solution.o
	gcc -pthread solution.o -o solution

solution.o: solution.c
	gcc -c -pthread solution.c

clean:
	rm -f *.o solution