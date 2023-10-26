#include "memory.h"
#include <stdio.h>
#include <ctype.h>

// Declare environ globally; needed to approximate the bottom of the stack
extern void **environ;

void print_memory(void *start_addr, void *end_addr) {
    // Display start and end addresses; gives context to the memory dump
    printf("Start Address: %p\n", start_addr);
    printf("End Address: %p\n", end_addr);

    // Convert to unsigned char* for byte-by-byte traversal
    unsigned char *start = (unsigned char *) start_addr;
    unsigned char *end = (unsigned char *) end_addr;

    // Loop to traverse the memory range; prints the content between start and end addresses
    while (start < end) {
        // Show the address for the current 16-byte line; aids in tracing memory positions
        printf("%p: ", start);

        // Loop to print 16 bytes as hex values; gives a view of raw memory data
        for (int i = 0; i < 16; i++) {
            if (start + i < end) {
                printf("%02x ", *(start + i));
            } else {
                printf("   ");
            }
        }

        printf(" ");

        // Loop to print 16 bytes as ASCII characters; helps in identifying printable data in memory
        for (int i = 0; i < 16; i++) {
            if (start + i < end) {
                unsigned char c = *(start + i);
                if (isprint(c)) {
                    printf("%c", c);
                } else {
                    printf(".");
                }
            }
        }

        // Move to the next 16-byte block; required to continue the memory traversal
        start += 16;

        printf("\n");
    }
}

// Function to print the call stack
void print_call_stack() {
    // Create a local variable; its address approximates the top of the call stack
    int local_var;
    void *top_of_stack = (void *) &local_var;

    // Use the address of the first environment variable; approximates the bottom of the stack
    void *bottom_of_stack = (void *) environ[0];

    // Call print_memory to display stack content; provides a snapshot of the call stack
    print_memory(top_of_stack, bottom_of_stack);
}
