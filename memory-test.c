/* memory-test.c */
#include <stdio.h>
#include <string.h>
#include "memory.h"

void print_call();
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
