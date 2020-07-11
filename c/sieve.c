/* 
 * sieve.c
 * Implementation of the Sieve of Eratosthenes in C.
 *
 * Usage: ./sieve <n>
 *   where <n> is an integer.  The sieve finds the number of primes 
 *   between 1 and n.
 *
 * Author: Z. Wallace
 * Last edit: 25 Nov. 2017
 *            28 Aug. 2018 --> Removed printed statements of "first 
 *                             prime greater than <#>".
 *                         --> Removed unused variable j.
 */


#include <stdio.h>
#include <stdlib.h> // exit()
#include <ctype.h>  // isdigit()
#include <math.h>
#include <float.h>


void sieve(double n) {
    int i, idx, j, m;
    double total;
    double *primes;
    
    /* allocate memory for prime and composite number arrays */
    primes = (double *) malloc(n * sizeof(double));
    
    for (i = 0; i < n; i++) {
	primes[i] = 1;    // initialize list as entirely prime
    }

    for (j=1; j <= sqrt(n); j = m) {
        for (i = j+1; i < n; i++) {   // find 1st prime greater than k
	        if (primes[i] == 1) {
		        m = i;
		        break;
            }
        }
        for (i = 2; i <= n/m; i++) {  // mark all multiples of m as composite
	    primes[i*m] = 0;
        }
    }
	    
    /*  output */
    total = 0;   // prime counter
    printf("The primes less than %g are:\n", n);
    for (idx = 2; idx < n; idx++) {   // 0 and 1 marked as special
        if (primes[idx] == 1) {
            printf("%i\n", idx);
            total += 1;
        }
    }
    printf("Total: %g\n", total);

    /* free memory allocated to prime array */
    free(primes);
    primes = NULL;

    return;
}


int main(int argc, char* argv[]) {
    double num = 0; 
    
    /* ensure correct program invocation */
    if (argc != 2) {
        printf("Wrong number of command line arguments.\n");
        printf("Usage is: sieve <n>.  Try again.\n");
        exit(-1);
    }

    num = atof(argv[1]);

    /* Ensure floating point exceptions avoided.  Currently, array 
       indexing goes out of bounds for n < 3.  */
    if (num < 3) {
        printf("%g\n", num);
        printf("No primes less than 2.\n");
        printf("Try a number greater than 2.\n");
        exit(-1);
    }

    printf("-----------------------\n");
    printf("Finding primes less than %g\n", num);
    printf("-----------------------\n");
    printf("Running sieve...\n");
    printf("-----------------------\n");
    sieve(num);
    
    return 0;
}
