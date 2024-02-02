#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

extern char **environ;

/**
 * prints memory contents from start_addr to end_addr
 *
 * @param start_addr the starting address of memory to print
 * @param end_addr the ending address of memory to print
 */
void printMemoryContents(void *start_addr, void *end_addr) {
    //cast void pointers to unsigned char pointers for byte-wise access
    unsigned char *start = (unsigned char *)start_addr;
    unsigned char *end = (unsigned char *)end_addr;

    printf("Start Address: %p\n", start_addr);
    printf("  End Address: %p\n", end_addr);

    while (start < end) {
        printf("%p: ", start);

        //print 16 bytes per line
        for (int i = 0; i < 16; i++) {
            if (start + i < end) {
                printf("%02x", start[i]);
            }
        }

        printf("  ");

        //print printable characters or dots for non-printable characters
        for (int i = 0; i < 16; i++) {
                if (isprint(start[i])) {
                    printf("%c", start[i]);
                } else {
                    printf(".");
                }
        }

        printf("\n");

        start += 16;
    }
}

/**
 * prints the contents of the call stack
 *
 * uses local variable as the estimated top of the stack
 * uses environ[0] as the estimated bottom of the stack
 * calls memory printing function with the estimated stack boundaries
 */
 void printCallStackContents() {
    //approximate the top of the stack by declaring a local variable
    unsigned char local_variable = 0;
    void *top_of_stack = &local_variable;

    //use environ[0] as the estimated bottom of the stack.
    void *bottom_of_stack = environ[0];

    printMemoryContents(top_of_stack, bottom_of_stack);
}