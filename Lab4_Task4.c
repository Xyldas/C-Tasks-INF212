// LAB 4 - TASK 4
// Emir Ersoy 230102002064

#include <stdio.h>

void arrayfiller(int n, int a[n]); // Prototype for arrayfiller function, notifies the code that this function exists
int* addressfinder(int n, int a[n], int val); // Prototype for addressfinder function, notifies the code that this function exists

int main() { // the main function
    int n, a[n], val, *address; // n and val values are declared as integers, a[n] is declared as an array with integer members with size of n, address is declared as a pointer

    printf("Enter the size of the array: "); 
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) { //loop to iterate rows
    	a[i] = 0;

    arrayfiller(n, a); // Calls the arrayfiller function

    printf("Enter the number you are searching in the array: ");
    scanf("%d", &val);

    address = addressfinder(n, a, val); //calls the addressfinder function and saves its result as address
    if (address == 0) {
        printf("The value %d is not present within the array.", val);
        printf("\n0");
    } else {
        printf("%d - %p", val, address);
    }
	//if address is 0, this means the number that is searched is not in the array
    return 0; //returns 0
}
}

void arrayfiller(int n, int a[n]) { // // function to create the array
    printf("Enter the terms of the array: \n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); //scans the input and places it into the array
    }
}

int* addressfinder(int n, int a[n], int val){ // function to find the address of a member of an array
    for (int i = 0; i < n; i++) { // loops through the members of the array
        if (a[i] == val) { // if they are equal to value that is searched
            return &a[i]; // returns its address
        }
    }
    return 0; //returns 0
}

