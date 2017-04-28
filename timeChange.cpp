/********************************
* Joanna Lew, Daniel Olivas, Nathan Stauffer
* CS325 project 2 algorithm run time comparison
* NOTE: the main method of jo-coinchange.cpp will need commented out
*********************************/
#include "jo-coinchange.cpp"
#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	double timer = 0;        //accumulates time for three runs of each algorithm
	double avg_time = 0;     //holds average of three timing runs 
	int numEle = 0;
	vector<int> vlist;
	vector<int> change;      //holds correct change for each coin
	
	ofstream outputFile;

	// Open the output file
	outputFile.open("output.txt");

	// set the seed for random numbers   
	// 'rd' for non-deterministic 32-bit seed    
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(-99, 99);

	//ALGORITHM #1: changeslow

	//numele variable may need to start at different value for different algorithms  
	numEle = 50;
	outputFile << "changeslow\n";
	outputFile << "n, seconds\n";
	//fill vector with first numEle elements
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// fill the rest of larger vector with random numbers        
		for (int j = numEle; j < numEle +50; ++j)
			vlist.push_back(dist(mt));
		numEle += 50;
		
		// find min coins using algorithm #1 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			change = changeslow(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;
		
		//display result
		int minCoin = 0;
		for (int i = 0; i < change.length; i++) {
			minCoin += change.at(i);
		}
		cout << "minimum number of coins needed: " << minCoin << endl;

		//display time result
		cout << "For vector size " << numEle << ", algorithm #1 took " << avg_time << " seconds" << endl;
		outputFile <<  numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}

	//clear vectors
	vlist.clear();
	change.clear();
	
	//ALGORITHM #2: changegreedy

	//numele variable may need to start at different value for different algorithms  
	numEle = 50;
	outputFile << "changegreedy\n";
	outputFile << "n, seconds\n";
	//fill vector with first numEle elements
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// fill the rest of larger vector with random numbers        
		for (int j = numEle; j < numEle +50; ++j)
			vlist.push_back(dist(mt));
		numEle += 50;
		
		// find min coins using algorithm #2 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			change = changegreedy(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;
		
		//display result
		int minCoin = 0;
		for (int i = 0; i < change.length; i++) {
			minCoin += change.at(i);
		}
		cout << "minimum number of coins needed: " << minCoin << endl;

		//display time result
		cout << "For vector size " << numEle << ", algorithm #2 took " << avg_time << " seconds" << endl;
		outputFile <<  numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}

	//clear vectors
	vlist.clear();
	change.clear();
	
	
	//ALGORITHM #3: changedpp

	//numele variable may need to start at different value for different algorithms  
	numEle = 50;
	outputFile << "changedpp\n";
	outputFile << "n, seconds\n";
	//fill vector with first numEle elements
	for (int i = 0; i < numEle; ++i)
		vlist.push_back(dist(mt));

	//test 10 different vector lengths
	for (int i = 0; i < 10; ++i) {
		cout << "round " << i+1 << "\n";
		// fill the rest of larger vector with random numbers        
		for (int j = numEle; j < numEle +50; ++j)
			vlist.push_back(dist(mt));
		numEle += 50;
		
		// find min coins using algorithm #2 and calculate run time
		// for increased accuracy, run three times and calculate average run time
		for (int k = 0; k < 3; ++k) {
			clock_t t1, t2;
			t1 = clock();
			change = changedpp(vlist);
			t2 = clock();
			double diff((double)t2 - (double)t1);
			timer += diff/CLOCKS_PER_SEC;
			
		}
		avg_time = timer / 3.0;
		
		//display result
		int minCoin = 0;
		for (int i = 0; i < change.length; i++) {
			minCoin += change.at(i);
		}
		cout << "minimum number of coins needed: " << minCoin << endl;

		//display time result
		cout << "For vector size " << numEle << ", algorithm #3 took " << avg_time << " seconds" << endl;
		outputFile <<  numEle << ", " << avg_time << endl;

		//clear timer
		timer = 0;
	}

	//clear vectors
	vlist.clear();
	change.clear();

	return 0;
}