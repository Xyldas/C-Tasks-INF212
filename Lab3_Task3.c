// LAB 3 - TASK 3
// Emir Ersoy 230102002064

#include <stdio.h> // includes the standart IO library 

#define MAX_SIZE 100 // Max size is defined as 100

void arrayfiller(int a[][MAX_SIZE], int n); // Prototype for arrayfiller function, notifies the code that this function exists
void arrayprinter(int a[][MAX_SIZE], int n); // Prototype for arrayprinter function, notifies the code that this function exists
int maximum(int a[][MAX_SIZE], int n); // Prototype for maximum function, notifies the code that this function exists

int main() { // the main function
    int a[MAX_SIZE][MAX_SIZE], n, max; //declarations of a, n and max values as integers

	printf("Enter the size of the square matrix: "); 
    scanf("%d", &n);
    
    arrayfiller(a, n); // Calls the arrayfiller function
    arrayprinter(a, n); // Calls the arrayprinter function
    max = maximum(a, n); // Calls the maximum function and declares max as its result
    printf("The maximum value of this matrix is %d", max); // prints the max value
    
    return 0; // returns 0
}

void arrayfiller(int a[][MAX_SIZE], int n) { // function to create the array
    int i, j;
    
    printf("Enter the terms of the array: \n");
    
    for (i = 0; i < n; i++) { //loop to iterate rows
        for (j = 0; j < n; j++) { // loop to iterate columns
            scanf("%d", &a[i][j]); //scans the input and places it into the array
        }
    }
}

void arrayprinter(int a[][MAX_SIZE], int n) { // function to display the array
    int i, j;

    for (i = 0; i < n; i++) {  //loop to iterate rows
        for (j = 0; j < n; j++) { // loop to iterate columns
            printf("%d ", a[i][j]);//reads the array and prints it
        }
        printf("\n");
    }
}

int maximum(int a[][MAX_SIZE], int n) { // function to find the max value
    int max = a[0][0]; // max is declared as the first element of the array
    int i, j;

    for (i = 0; i < n; i++) { //loop to iterate rows
        for (j = 0; j < n; j++) { // loop to iterate columns
            if (a[i][j] > max) { // If a member of the array is bigger than the max value
                max = a[i][j]; // The max value is declared as the bigger value
                // This repeats until there are no members
            }
        }
    }

    return max; // The biggest value is returned as max
}

