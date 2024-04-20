#include <Adafruit_LiquidCrystal.h> //Libraries
#include <stdio.h>
#include <math.h>

int takenumber(long long ID, int flag, int initial, int number); // Func. prototypes
int maxnumber(long long ID);
int minnumber(long long ID);
float average(long long ID);
float area(int a, int b, int c, int x0, int x1, float step);
char dec2hexa(int number, int flag);

long long num = 230102002064; //Student ID
int a = 0, b = 0, c = 0, x0 = 0, x1 = 0; // Coefficients and bounds of integral
float stp, A; // step size and area
char firsthexa, sechexa, lasthexa, penultimatehexa; // hexadecimal characters

Adafruit_LiquidCrystal lcd(7, 6, 5, 4, 3, 2); //LCD is defined with 7,6,5,4,3,2 pins

void setup() {
    lcd.begin(16, 2); //LCD with sizes of 16 and 2 begins
    lcd.setCursor(0, 0); //cursor is set to 0 and 0
    lcd.print("Greetings!"); //printed where cursor is
    delay(2000);
  	lcd.clear();
  
    lcd.setCursor(0, 0);
    lcd.print("EMIR ERSOY");
    lcd.setCursor(0, 1);
    lcd.print("ID:230102002064");
  	delay(2000);
    lcd.clear();
 
}

void loop() {

    a = takenumber(num,0,1,2); // Took the number a
 	  b = takenumber(num,1,4,2);// Took the number a
    c = takenumber(num,1,2,2); // Took the number a
    x0 = minnumber(num); // x0 is declared as the minimum number on ID
    x1 = maxnumber(num); // x1 is declared as the max. number on ID
    stp = (average(num)/100); // took the percentage of the average
    A = area(a, b, c, x0, x1, stp);// for my student ID, 230102002064, result 2400.
    firsthexa = dec2hexa(a, 1); //takes the hexadecimals of the numbers
    sechexa = dec2hexa(a, 2);
    lasthexa = dec2hexa(c, 2);
    penultimatehexa = dec2hexa(c, 1);
    
    printf("ID = %lld\n", num); //Prints the ID
    printf("a = %d\n", a); //the coefficient of x^2
	  printf("b = %d\n", b); //the coefficient of x, also the last 3rd and 4th number
	  printf("c = %d\n", c); //last two numbers
	  printf("f(x) = %dx^2 + %dx + %d\n", a,b,c); // the function
	  printf("x0 = %d\n", x0); //the start of the integral
	  printf("x1 = %d\n", x1); //the end of the integral
	  printf("step = %lf\n", stp);
	  printf("area (step size of %lf) = %.2lf\n", stp, A);
	  printf("Hexadecimal for %d: %c", a, firsthexa);
	  printf("%c\n", sechexa);
	  printf("Hexadecimal for %d: %c", c, penultimatehexa);
	  printf("%c", lasthexa);
  
    lcd.setCursor(0, 0);
    lcd.print(a);
  	lcd.setCursor(5, 0);
    lcd.print(b);
    lcd.setCursor(10, 0);
    lcd.print(c);
    delay(3000);
  	lcd.clear();

  	lcd.setCursor(0, 0);
    lcd.print("1st two digits");
  	delay(3000);
  
  	lcd.clear();
  
  	lcd.setCursor(0, 0);
    lcd.print("Decimal:");
  	lcd.setCursor(9, 0);
    lcd.print(a);
    lcd.setCursor(0, 1);
    lcd.print("Hexa:");
  	lcd.setCursor(6, 1);
    lcd.print(firsthexa);
  	lcd.setCursor(7, 1);
    lcd.print(sechexa);
  	delay(3000);
  
  	lcd.clear();
  
  	lcd.setCursor(0, 0);
    lcd.print("last 2 digits");
  	delay(3000);
  
    lcd.clear();
  
  	lcd.setCursor(0, 0);
    lcd.print("Decimal:");
  	lcd.setCursor(9, 0);
    lcd.print(c);
    lcd.setCursor(0, 1);
    lcd.print("Hexa:");
  	lcd.setCursor(6, 1);
    lcd.print(penultimatehexa);
  	lcd.setCursor(7, 1);
    lcd.print(lasthexa);
  	delay(3000);
  
  	lcd.clear();
  
  	lcd.setCursor(0, 0);
    lcd.print("Area:");
    lcd.setCursor(5, 0);
  	lcd.print(A);
  	delay(3000);
  
  	lcd.clear();
}

int takenumber(long long ID, int flag, int initial, int number) {
    int ID_str[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; // Array of size 12 initialized with 0
    int kalan = 0, on = 0, bir = 0, numb = 0;
    int *ptr = ID_str; //pointer is declared
    
    for (int i = 11; ID != 0 && i >= 0; --i) { //takes the digits of the number and stores it in the array
        kalan = ID % 10;
        ID_str[i] = kalan;
        ID /= 10;
    }

    if(flag==0){
        for(int i = initial - 1; i < (initial + number - 1); ++i){ //takes the wanted digits from left to right
            on = *(ptr+i);
            on *= 10;
            bir = *(ptr+i+1);
            numb += (on + bir);
            break;
        }
        return numb;
    }
    if(flag==1){ //takes the wanted digits from right to left
        for(int i = (12 - initial); i < 12; ++i){
            on = *(ptr+i);
            on *= 10;
            bir = *(ptr+i+1);
            numb += (on+bir);
            break;
        }
        return numb;
    }
}

int maxnumber(long long ID){ // finds the maximum digit in the number
	int max_num = 0;
	int c_num;
	while (ID > 0) {
		c_num = ID%10;
		if(c_num > max_num){
			max_num = c_num;
		}
		ID /= 10;
	}
	return max_num;
}

int minnumber(long long ID){ // finds the minimum digit in the number
	int min_num = 9;
	int c_num;
	while (ID > 0) {
		c_num = ID%10;
		if(c_num < min_num){
			min_num = c_num;
		}
		ID /= 10;
	}
	return min_num;
}

float average(long long ID){ // finds the average digit in the number
	float sum = 0, avg = 0;
	int c_num;
		while (ID > 0) {
		c_num = ID%10;
		sum += c_num;
		ID /= 10;
	}
	avg = sum / 12;
	return avg;
}

float area(int co1, int co2, int co3, int x0, int x1, float step){ //calculates the area of a parabolic function 
	float A = 0;
	for(float x = x0; x < x1; x += step){
	A += ((co1*x*x+co2*x+co3)+(co1*(x+step)*(x+step)+co2*(x+step)+co3))*step/2;	//trapezoidal rule, https://en.wikipedia.org/wiki/Trapezoidal_rule
	}
	return A;
	
}

char dec2hexa(int number, int flag){ // used the algorithm from this link: https://codescracker.com/c/program/c-program-convert-decimal-to-hexadecimal.htm 
	int hex1 = 0, dec, i = 0;
	char hex[100];
	dec = number;
	while(dec != 0){
		hex1 = dec%16;
		if(hex1 < 10){
			hex1 = hex1 + 48;
		}
		else {
			hex1 = hex1 + 55;
		}
		hex[i] = hex1;
		i++;
		dec = dec/16;
	}

	return hex[i-flag];
}
