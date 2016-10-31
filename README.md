# Parallel-Erastothenes-Sieve

This is a parallel implementation of the classic
    Eratosthenes Sieve to find prime numbers
    Implemented by:
        Guilherme Zanardo Borduchi  NUSP 8937458
        Gustavo Ferreira Ceccon     NUSP 8936822
        Matheus Henrique Soares     NUSP 8066349
        Victor Hugo Heclis          NUSP 8937382
    To compile: $ gcc -o name_of_executable -fopenmp -lm sieve_par.c
    To run: $ ./name_of_executable max_integer_n
    where max_integer_n is the maximum value wanted to check for primes
    Example:
        $ gcc -o sieve -fopenmp -lm sieve_par.c
        $ ./sieve 30
    (will compile and check for primes on the closed interval [2, 30])
