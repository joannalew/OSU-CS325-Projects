/********************************
* Joanna Lew, Daniel Olivas, Nathan Stauffer
* CS325 project 2 algorithm run time comparison
*********************************/
#include "functions.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	double timer = 0;        //accumulates time for three runs of each algorithm
	double avg_time = 0;     //holds average of three timing runs 
	int a = 0;					//represents total amount trying to make change for
	vector<int> denominations = [1, 5, 10, 25];
	vector<int> *dnm = &denominations;
	vector<int> change;      //holds correct change for each coin
	
	ofstream outputFile;

	// Open the output file
	outputFile.open("output.txt");



	//ALGORITHM #1: changeslow

	//"a" variable may need to start at different value for different algorithms  
	a = 50;
	outputFile << "changeslow\n";
	outputFile << "A, seconds\n";
	
	//test 10 different sizes of "a"
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// find min coins using algorithm #1 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			change = changeslow(dnm, a);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;
		
		//display result
		cout << "amount of change needed at each denomination:\n";
		int minCoin = 0;
		for (int i = 0; i < change.length; i++) {
			cout << change.at(i) << " \n";
			minCoin += change.at(i);
		}
		cout << "\nminimum number of coins needed: " << minCoin << endl;

		//display time result
		cout << "For A = " << a << ", algorithm #1 took " << avg_time << " seconds" << endl;
		outputFile <<  a << ", " << avg_time << endl;

		//use whatever pattern to update "a"
		//default set to doubling "a" each iteration
		a *= 2;
		
		//clear timer
		timer = 0;
	}

	//clear change vector
	change.clear();
	
	//ALGORITHM #2: changegreedy

	//"a" variable may need to start at different value for different algorithms  
	a = 50;
	outputFile << "changegreedy\n";
	outputFile << "A, seconds\n";
	
	//test 10 different sizes of "a"
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// find min coins using algorithm #2 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			change = changegreedy(dnm, a);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;
		
		//display result
		cout << "amount of change needed at each denomination:\n";
		int minCoin = 0;
		for (int i = 0; i < change.length; i++) {
			cout << change.at(i) << " \n";
			minCoin += change.at(i);
		}
		cout << "\nminimum number of coins needed: " << minCoin << endl;

		//display time result
		cout << "For A = " << a << ", algorithm #2 took " << avg_time << " seconds" << endl;
		outputFile <<  a << ", " << avg_time << endl;

		//use whatever pattern to update "a"
		//default set to doubling "a" each iteration
		a *= 2;
		
		//clear timer
		timer = 0;
	}

	//clear change vector
	change.clear();
	
	
	//ALGORITHM #3: changedpp

	//"a" variable may need to start at different value for different algorithms  
	a = 50;
	outputFile << "changedpp\n";
	outputFile << "A, seconds\n";
	
	//test 10 different sizes of "a"
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// find min coins using algorithm #3 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			change = changedpp(dnm, a);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;
		
		//display result
		cout << "amount of change needed at each denomination:\n";
		int minCoin = 0;
		for (int i = 0; i < change.length; i++) {
			cout << change.at(i) << " \n";
			minCoin += change.at(i);
		}
		cout << "\nminimum number of coins needed: " << minCoin << endl;

		//display time result
		cout << "For A = " << a << ", algorithm #3 took " << avg_time << " seconds" << endl;
		outputFile <<  a << ", " << avg_time << endl;

		//use whatever pattern to update "a"
		//default set to doubling "a" each iteration
		a *= 2;
		
		//clear timer
		timer = 0;
	}

	
	return 0;
}
