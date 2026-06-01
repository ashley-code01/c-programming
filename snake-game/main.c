#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define cols 30
#define rows 15

char board[cols * rows]; // A 1D array to represent the 2D board, where each cell can be accessed using board[y * cols + x]
int isGameOver = 0; // A flag to indicate whether the game is over or not. The game will end when the snake collides with itself or the wall.

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

void clear_screen() { // Clears the console screen
    system("cls"); // Clear the console screen (Windows specific command)

    // on linux
    // system("clear"); // Clear the console screen (Linux specific command)
    // or 
    // printf("\033[H\033[J"); // Clear the console screen using ANSI escape codes (cross-platform)
}

void print_board() { // Prints the board to the console
    int x, y;

    // clear screen
    clear_screen();

    for (y = 0; y < rows; y++) {
        for (x = 0; x < cols; x++) {
            putchar(board[y * cols + x]); // Print the character at the current position in the board array
        }
        putchar('\n'); // Print a newline character after each row
    }
}

int snake_x = cols / 2; // Initial x position of the snake (center of the board)
int snake_y = rows / 2; // Initial y position of the snake (center of the board)

void draw_snake() { // Placeholder function to draw the snake on the board
    board[snake_y * cols + snake_x] = 'O'; // Set the current position of the snake to 'O' on the board
}

void move_snake_up(int deltaX, int deltaY) { // Placeholder function to move the snake up
    snake_x += deltaX; // Update the snake's x position based on the input direction
    snake_y += deltaY; // Update the snake's y position based on the input direction
}

void move_snake_down(int deltaX, int deltaY) { // Placeholder function to move the snake down
    snake_x += deltaX; // Update the snake's x position based on the input direction
    snake_y += deltaY; // Update the snake's y position based on the input direction
}

void move_snake_left(int deltaX, int deltaY) { // Placeholder function to move the snake left
    snake_x += deltaX; // Update the snake's x position based on the input direction
    snake_y += deltaY; // Update the snake's y position based on the input direction
}

void move_snake_right(int deltaX, int deltaY) { // Placeholder function to move the snake right
    snake_x += deltaX; // Update the snake's x position based on the input direction
    snake_y += deltaY; // Update the snake's y position based on the input direction
}

void read_keyboard() { // This function will read keyboard input and update the game state accordingly
    
    if (_kbhit()) { // Check if a key has been pressed. _kbhit() is a non-blocking function that returns true if a key has been pressed, allowing the game loop to continue running without waiting for user input.
        int ch = getch();

        switch (ch) {
            case 'w': move_snake_up(0, -1); break;
            case 's': move_snake_down(0, 1); break;
            case 'a': move_snake_left(-1, 0); break;
            case 'd': move_snake_right(1, 0); break;
        }
    }

}

int main(int argc, char *argv[]) {

    while (!isGameOver) { // Main game loop.
        fill_board();
        draw_snake(); // Draw the snake on the board
        print_board();
        read_keyboard(); // Main game loop where keyboard input is read and game state is updated
    }

    return 0;
}