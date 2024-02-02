#include <stdio.h>
#include <string.h>

//function to print the call stack contents
void printCallStackContents();

//function for f2().
void f2();

int f1(char *str, int multiplier) {
    char local_str[strlen(str) + 1];
    strcpy(local_str, str);
    int f1_result = strlen(str) * multiplier;

    //call the memory printing function to print the call stack
    printCallStackContents();

    //call f2()
    f2();

    return f1_result;
}

void f2() {
    //perform some calculations
    int x = 10;
    int y = 20;
    int result = x + y;
	printf("Testing f2(): %d + %d = %d\n", x, y, result);
    //call the memory printing function to print the call stack
    printCallStackContents();
}

int main() {
    //call the memory printing function to print the call stack
    printCallStackContents();

    //call f1().
    int result = f1("Hello", 3);

    //print the result of f1().
    printf("Result of f1: %d\n", result);

    return 0;
}
