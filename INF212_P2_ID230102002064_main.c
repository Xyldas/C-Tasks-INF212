// Emir Ersoy 230102002064
// Project 2 - Tic Tac Toe

#include <stdio.h>

// definitions for board sizes
#define SIZE_3X3 3
#define SIZE_9X9 9

// Function prototypes
void initialize_Game_Board(char (*game_board)[SIZE_9X9], int size);
int update_Game_Board(char (*game_board)[SIZE_9X9], int size, int row, int col, char symbol);
void show_Game_Board(char (*game_board)[SIZE_9X9], int size);
int check_for_Win(char (*game_board)[SIZE_9X9], int size, char symbol);
int check_for_Tie(char (*game_board)[SIZE_9X9], int size);
void start_Game(int size);
void Menu();

//function that initializes the game board, loops through every member of the game_board array and sets it to " "
void initialize_Game_Board(char (*game_board)[SIZE_9X9], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(game_board + i) + j) = ' ';
        }
    }
}

//Function that updates the board with players' moves, checks if the move is valid 
int update_Game_Board(char (*game_board)[SIZE_9X9], int size, int row, int col, char symbol) {
    if (row < 0) {
        printf("Invalid position. Please try again.\n");
        return 0; // Return 0 for invalid move
    }
    if (row >= size) {
        printf("Invalid position. Please try again.\n");
        return 0; // Return 0 for invalid move
    }
    if (col < 0) {
        printf("Invalid position. Please try again.\n");
        return 0; // Return 0 for invalid move
    }
    if (col >= size) {
        printf("Invalid position. Please try again.\n");
        return 0; // Return 0 for invalid move
    }
    if (*(*(game_board + row) + col) != ' ') {
        printf("Invalid position. Please try again.\n");
        return 0; // Return 0 for invalid move
    }
    
    *(*(game_board + row) + col) = symbol; // updates the game board if the move is valid
    return 1; // Return 1 for successful move
}

//function to print the game board
void show_Game_Board(char (*game_board)[SIZE_9X9], int size) {
    for (int i = 0; i < size; i++) { //loops through every member of the game board array
        for (int j = 0; j < size; j++) {
            printf("%c", *(*(game_board + i) + j)); //prints the character of game board at (i,j)
            if (j < size - 1) {
                printf("|"); //prints vertical lines between the cells
            }
        }
        printf("\n"); //moves to next line
        
        
        if (i < size - 1) {
            for (int k = 0; k < size * 2 - 1; k++) {
                printf("-"); //prints horizontal lines
            }
            printf("\n"); 
        }
    }
}

// function to see if win conditions are satisfied
int check_for_Win(char (*game_board)[SIZE_9X9], int size, char symbol) {
    // Check rows and columns
    int win_row;
    int win_col;

    for (int i = 0; i < size; i++) {
        win_row = 1; // Reset win_row for each row
        win_col = 1; // Reset win_col for each column

        for (int j = 0; j < size; j++) { // Check each row and column for symbol
            if (*(*(game_board + i) + j) != symbol) {
                win_row = 0;
            }
            if (*(*(game_board + j) + i) != symbol) {
                win_col = 0;
            }
        }
        if (win_row) {
            return 1; // Return 1 if there's a win in row
        }
        if (win_col) {
            return 1; // Return 1 if there's a win in column
        }
    }

    // Check diagonals
    int win_diag1 = 1;
    int win_diag2 = 1;

    for (int i = 0; i < size; i++) {
        if (*(*(game_board + i) + i) != symbol) {
            win_diag1 = 0;
        }
        if (*(*(game_board + i) + (size - 1 - i)) != symbol) {
            win_diag2 = 0;
        }
    }
    if (win_diag1) {
        return 1; // Return 1 if there's a win in diagonal 1
    }
    if (win_diag2) {
        return 1; // Return 1 if there's a win in diagonal 2
    }

    return 0; // Return 0 if there's no win
}

// function that checks if the game board has an empty cell, if every cell is filled and no win condition is triggered, says the game is tied.
int check_for_Tie(char (*game_board)[SIZE_9X9], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(*(game_board + i) + j) == ' ') {
                return 0; // Game is not tied
            }
        }
    }
    return 1; // Game is tied
}

void start_Game(int size) {
    char game_board[size][size];
    char symbol = 'O'; // Starting symbol
    int game_over = 0;

    initialize_Game_Board(game_board, size);

    // Main game loop
    while (!game_over) {
        // Print current grid
        printf("Current grid:\n");
        show_Game_Board(game_board, size);
        printf("\n");

        // Get user input for position
        int row, col;
        printf("Player %c's turn. Enter row (Starts from 0): ", symbol);
        scanf("%d", &row);
        printf("Enter the column (Starts from 0): ");
        scanf("%d", &col);

        // Update the board
        int result = update_Game_Board(game_board, size, row, col, symbol);
        if (result == 0) {
            continue; // Invalid move, ask again
        }

        // Check for winner
        if (check_for_Win(game_board, size, symbol)) {
            printf("Player %c wins!\n", symbol);
            game_over = 1;
            continue;
        }
        
        // Check for a tie
        if (check_for_Tie(game_board, size)) {
            printf("It's a tie!\n");
            game_over = 1;
            continue;
        }

        // Switch player
        if (symbol == 'O') {
    		symbol = 'X';
		} else {
    		symbol = 'O';
		}
    }
}
// Menu function
void Menu() {
    int inp;
    
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Made by Emir Ersoy, 230102002064\n");
    printf("Choose your board:\n");
    printf("1. 3x3\n");
    printf("2. 9x9\n");
    printf("Enter your choice: ");
    scanf("%d", &inp);

    switch (inp) {
        case 1:
            printf("Starting 3x3 Tic-Tac-Toe game:\n");
            start_Game(SIZE_3X3);
            break;
        case 2:
            printf("Starting 9x9 Tic-Tac-Toe game:\n");
            start_Game(SIZE_9X9);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return;
    }
}

int main() {
    Menu();
    return 0;
}

