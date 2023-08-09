/* ----------------------------------------------------------------------------
    This is a parallel implementation of the classic
    Eratosthenes Sieve to find prime numbers

    Implemented by:
        Guilherme, Gustavo, Matheus, Victor

    To compile: $ gcc -o name_of_executable -fopenmp -lm sieve_par.c

    To run: $ ./name_of_executable max_integer_n
    where max_integer_n is the maximum value wanted to check for primes

    Example:
        $ gcc -o sieve -fopenmp -lm sieve_par.c
        $ ./sieve 30
    (will compile and check for primes on the closed interval [2, 30])
---------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UNMARKED '0'
#define MARKED '1'

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s max_integer_n\n", argv[0]);
        return -1;
    }

    int i, primes_counter=0, my_prime, last_prime=1;

    // Binds argv[1] (our upper boundary) to another variable for better readability.
    // The "plus one" is here because we are considering the closed interval
    // between 2 and the number passed
    int n = atoi(argv[1]) + 1;

    // Allocates the "boolean" vector
    char* vector = (char *) malloc (n * sizeof(char));

    // Sets every element of the vector as UNMARKED
    // Starts with 2 since we don't use the positions 0 and 1 of this vector
    for(i = 2; i < n; i++)
        vector[i] = UNMARKED;

    // All threads access the vector and the last_prime integer;
    // however each one of them has a private loop index (i) and a current prime to iterate (my_prime)
    #pragma omp parallel shared(vector, last_prime) private(i, my_prime)
    {
        while(last_prime <= sqrt(n)){
            // Finds the first number still UNMARKED in the vector
            for(i = last_prime + 1; i < n; i++){
                if(vector[i] == UNMARKED){
                    last_prime = my_prime = i;
                    break;
                }
            }

            // Marks the multiples of my_prime starting with my_prime²
            for(i = pow(my_prime, 2); i < n; i += my_prime)
                vector[i] = MARKED;
        }
    }

    // Prints the results (i.e., the numbers still UNMARKED)
    printf("Primes on the interval [2, %d]:\n", n-1);
    for(i = 2; i < n; i++){
        if(vector[i] == UNMARKED){
            printf("%d ", i);
            primes_counter++;
        }
    }
    printf("\n%d primes found.\n", primes_counter);

    free(vector);
    return 0;
}
