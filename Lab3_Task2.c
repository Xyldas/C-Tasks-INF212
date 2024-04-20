// LAB 3 - TASK 2
// Emir Ersoy 230102002064

#include <stdio.h> // includes the standart IO library 

void arrayfiller(int a[4][4]); //  Prototype for arrayfiller function, notifies the code that this function exists
void arrayprinter(int a[4][4]); // Prototype for arrayprinter function, notifies the code that this function exists
int nega(int a[4][4]); // Prototype for maximum function, notifies the code that this function exists

int main() {  // the main function
    int a[4][4], n; //declarations of a and n values as integers. a can take maximum of 4 and 4 values
    
    arrayfiller(a); // Calls the arrayfiller function
    arrayprinter(a); // Calls the arrayprinter function
    n = nega(a); // Calls the nega function and declares n as its result
    
    printf("This matrix has %d negative elements.\n", n);  // prints the num of negative values
    
    return 0; //returns 0
}

void arrayfiller(int a[][4]) {  // function to create the array
    int i, j;
    
    printf("Enter the terms of the array: \n");
    
    for (i = 0; i < 4; i++) { //loop to iterate rows
        for (j = 0; j < 4; j++) { // loop to iterate columns
            scanf("%d", &a[i][j]); //scans the input and places it into the array
        }
    }
}

void arrayprinter(int a[][4]) { // function to display the array
    int i, j;

    for (i = 0; i < 4; i++) { //loop to iterate rows
        for (j = 0; j < 4; j++) { // loop to iterate columns
            printf("%d ", a[i][j]); //reads the array and prints it
        }
        printf("\n");
    }
}

int nega(int a[][4]) { // function to find the amount of negative values within the array
    int i, j, count = 0; //declarations of i j and count values as integers. count is declared as 0

    for (i = 0; i < 4; i++) { //loop to iterate rows
        for (j = 0; j < 4; j++) { // loop to iterate columns
            if (a[i][j] < 0) { // if the value on the ith row and jth column of the array is below zero
                count++; // increment count
            }
        }
    }
    
    return count; // returns count
}

