#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STRING_LENGTH 10  // Define the length of each random string
#define NUM_STRINGS 10000 // Define how many strings we want to generate

// Function to generate a random alphanumeric string of given length
void generate_random_string(char *str, int length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);  // Randomly select a character from charset
        str[i] = charset[key];
    }
    str[length] = '\0';  // Null-terminate the string
}

// Main function to generate NUM_STRINGS random strings and save them to a file
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Open file to save the generated strings
    FILE *file = fopen("random_strings.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }

    char random_string[STRING_LENGTH + 1];  // Buffer to store each generated string

    // Generate NUM_STRINGS random strings and write each to the file
    for (int i = 0; i < NUM_STRINGS; i++) {
        generate_random_string(random_string, STRING_LENGTH);
        fprintf(file, "%s\n", random_string);  // Write string to file
    }

    // Close the file
    fclose(file);

    printf("%d random strings saved to random_strings.txt\n", NUM_STRINGS);

    return 0;
}
