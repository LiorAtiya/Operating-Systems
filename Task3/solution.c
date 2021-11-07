#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// global variables
const int num_of_threads = 6;
long sum = 0;
long primeCounter = 0;
int numOfRandomNumbers = 0;
int randomPivot = 0;

pthread_mutex_t mutex;

int isPrime(int num)
{
    // edge cases
    if (num <= 1)
        return 0;
    if (num <= 3)
    {
        return 1;
    }

    if (num % 2 == 0 || num % 3 == 0)
    {
        return 0;
    }

    for (int i = 5; i * i <= num; i = i + 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }

    return 1;
}

void *generate()
{
    for (int i = 0; i < numOfRandomNumbers / num_of_threads; i++)
    {
        //generate a random number
        int random = rand();

        //check if the number is prime
        if (isPrime(random))
        {
            pthread_mutex_lock(&mutex);
            // add up it's sum, and increment counter
            sum += random;
            primeCounter++;
            pthread_mutex_unlock(&mutex);
        }
    }
}

int main(int argc, char *argv[])
{
    // check if the input is valid 
    if (argc != 3)
    {
        printf("Too few arguments ");
        printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
        exit(0);
    }

    randomPivot = atoi(argv[1]);
    numOfRandomNumbers = atoi(argv[2]);
    srand(randomPivot);
    pthread_t threads[num_of_threads];
    pthread_mutex_init(&mutex, NULL);

    // creating the threads
    for (int i = 1; i <= num_of_threads; i++)
    {
        if (pthread_create(threads + i, NULL, &generate, NULL) != 0)
        {
            perror("Failed to create a thread");
            return i;
        }
    }

    // waiting until all the threads will finish 
    for (int i = 1; i <= num_of_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            return num_of_threads + i;
        }
    }

    pthread_mutex_destroy(&mutex);


    // printing the result 
    printf("%ld,%ld\n", sum, primeCounter);

    exit(0);
}
