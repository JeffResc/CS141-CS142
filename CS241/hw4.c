// Include standard IO as we need to use printf()
#include <stdio.h>

// My string length function
int my_strlen(char *str)
{
    // Creates a pointer, ptr, that points to str
    char *ptr = str;
    // As long as the pointer is not at the end of str (denoted by '\0'), keep moving the pointer forward
    while (*ptr != '\0')
        // Add 1 to ptr to determine another character in the string
        ptr++;
    // Now that ptr is at the end of the string and str is at the beginning, we can take the difference between the two to get the length of str
    return ptr - str;
}

// The main function
int main()
{
    // An array of chars to denote our string
    char a[] = "Count the length of this string";
    // A test driver for my_strlen that takes a and prints out the number of characters in a
    printf("% d characters in % s\n", my_strlen(a), a);
}
