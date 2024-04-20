// Lab 3 - Task 1
// Emir Ersoy 230102002064

#include <stdio.h> // includes the standart IO library 

int main() { // the main function

int i = 0, toplam; // i and toplam are declared as integers, i is declared as equal to 0
int array1[] = {-4, 6, 21, 13}; // array1 is declared
int array2[] = {9, -7, 33, 0}; // array2 is declared

printf("The element-wise summations are: \n"); //Prints the statement within ""
for(i; i < 4 ; i++) { //for loop
	toplam = array1[i] + array2[i]; // adds ith members of array1 and array2 together, saves it as toplam
	printf("%d + %d = %d \n", array1[i], array2[i], toplam); //prints the statement within ""
}
return 0; // returns 0
}
