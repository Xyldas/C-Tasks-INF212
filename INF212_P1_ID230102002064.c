// Project 1
// Emir Ersoy - 230102002064

#include <stdio.h>
#include <math.h>

int takenumber(long long ID, int flag, int initial, int number);
int maxnumber(long long ID);
int minnumber(long long ID);
float average(long long ID);
float area(int a, int b, int c, int x0, int x1, float step);
char dec2hexa(int number, int flag);

int main() {
    long long num = 230102002064;
 //   int numa = 23010, numb = 200, numc = 2064;
    int a, b, c, x0, x1;
	float stp, A;
	char firsthexa, sechexa, lasthexa, penultimatehexa;

    a = takenumber(num,0,1,2);
    b = takenumber(num,1,4,2);
    c = takenumber(num,1,2,2);
    x0 = minnumber(num);
    x1 = maxnumber(num);
    stp = (average(num)/100); // took the percentage of the average
    A = area(a, b, c, x0, x1, stp);// for my student ID, 230102002064, için 2400 gelmeli
//    B = area(a, b, c, x0, x1, 0.1);
//    C = area(a, b, c, x0, x1, 0.01); 
    firsthexa = dec2hexa(a, 1);
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
	
    return 0;
}

int takenumber(long long ID, int flag, int initial, int number) {
    int ID_str[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int kalan = 0, on = 0, bir = 0, numb = 0;
    int *ptr = ID_str;
    
    for (int i = 11; ID != 0 && i >= 0; --i) {
        kalan = ID % 10;
        ID_str[i] = kalan;
        ID /= 10;
    }

    if(flag==0){
        for(int i = initial - 1; i < (initial + number - 1); ++i){
            on = *(ptr+i);
            on *= 10;
            bir = *(ptr+i+1);
            numb += (on + bir);
            break;
        }
        return numb;
    }
    if(flag==1){
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

int maxnumber(long long ID){
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

int minnumber(long long ID){
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

float average(long long ID){
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

float area(int a, int b, int c, int x0, int x1, float step){
	float A = 0;
	for(float x = x0; x < x1; x += step){
	A += ((a*x*x+b*x+c)+(a*(x+step)*(x+step)+b*(x+step)+c))*step/2;	//trapezoidal rule, https://en.wikipedia.org/wiki/Trapezoidal_rule
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
