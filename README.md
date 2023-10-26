
# README for Memory Diagnostic Tool

## Overview
This project is a simple memory diagnostic tool designed to help with the inspection and debugging of memory in C programs. It includes functionality to print a specified memory range in both hexadecimal and ASCII formats and to visualize the call stack of a program.

## Build Instructions
The project can be compiled using the provided `Makefile`. To build the project, run the following command in the project directory:

make

This will compile the source files and generate an executable named `memory-test`.

To clean the build (remove all compiled objects and executables), run:

make clean

## Usage
After building, you can run the executable with:


./memory-test


This will execute a series of functions (`f1` and `f2`) and print the call stack at different stages of execution. The output will help you visualize how the stack changes across function calls and how local variables affect the stack.

## Function Descriptions
### `print_memory(void *start_addr, void *end_addr)`
- **Purpose**: Prints the memory content between `start_addr` and `end_addr` in hexadecimal and ASCII formats.
- **Usage**: This function is utilized internally to display the content of the call stack.

### `print_call_stack()`
- **Purpose**: Visualizes the current state of the call stack.
- **Usage**: Called within functions to show the stack content at that point in execution.
