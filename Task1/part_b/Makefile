default: main2_1 main2_2 main2_3 main2_4

main2_1: main2_1.o
	gcc main2_1.o -o main2_1

main2_2: main2_2.o
	gcc main2_2.o -o main2_2

main2_3: main2_3.o
	gcc main2_3.o -o main2_3

main2_4: main2_4.o
	gcc main2_4.o -o main2_4

main2_1.o: main2_1.c
	gcc -c main2_1.c

main2_2.o: main2_2.c
	gcc -c main2_2.c

main2_3.o: main2_3.c
	gcc -c main2_3.c

main2_4.o: main2_4.c
	gcc -c main2_4.c

clean:
	rm -f *.o main2_1 main2_2 main2_3 main2_4
