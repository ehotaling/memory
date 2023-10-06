#include "memory.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// f2 function is defined to serve as a deeper level in the call stack
void f2() {
    int a = 10, b = 20;  // Local variables to add some complexity to the stack
    int sum = a + b;  // Summation to engage the CPU and modify the stack
    printf("Sum in f2: %d\n", sum);  // Output to observe function behavior

    // To visualize how the stack changes when entering and exiting f2
    print_call_stack();
}

// f1 function performs some string operations and calls f2
int f1(char *str, int multiplier) {
    char local_str[strlen(str) + 1];  // To see how local variables affect the stack
    strcpy(local_str, str);  // Copy operation to add more instructions to the stack

    int f1_result = strlen(str) * multiplier;  // To engage CPU in some calculations

    // To visualize the state of the stack within this function before calling f2
    print_call_stack();

    // To add another layer to the call stack and observe changes
    f2();

    return f1_result;  // To provide an output from the function, affecting the caller's stack
}

// main function serves as the entry point and initiates the program flow
int main(int argc, char *argv[]) {
    // To capture the initial state of the call stack at the beginning of program execution
    print_call_stack();

    // To initiate a sequence of function calls, adding layers to the call stack
    int result = f1("test", 2);

    // Output to confirm the result of f1, providing a terminal point for program flow
    printf("Result from f1: %d\n", result);

    return 0;  // To signify successful program termination
}
