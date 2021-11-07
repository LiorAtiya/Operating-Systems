
default: main1_1 main1_2 main1_3

main1_1: main1_1.o hello_ariel.o
	gcc main1_1.o hello_ariel.o -o main1_1

main1_2: main1_2.o libHelloAriel.so
	gcc -o main1_2 main1_2.o -L. ./libHelloAriel.so

main1_3: main1_3.o libHelloAriel.so
	gcc main1_3.c -fPIC -ldl -o main1_3

libHelloAriel.so: hello_ariel.o hello_ariel.h
	gcc -shared -o libHelloAriel.so -fPIC hello_ariel.o

main1_1.o: main1_1.c hello_ariel.h
	gcc -c main1_1.c

main1_2.o: main1_2.c hello_ariel.h
	gcc -c main1_2.c

hello_ariel.o: hello_ariel.c
	gcc -c hello_ariel.c

clean:
	rm -f *.o *.so main1_1 main1_2 main1_3
