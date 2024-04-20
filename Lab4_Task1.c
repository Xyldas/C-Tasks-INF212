// LAB 4 - TASK 1
// Emir Ersoy 230102002064

#include <stdio.h> // includes the standart IO library 

void arrayfiller(int n , int a[n][n]); // Prototype for arrayfiller function, notifies the code that this function exists
void arrayprinter(int n , int a[n][n]); // Prototype for arrayprinter function, notifies the code that this function exists
int maximum(int n , int a[n][n]); // Prototype for maximum function, notifies the code that this function exists
int minimum(int n , int a[n][n]); // Prototype for minimum function, notifies the code that this function exists
void changeelement(int *a, int n, int row, int col, int val); // Prototype for changeelement function, notifies the code that this function exists

int main() { // the main function
    int n, a[n][n], max, min, row, col, val; //declarations of a, n, max, min, row, col and val values as integers

	printf("Enter the size of the square matrix: "); 
    scanf("%d", &n);
    
    arrayfiller(n, a); // Calls the arrayfiller function
    arrayprinter(n, a); // Calls the arrayprinter function
    max = maximum(n, a); // Calls the maximum function and declares max as its result
    min = minimum(n, a);// Calls the minimum function and declares max as its result
    printf("The maximum value of this matrix is %d, minimum value is %d.\n", max, min); // prints the max and min value
	printf("Now change an element. \n");
	printf("Enter the row index: \n"); // takes the row index for changeelement 
	scanf("%d", &row);
	
	printf("Enter the column index: \n"); // takes the column index for changeelement 
	scanf("%d", &col);
	
    printf("Enter new value: "); // takes the new value for changeelement 
    scanf("%d", &val);
    changeelement(*a, n, row, col, val); //calls the changeelement function
    
    printf("Updated array:\n"); //prints the updated array by calling arrayprinter function
    arrayprinter(n, a);
    
    return 0; // returns 0
}

void arrayfiller(int n , int a[n][n]) { // function to create the array
    
    printf("Enter the terms of the array: \n");
    
    for (int i = 0; i < n; i++) { //loop to iterate rows
        for (int j = 0; j < n; j++) { // loop to iterate columns
            scanf("%d", &a[i][j]); //scans the input and places it into the array
        }
    }
}

void arrayprinter(int n , int a[n][n]) { // function to display the array

    for (int i = 0; i < n; i++) {  //loop to iterate rows
        for (int j = 0; j < n; j++) { // loop to iterate columns
            printf("%d ", a[i][j]);//reads the array and prints it
        }
        printf("\n");
    }
}

int maximum(int n , int a[n][n]) { // function to find the max value
    int max = a[0][0]; // max is declared as the first element of the array

    for (int i = 0; i < n; i++) { //loop to iterate rows
        for (int j = 0; j < n; j++) { // loop to iterate columns
            if (a[i][j] > max) { // If a member of the array is bigger than the max value
                max = a[i][j]; // The max value is declared as the bigger value
                // This repeats until there are no members
            }
        }
    }

    return max; // The biggest value is returned as max
}

int minimum(int n , int a[n][n]) { // function to find the min value
    int min = a[0][0]; // min is declared as the first element of the array

    for (int i = 0; i < n; i++) { //loop to iterate rows
        for (int j = 0; j < n; j++) { // loop to iterate columns
            if (a[i][j] < min) { // If a member of the array is lesser than the min value
                min = a[i][j]; // The min value is declared as the smaller value
                // This repeats until there are no members
            }
        }
    }

    return min; // The smallest value is returned as min
    }
    
void changeelement(int *a, int n, int row, int col, int val) { //function to change an element of the array
    if (row >= 0 && row < n && col >= 0 && col < n) { 
        *(a + (row*n) + col) = val; //this line assignes the value of val to the address referenced by *(a + row * n + col)
        // a refers to the beginning of the 2D array, row * n is the multiplication of the amount of rows with the amount of values in a row
		// this takes us to the row we desire, by adding col we reach the index we desire.
		// TLDR: basically accesses a[row][col], but does it via pointers
    } else {
        printf("Invalid row or column index.\n"); // If it is out of bounds, print this.
    }
}


