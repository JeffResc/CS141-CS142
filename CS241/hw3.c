// Include standard IO as we need to use printf()
#include <stdio.h>

// The main function
int main()
{
    // Declare i now because we cannot declare it at the for loop due to this version of the compiler
    int i;
    // Start our for loop that loops 1 - 10
    for (i = 1; i <= 10; i++)
    {
        // Print the number followed by a colon and the "Odd" or "Even" string. Uses a ternary operator to take the modulo of i and return "Odd" or "Even"
        printf("%d: %s\n", i, (i % 2 ? "Odd" : "Even"));
    }
    // Return 0 for program success
    return 0;
}
