#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define UNIVERSE_SIZE 26 // Alphabet {A..Z}

// Function to generate a random string of a specified length
void generate_random_string(char *str, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        int key = rand() % UNIVERSE_SIZE;
        str[i] = charset[key];
    }
    str[length] = '\0';  // Null-terminate the string
}

// Hash function 1: Simple hash using sum of ASCII values modulo m
int hash1(char *str, int m) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }
    return hash % m;
}

// Hash function 2: Polynomial rolling hash
int hash2(char *str, int m) {
    int p = 31;  // A small prime number
    int hash = 0, p_pow = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash + (str[i] - 'A' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash;
}

// Hash function 3: XOR hash
int hash3(char *str, int m) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash ^= str[i];
    }
    return hash % m;
}

// Bloom filter structure
typedef struct {
    int *bit_array;
    int m;  // size of bit array
    int k;  // number of hash functions
} BloomFilter;

// Initialize the bloom filter
BloomFilter *initialize_bloom_filter(int m, int k) {
    BloomFilter *bloom_filter = (BloomFilter *)malloc(sizeof(BloomFilter));
    bloom_filter->bit_array = (int *)calloc(m, sizeof(int));
    bloom_filter->m = m;
    bloom_filter->k = k;
    return bloom_filter;
}

// Insert element into bloom filter using k hash functions
void insert_bloom_filter(BloomFilter *bf, char *str) {
    int h1 = hash1(str, bf->m);
    int h2 = hash2(str, bf->m);
    int h3 = hash3(str, bf->m);

    bf->bit_array[h1] = 1;
    bf->bit_array[h2] = 1;
    if (bf->k > 3) {
        int h4 = (h1 + h2) % bf->m;  // Derivative of h1 and h2
        bf->bit_array[h4] = 1;
    }
    if (bf->k > 5) {
        int h5 = (h2 + h3) % bf->m;  // Derivative of h2 and h3
        bf->bit_array[h5] = 1;
    }
}

// Check if an element is possibly in the bloom filter (false positives possible)
bool check_bloom_filter(BloomFilter *bf, char *str) {
    int h1 = hash1(str, bf->m);
    int h2 = hash2(str, bf->m);
    int h3 = hash3(str, bf->m);

    if (!bf->bit_array[h1] || !bf->bit_array[h2] || !bf->bit_array[h3]) {
        return false;
    }

    if (bf->k > 3) {
        int h4 = (h1 + h2) % bf->m;
        if (!bf->bit_array[h4]) return false;
    }
    if (bf->k > 5) {
        int h5 = (h2 + h3) % bf->m;
        if (!bf->bit_array[h5]) return false;
    }

    return true;
}

// Function to measure the false positive rate
double measure_false_positive_rate(BloomFilter *bf, int n, int test_size) {
    int false_positive_count = 0;
    char test_string[11];

    // Generate and check random strings not in the bloom filter
    for (int i = 0; i < test_size; i++) {
        generate_random_string(test_string, 10);

        if (check_bloom_filter(bf, test_string)) {
            false_positive_count++;
        }
    }

    // False positive rate is the ratio of false positives to the number of tests
    return (double)false_positive_count / test_size;
}

int main() {
    srand(time(0));

    // Configuration
    int n = 10000;           // Number of strings to insert
    int test_size = 10000;    // Number of strings to test
    int string_length = 10;   // Length of each random string

    // Choose k and m values (hash functions and bit array size)
    int k_values[] = {3, 5, 7};
    int m_values[] = {10, 50, 100, 200, 500};

    char random_string[11];   // Buffer for random strings

    // Loop through different values of k and m
    for (int ki = 0; ki < 3; ki++) {
        for (int mi = 0; mi < 5; mi++) {
            int k = k_values[ki];
            int m = m_values[mi];

            // Initialize the bloom filter
            BloomFilter *bf = initialize_bloom_filter(m, k);

            // Insert n random strings into the bloom filter
            for (int i = 0; i < n; i++) {
                generate_random_string(random_string, string_length);
                insert_bloom_filter(bf, random_string);
            }

            // Measure the false positive rate
            double false_positive_rate = measure_false_positive_rate(bf, n, test_size);

            // Output the results
            printf("k = %d, m = %d: False positive rate = %.4f\n", k, m, false_positive_rate);

            // Free the bloom filter memory
            free(bf->bit_array);
            free(bf);
        }
    }

    return 0;
}
