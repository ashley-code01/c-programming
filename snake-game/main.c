#include <stdio.h>
#include <conio.h>

#define cols 30
#define rows 15

char board[cols * rows]; // A 1D array to represent the 2D board, where each cell can be accessed using board[y * cols + x]

void fill_board() { // Fills the board with '#' characters for the borders and ' ' for the inside
    int x, y;

    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            if (x == 0 || y == 0 || x == cols - 1 || y == rows - 1) { // If it's the border, set to '#'
                board[y * cols + x] = '#'; // Calculate the index in the 1D array and set to '#'
            } else {
                board[y * cols + x] = ' '; // Set the inside cells to spaces
            }
        }
    }
}

void print_board() { // Prints the board to the console
    int x, y;

    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            putchar(board[y * cols + x]); // Print the character at the current position in the board array
        }
        putchar('\n'); // Print a newline character after each row
    }
}

void read_keyboard() { // This function will read keyboard input and update the game state accordingly
    int ch = getch();
}

int main(int argc, char *argv[]) {
    fill_board();
    print_board();
    read_keyboard(); // Main game loop where keyboard input is read and game state is updated
    return 0;
}