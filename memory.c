/* memory.c */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern void **environ;

void print_mem(void *start_addr, void *end_addr) {
        unsigned char *start = (unsigned char *)start_addr;
        unsigned char *end = (unsigned char *)end_addr;

        printf("Start Address: %p\n", start);
        printf("End Address: %p\n", end);

        while (start < end) {
                printf("%p: ", (void *)start);

                for (int i = 0; i < 16; i++){
                        if (start + i < end) {
                                unsigned char byte = start[i];

                                printf("%02X ", byte);
                        } else {
                                printf("   "); //Adds additional spaces for any incomplete lines that are found
                        }
                }

                printf(" ");

                for (int i = 0; i < 16; i++) {
 if (start + 1 < end) {
                                if (isprint(start[i])) {
                                        printf("%c", start[i]); //Prints out whatever can actually be printed by the code
                                }
                                else {
                                        printf(".");
                                } //Everything that cannot be printed gets replaced with a dot
                        }
                }
                printf("\n");
                start += 16;
        }
} //Complete function to print all of the memory contents from the starting address to end address

void print_call(){

        char bot = 0;
        char *bot_addr = &bot;

        char *top_addr = (char *)environ[0]; //Gets the top address from environ

        print_mem(bot_addr, top_addr); //Function to print the contents of the call stack
}
