#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define COLS 30
#define ROWS 15
#define MAX_LENGTH (COLS * ROWS)

// ======================= Board =======================
char board[COLS * ROWS];
int isGameOver = 0;
int score = 0;

// ======================= Snake =======================
typedef struct { // Represents a single segment of the snake.
    int x, y;
} Point;

Point snake[MAX_LENGTH]; // Array of segments. snake[0] is always the head.
int snake_length = 1; // Starts with just the head. Grows when eating food.

// ======================= Direction (continuous movement) =======================
int dir_x = 1; // Starts moving right
int dir_y = 0;

// ======================= Food =======================
int food_x, food_y;

// ======================= Function Prototypes =======================

void place_food() { // Randomly place food on the board, ensuring it doesn't spawn on the snake.

    int valid = 0; // Flag to check if the generated food position is valid (not on the snake)
    int i;

    while (!valid) { // Keep generating until we find a valid position

        food_x = (rand() % (COLS - 2)) + 1; // Keep food inside the borders
        food_y = (rand() % (ROWS - 2)) + 1;
        valid = 1;

        // Make sure food doesn't spawn on top of the snake
        for (i = 0; i < snake_length; i++) {
            if (snake[i].x == food_x && snake[i].y == food_y) { // If food spawns on the snake, we need to generate a new position
                valid = 0;
                break;
            }
        }
    }
}

void fill_board() { // Fill the board array with spaces and borders. Borders are represented by '#', empty spaces by ' '.
    int x, y;

    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            if (x == 0 || y == 0 || x == COLS - 1 || y == ROWS - 1) { // Border cells. The snake cannot move into these cells without colliding with the wall.
                board[y * COLS + x] = '#';
            } else {
                board[y * COLS + x] = ' ';
            }
        }
    }
}

void draw_food() { // Place the food character on the board at the current food coordinates.
    board[food_y * COLS + food_x] = '*'; // Food is represented by '*'
}

void draw_snake() { // Place the snake segments on the board.
    int i;

    for (i = 0; i < snake_length; i++) {
        // Head is '@', body segments are 'o'
        board[snake[i].y * COLS + snake[i].x] = (i == 0) ? '@' : 'o';
    }
}

// Clears the console screen. Uses system("cls") which is specific to Windows. 
// On other platforms, you might need to use system("clear") or a different method.
void clear_screen() {
    system("cls");
}

void print_board() {
    int x, y;

    clear_screen();

    for (y = 0; y < ROWS; y++) { // Print each row of the board. Each cell is printed based on the character in the board array.
        for (x = 0; x < COLS; x++) {
            putchar(board[y * COLS + x]);
        }
        putchar('\n');
    }

    printf("\n  Score: %d\n", score); // Print score below the board
}

void move_snake() {
    int i;

    // Shift every segment forward by one - from the tail up to the neck
    for (i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // Move the head in the current direction
    snake[0].x += dir_x;
    snake[0].y += dir_y;
}

void check_collisions() {
    int i;
    int head_x = snake[0].x;
    int head_y = snake[0].y;

    // Wall collision
    if (head_x <= 0 || head_x >= COLS - 1 || head_y <= 0 || head_y >= ROWS - 1) {
        isGameOver = 1;
        return;
    }

    // Self collision - check head against every body segment
    for (i = 1; i < snake_length; i++) {
        if (snake[i].x == head_x && snake[i].y == head_y) {
            isGameOver = 1;
            return;
        }
    }

    // Food collision - grow the snake and place new food
    if (head_x == food_x && head_y == food_y) {
        score++;
        snake_length++;
        place_food();
    }
}

void read_keyboard() {
    if (_kbhit()) { // Non-blocking - only reads if a key is waiting
        int ch = getch();

        switch (ch) {
            // Prevent the snake from reversing directly into itself
            case 'w': if (dir_y != 1)  { dir_x = 0;  dir_y = -1; } break;
            case 's': if (dir_y != -1) { dir_x = 0;  dir_y = 1;  } break;
            case 'a': if (dir_x != 1)  { dir_x = -1; dir_y = 0;  } break;
            case 'd': if (dir_x != -1) { dir_x = 1;  dir_y = 0;  } break;
        }
    }
}

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL)); // Seed random number generator

    // Initialize snake head at the center of the board
    snake[0].x = COLS / 2;
    snake[0].y = ROWS / 2;

    place_food(); // Place the first food item

    int sleep = 150 - (score * 5); // Speed up the game as the score increases
    if (sleep < 50) { 
        sleep = 50; 
    } // Cap the speed increase to prevent it from becoming unplayable
    
    while (!isGameOver) {
        fill_board();
        draw_food();
        draw_snake();
        print_board();
        read_keyboard();
        move_snake();
        check_collisions();
        Sleep(sleep); // ~6 frames per second - lower = faster snake
    }

    // Game over screen
    clear_screen();
    printf("+--------------------------+\n");
    printf("|        GAME  OVER        |\n");
    printf("+--------------------------+\n");
    printf("|     Final Score: %-3d     |\n", score);
    printf("+--------------------------+\n");

    return 0;
}