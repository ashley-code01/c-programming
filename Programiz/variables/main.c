#include <stdio.h>

int main() {
    int a = 10; // Declaring an integer variable 'a' and initializing it with the value 10
    float b = 3.14; // Declaring a float variable 'b' and initializing it with the value 3.14
    char c = 'A'; // Declaring a char variable 'c' and initializing it with the value 'A'

    // use format specifiers to print the values of the variables
    // %d is used for integers, %.2f is used for floats (with 2 decimal places), and %c is used for characters
    
    printf("The value of a is: %d\n", a); // Printing the value of variable 'a'
    printf("The value of b is: %.2f\n", b); // Printing the value of variable 'b' with 2 decimal places
    printf("The value of c is: %c\n", c); // Printing the value of variable 'c'

    // change value of variable a
    a = 20; // Assigning a new value 20 to variable 'a'
    printf("The new value of a is: %d\n", a);

    // assign a variable to another variable
    int d = a; // Assigning the value of variable 'a' to variable 'd'
    printf("The value of d is: %d\n", d);

    // declare multiple variables of the same type in a single line
    int x = 5, y = 10, z = 15;
    printf("Values of x, y and z are: %d, %d, %d\n", x, y, z);

    int age = 26; // Declaring an integer variable 'age' and initializing it with the value 26
    printf("The value of age is: %d\n", age); // Printing the value of variable 'age'

    return 0; // Returning 0 to indicate that the program ended successfully
}