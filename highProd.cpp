//Practice Programming Interview Question #3
//Given a list of ints, find the highest product you can get from three of the integers
//List will always have at least 3 integers

//Wall clock time started: 11:51am

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

//Brute force: create a product for each set of 3 values in array and compare
//Can I do it in place?
//Make a new list of products and find highest?
//What about 2 negatives? -10 * -10 = 100
//If I find largest product of 2 numbers and lowest product of 2 numbers, can prod that by all other values
//and determine highest prod of 3

int main() {
	int initArray[10];
	srand (time(NULL));
	for(int i = 0; i < 10; i++) {
		int value = rand() % 10 + 1; //1-10
		if(rand() % 2 == 1)
			value *= -1;
		initArray[i] = value;
	}

	int high,		//Largest value 
		low, 		//Smallest value
		hprod2, 	//Largest product of 2 numbers
		lprod2, 	//Smallest product of 2 numbers 
		prod3;		//Total product
	if(initArray[0] >= initArray[1]) {
		high = initArray[0];
		low = initArray[1];
	}
	else {
		high = initArray[1];
		low = initArray[0];
	}
	lprod2 = hprod2 = high*low;
	prod3 = initArray[0] * initArray[1] * initArray[2];
	
	for(int i = 2; i < 10; i++) {
		int maxProd3 = 0;
		if(prod3 > maxProd3)
			maxProd3 = prod3;
		if((initArray[i] * hprod2) > maxProd3)
			maxProd3 = initArray[i] * hprod2;
		if((initArray[i] * lprod2) > maxProd3)
			maxProd3 = initArray[i] * lprod2;
		prod3 = maxProd3;
		
		int maxHProd2 = 0;
		if(hprod2 > maxHProd2)
			maxHProd2 = hprod2;
		if((initArray[i] * high) > maxHProd2)
			maxHProd2 = initArray[i] * high;
		if((initArray[i] * low) > maxHProd2)
			maxHProd2 = initArray[i] * low;
		hprod2 = maxHProd2;
		
		int minLProd2 = 111111111;
		if(lprod2 < minLProd2)
			minLProd2 = lprod2;
		if((initArray[i] * high) < minLProd2)
			minLProd2 = initArray[i] * high;
		if((initArray[i] * low) < minLProd2)
			minLProd2 = initArray[i] * low;
		lprod2 = minLProd2;
		
		if(initArray[i] > high)
			high = initArray[i];
		
		if(initArray[i] < low)
			low = initArray[i];
	} //Output is 3 highest values, just need to multiply
	
	cout << "Init Arary: " << endl;
	for(int i = 0; i < 10; i++) {
		cout << initArray[i] << " ";
	}
	
	cout << endl << "Largest Product of 3: " << prod3 << endl;
	//Wall clock time done coding: 12:25pm
	//Wall clock done debugging: 
	return 0;
}