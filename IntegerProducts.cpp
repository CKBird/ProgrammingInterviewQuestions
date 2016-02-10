//Practice Programming Problem #2
//You have a list of integers, and for each index you want to find the product of every integer 
//except the integer at that index.
//Write a function get_products_of_all_ints_except_at_index() that takes a list of integers and 
//returns a list of the products.

//Wall clock time started: 11:20am
//Take array of values, make an array of same size, and at each location, store product of other numbers


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
	
	int runningProd = 1;
	for(int j = 0; j < 5; j++) {		
		for(int i = 0; i < 5; i++) {
			if(i != j) {
				runningProd *= initArray[i];
			}
		}
		outArray[j] = runningProd;
		runningProd = 1;
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
	//Wall time at end of coding: 11:26am
	//Wall time at end of debugging: 11:33am
	return 0;
}