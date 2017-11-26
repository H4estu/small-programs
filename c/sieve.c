/* 
 * sieve.c
 * Implementation of the Sieve of Eratosthenes in C.
 *
 * Usage: ./sieve <n>
 *   where <n> is an integer.  The sieve finds the number of primes 
 *   between 1 and n.
 *
 * Author: Z. Wallace
 * Last edit: 17 Sept. 2017
 */


#include <stdio.h>
#include <stdlib.h> // exit()
#include <ctype.h>  // isdigit()
#include <math.h>


void sieve(int n) {
    int i, idx, j,  k, m, total;
    int *primes;
    
    // allocate memory for prime and composite number arrays
    primes = (int *) malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++) {
	primes[i] = 1;    // initialize list as entirely  prime
    }

    for (k=1; k <= sqrt(n); k = m) {
        for (i = k+1; i < n; i++) {   // find 1st prime greater than k
	    if (primes[i] == 1) {
		m = i;
		break;
	    }
	}
	printf("First prime larger than %d: %d\n",k, m);

        for (i = 2; i <= n/m; i++) {  // mark all multiples of m as composite
	    primes[i*m] = 0;
	}
    }
	    
    // output
    total = 0;
    printf("The primes less than %d are:\n", n);
    for (idx = 1; idx < n; idx++) {
	if (primes[idx] == 1) {
	    printf("%d\n", idx);
	    total += 1;
	}
    }
    printf("Total: %d\n", total);

    // free memory allocated to prime and composite arrays
    free(primes);
    primes = NULL;

    return;
}


int main(int argc, char* argv[])
{
    int num = 0; 
    
    // ensure 1 command line argument only
    if (argc != 2) {
	printf("Wrong number of command line arguments.  Try again.\n");
	exit(-1);
    }

    num = atoi(argv[1]);
    printf("-----------------------\n");
    printf("Find primes less than %d\n", num);
    printf("-----------------------\n");
    printf("Running sieve...\n");
    printf("-----------------------\n");
    sieve(num);
    
    return 0;
}
