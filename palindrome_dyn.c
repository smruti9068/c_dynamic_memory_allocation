#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a pointer for dynamic memory allocation
    char *number;
    int length, i, isPalindrome = 1;

    // Input the number as a string
    printf("Enter a number: ");
    // Allocate memory for the number (assuming maximum length of 20 digits)
    number = (char *)malloc(20 * sizeof(char));
    if (number == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Read the number as a string
    scanf("%s", number);

    // Calculate the length of the number
    for (length = 0; number[length] != '\0'; length++);
    /*number[length] != '\0': This condition checks whether the current character in the string number at index length
     is not the null terminator ('\0'). In C,strings are represented as arrays of characters terminated by a null character.
     The null character indicates the end of the string.*/

    // Check for palindrome
    for (i = 0; i < length / 2; i++) {
        if (number[i] != number[length - i - 1]) {
            isPalindrome = 0; // Set flag to false if mismatch found
            break; // No need to check further
        }
    }

    // Output the result
    if (isPalindrome) {
        printf("%s is a palindrome number.\n", number);
    } else {
        printf("%s is not a palindrome number.\n", number);
    }

    // Free the allocated memory
    free(number);

    return 0;
}