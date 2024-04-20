// LAB 4 - TASK 2
// Emir Ersoy 230102002064

#include <stdio.h> // includes the standart IO library 

void arrayfiller(int n, int a[n]); // Prototype for arrayfiller function, notifies the code that this function exists
void arrayprinter(int n, int a[n], int *pnt); // Prototype for arrayprinter function, notifies the code that this function exists

int main() {
    int n; // n is declared as an integer
    printf("Enter the size of the array: ");
    scanf("%d", &n); 
    
    int a[n]; // array a with size n is declared
    int *pnt = &a[0]; //pointer pnt is declared as the address of the 1st element of array a
    
    for (int i = 0; i < n; i++) { //loop to initialize array with 0's
        a[i] = 0;
    }
    
    arrayfiller(n, a); //calls the arrayfiller function
    arrayprinter(n, a, pnt); //calls the arrayprinter function
    
    return 0; //returns 0
}

void arrayfiller(int n, int a[n]) { // // function to create the array
    printf("Enter the terms of the array: \n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); //scans the input and places it into the array
    }
}

void arrayprinter(int n, int a[n], int *pnt) { //function to print the array
    printf("Array[%d]: \n", n);
    
    for (int i = 0; i < n; i++) {
        printf("%d - %p \n", a[i], (pnt + i)); //prints the value and the address of the member of the array with index i
    }
}

