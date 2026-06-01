#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variable naming conventions in C

    // 1. Variable names must start with a letter (a-z, A-Z) or an underscore (_)
    int age = 25; // Valid variable name
    int _age = 30; // Valid variable name
    // int 1age = 35; // Invalid variable name (starts with a digit)

    // 2. Variable names can contain letters, digits (0-9), and underscores
    int my_variable = 10; // Valid variable name
    int myVariable = 20; // Valid variable name (camelCase)
    int myVariable123 = 30; // Valid variable name
    // int my-variable = 40; // Invalid variable name (contains a hyphen)

    // 3. Variable names are case-sensitive
    int var = 5; // Valid variable name
    int Var = 10; // Valid variable name (different from 'var')
    
    printf("The value of age is: %d\n", age);
    printf("The value of _age is: %d\n", _age);
    printf("The value of my_variable is: %d\n", my_variable);
    printf("The value of myVariable is: %d\n", myVariable);
    printf("The value of myVariable123 is: %d\n", myVariable123);
    printf("The value of var is: %d\n", var);
    printf("The value of Var is: %d\n", Var);

    return 0;
}