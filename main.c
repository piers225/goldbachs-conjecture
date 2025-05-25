#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 

int main() {
    int limit;

    printf("Enter the upper limit (even number >= 4) to verify Goldbach's Conjecture: ");
    if (scanf("%d", &limit) != 1 || limit < 4) {
         printf("Invalid input. Limit must be an integer >= 4.\n");
         return 1;
    }

    bool *is_prime_lookup = (bool *)calloc(limit + 1, sizeof(bool));
    if (is_prime_lookup == NULL) {
        perror("Failed to allocate memory for prime lookup table");
        return 1;
    }

    for (int i = 2; i <= limit; ++i) {
        is_prime_lookup[i] = true;
    }

    int sqrt_limit = (int)sqrt(limit);
    for (int p = 2; p <= sqrt_limit; ++p) {
        if (is_prime_lookup[p]) {
            for (long long i = (long long)p * p; i <= limit; i += p) {
                is_prime_lookup[i] = false;
            }
        }
    }
    printf("Sieve of Eratosthenes complete. Primes up to %d calculated.\n", limit);

    printf("Verifying Goldbach's Conjecture using the pre-calculated primes...\n");
    bool conjectureHolds = true;

    for (int n = 4; n <= limit; n += 2) {
        bool foundPair = false;
        for (int p1 = 2; p1 <= n / 2; ++p1) {
            if (is_prime_lookup[p1] && is_prime_lookup[n - p1]) {
                foundPair = true;
                break;
            }
        }

        if (!foundPair) {
            printf("!!! Counterexample found for %d. Goldbach's Conjecture FAILED at this number. !!!\n", n);
            conjectureHolds = false;
            break; 
        }
    }

    if (conjectureHolds) {
        printf("\nVerification complete. Goldbach's Conjecture holds true for all even numbers checked up to %d.\n", limit);
    } else {
        printf("\nVerification stopped. A counterexample was found.\n");
    }

    free(is_prime_lookup); 
    return 0;
}