#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_OF_THREADS 6

long sum = 0;
long primeCounter = 0;
int numOfRandomNumbers = 0;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int isPrime(int n)
{
	// Corner cases
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;

	// This is checked so that we can skip
	// middle five numbers in below loop
	if (n % 2 == 0 || n % 3 == 0)
		return 0;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;

	return n;
}



void *myThreadFun()
{
	//generate random numbers
	for (int i = 0; i < numOfRandomNumbers/NUM_OF_THREADS ; i++)
	{	
		//init rundom generator
		int rnd = rand();
		//check if the number is prime
		if (isPrime(rnd))
		{
			pthread_mutex_lock(&mutex);
			//if do, add up it's sum, and increment counter
			primeCounter++;
			sum += rnd;
			pthread_mutex_unlock(&mutex);
		}
	}

    return NULL;
}
   
int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		printf("Too few arguments ");
		printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
		exit(0);
	}

	int randomPivot = atoi(argv[1]);
	numOfRandomNumbers = atoi(argv[2]);

	srand(randomPivot);

	pthread_t thr[NUM_OF_THREADS];
    
    	for(int n = 0; n < NUM_OF_THREADS; n++)
        	pthread_create(&thr[n],NULL, myThreadFun, NULL);
	
	for(int n = 0; n < NUM_OF_THREADS ; n++)
		pthread_join(thr[n], NULL);

	printf("%ld,%ld\n", sum, primeCounter);
    pthread_exit(NULL);
}
