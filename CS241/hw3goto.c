// Include standard IO as we need to use printf()
#include <stdio.h>

// The main function
int main()
{
    // Declare i now because we cannot declare it at the for loop due to this version of the compiler
    int i = 1;
    // Declares myloop as a goto label. The body of this is our loop.
    myloop:
        // Print the number followed by a colon and the "Odd" or "Even" string. Uses a ternary operator to take the modulo of i and return "Odd" or "Even"
        printf("%d: %s\n", i, (i % 2 ? "Odd" : "Even"));
        // Adds 1 to i to determine which step the loop is currently in
        i++;
    // If i is less than or equal to 10, repeat the loop again
    if (i <= 10) goto myloop;
    // Return 0 for program success
    return 0;
}
