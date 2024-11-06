#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *number;
    int length, i;

    // Allocate memory for the number
    number = (char *)malloc(100 * sizeof(char)); // Allocate memory for 100 characters
    if (number == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read the number as a string
    printf("Enter a number: ");
    scanf("%s", number);
    /*scanf("%d", &number); uses & to pass the address of number.
    scanf("%s", str); does not use & because str already points to the first character of the array.*/

    // Get the length of the string
    length = strlen(number);

    // Reverse the string
    for (i = 0; i < length / 2; i++) {
        char temp = number[i];
        number[i] = number[length - i - 1];
        number[length - i - 1] = temp;
        /*char temp = number[i];
        This line stores the value of number[0] in a temporary variable temp. 
        For example, if number is "hello", then temp will be 'h'.
    number[i] = number[length - i - 1];
        This line assigns the value of the last character in the array to the first position. 
        The expression length - i - 1 calculates the index of the last character. 
        So, for i = 0, it assigns number[length - 1] (which is 'o' for the string "hello") to number[0]. Now, number temporarily looks like "oello".
    number[length - i - 1] = temp;
        This line assigns the value stored in temp (which is 'h') to the last position of the array. 
        So, it assigns temp to number[length - 1] (which was 'o' before). Now, number looks like "oellh".*/
    }

    // Print the reversed number
    printf("Reversed number: %s\n", number);

    // Free the allocated memory
    free(number);

    return 0;
}
/*  Dynamic Memory Allocation: We allocate memory for a string to hold the number using malloc.
    We assume a maximum length of 100 characters for simplicity.
    Reading Input: We read the number as a string using scanf.
    This allows us to handle large numbers that may exceed the limits of standard integer types.
    Reversing the String: We use a simple loop to swap characters from the start and end of the string until we reach the middle.
    Output: We print the reversed string
    Memory Management: Finally, we free the allocated memory to avoid memory leaks. */

/*malloc stands for "memory allocation" and is a standard library function in C used to dynamically allocate memory at runtime. 
It is part of the <stdlib.h> header file. The malloc function allocates a specified number of bytes and 
returns a pointer to the beginning of the allocated memory block.
If the allocation fails (for example, if there is not enough memory available), it returns NULL.*/