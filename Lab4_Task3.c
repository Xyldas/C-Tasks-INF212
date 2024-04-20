// LAB 4 - TASK 3
// Emir Ersoy 230102002064

#include <stdio.h> // includes the standart IO library 

void arrayfiller(int n, int a[n]); // Prototype for arrayfiller function, notifies the code that this function exists
void arrayprinter(int n, int a[n]); // Prototype for arrayprinter function, notifies the code that this function exists

int main() {	
	int n; // n is declared as an integer
    printf("Enter the size of the array: ");
    scanf("%d", &n); 
    
    int a[n]; // array a with size n is declared

    for (int i = 0; i < n; i++) { //loop to initialize array with 0's
        a[i] = 0;
    }
    
    arrayfiller(n, a); //calls the arrayfiller function
    arrayprinter(n, a); //calls the arrayprinter function
    
    return 0; //returns 0
}

void arrayfiller(int n, int a[]) { // // function to create the array
    printf("Enter the terms of the array: \n");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); //scans the input and places it into the array
    }
}

void arrayprinter(int n, int a[]) {
    int *ptr;
    int *last_ptr = &a[n - 1]; // Pointer to the last element in the array

    printf("Array[%d]: \n", n);
    
    for (ptr = &a[0]; ptr <= last_ptr; ptr++) { // Loop limited by comparing pointers
        printf("%d - %p \n", *ptr, ptr);
    }
}


