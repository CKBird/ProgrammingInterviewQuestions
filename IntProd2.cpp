//Take #2 of IntegerProducts.cpp
//Keeping in mind space and time complexity
//Take #1 was very space/time intensive, brute force even

//Wall Clock time started: 11:40am

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int initArray[5];
	int outArray[5];
	
	for(int i = 0; i < 5; i++) {
		initArray[i] = rand() % 10 + 1; //1-10 in each spot
	} //Array is filled with values
	
	//This will fill the new array with a list of all products BEFORE the current index
	int prod = 1;
	//Look over array once
	for(int i = 0; i < 5; i++) {
		outArray[i] = prod;
		prod *= initArray[i];
	}
	
	//This will edit outArray to inculde product of all values AFTER current index
	prod = 1;
	for(int i = 4; i >= 0; i--) {
		outArray[i] *= prod;
		prod *= initArray[i];
	}
	
	//Print init array values
	//Print out array values

	cout << "Init Array: " << endl;
	for(int i = 0; i < 5; i++) {
		cout << initArray[i] << " ";
	}
	cout << endl;
	
	cout << "Out Array: " << endl;
	for(int i = 0; i < 5; i++) {
		cout << outArray[i] << " ";
	}
	cout << endl;
	//Wall time at end of coding: 11:46am
	//Wall time at end of debugging: 11:49am
	return 0;
}