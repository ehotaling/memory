#ifndef MEMORY_H
#define MEMORY_H

extern void **environ;

void print_memory(void *start_addr, void *end_addr);
void print_call_stack();

#endif // MEMORY_H
