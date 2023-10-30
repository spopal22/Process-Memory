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
		start += 16
/* memory-test.c */
#include <stdio.h>
#include <string.h>

void f2();

int f1 (char *str, int multiplier) {
	char local_str[strlen(str) + 1];
	strcpy(local_str, str);
	int f1_result = strlen(str) * multiplier;
	print_call();
	f2();
	return f1_result;
}

void f2(){
	int a = 150;
	int b = 150;
	int result = a + b;
	if (result == 300) {
		printf("Function 2 is a success! The result was: %d\n", result);
	}
	print_call();
}

int main(){
	print_call();

	int result = f1("Test", 2); //Executes f1
	printf("The result of f1 is: %d\n", result);

	return 0;
}

