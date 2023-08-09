# Parallel-Erastothenes-Sieve
This is a parallel implementation of the classic Eratosthenes Sieve to find prime numbers.

### Authors
Guilherme, Gustavo, Matheus, Victor

## Compiling
```bash
$ gcc -o name_of_executable -fopenmp -lm sieve_par.c
```

## Running
```bash
$ ./name_of_executable max_integer_n
```
Where `max_integer_n` is the maximum value wanted to check for primes.

## Example
To compile and check for primes on the closed interval [2, 30]:
```bash
$ gcc -o sieve -fopenmp -lm sieve_par.c
$ ./sieve 30
```
