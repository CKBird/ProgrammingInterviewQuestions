//---Programming Interview Question #1---
//Suppose we could access yesterday's stock prices as a list, where:
//The indices are the time in minutes past trade opening time, which was 9:30am local time.
//The values are the price in dollars of Apple stock at that time.
//So if the stock cost $500 at 10:30am, stock_prices_yesterday[60] = 500.

//Write an efficient function that takes stock_prices_yesterday and returns the best profit 
//I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.

//Wall Clock time Started: 11:00am February 10th, 2016

//All i values are the MINUTES past the opening time which was 930am
//The value stored at that position is the value of the stock at that time
//Must find best profit could have made from 1 buy and 1 sell
//AKA: find the max difference in the array values, since time isn't an issue
//Find max and min of array, ensure that min comes before max in terms of i 
//Output result

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
	//Input array of values from other file, will hard code here for testing purposes
	//Will assume i is 100 minutes
	int stock_prices_yesterday[100];
	
	//Simple for loop to fill array with random values from 1-100
	for(int i = 0; i < 100; i++) {
		stock_prices_yesterday[i] = rand() % 100 + 1;
	}
	
	//Can begin finding values within array, since I don't need to sort, I can 
	//simply iterate through the array finding max and min
	//Will iterate through ALL and find both, THEN check if iMin < iMax
	//If it isn't, will then check through 0 -> iMax to find new iMin
	
	
	int min = 101, max = 0;
	int minpos = 0, maxpos = 0;
	for(int i = 0; i < 100; i++) {
		if(stock_prices_yesterday[i] > max) {
			max = stock_prices_yesterday[i];
			maxpos = i;
		}
		if(stock_prices_yesterday[i] < min) {
			min = stock_prices_yesterday[i];
			minpos = i;
		}
	}
	
	//Check iMin vs iMax
	if(minpos > maxpos) {
		min = 101;
		minpos = 0;
		for(int i = 0; i < maxpos; i++) {
			if(stock_prices_yesterday[i] < min) {
				min = stock_prices_yesterday[i];
				minpos = i;
			}
		}
	} //Cannot exit here without iMin < iMax

	for(int i = 0; i < 100; i++) {
		if(i%10 == 1) {
			cout << endl;
		}
		cout << stock_prices_yesterday[i] << " ";
	}
	cout << endl;
	
	cout << "Buy at time: "  << minpos << " With value: " << min << endl << "Sell at time: " << maxpos << " With Value: " << max << endl << "Total Value: " << (max-min) << endl;
	//Wall clock time before test: 11:09am
	//Wall clock time of working program: 11:14am
	return 0;
}