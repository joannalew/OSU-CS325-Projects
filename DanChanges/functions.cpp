///
//  functions.cpp
//  hw1.1
//
//  Created by Joanna on 4/21/17.
//  Copyright © 2017 Joanna. All rights reserved.
//

#include "functions.hpp"

/** Gets the larger of two numbers
@param a is the first integer to be compared
@param b is the second integer to be compared
@returns the larger of the two integers; either a or b
**/
int max(int a, int b) {
	return (a > b) ? a : b;
}

/** Finds the subvector with the largest sum
Using 3 for-loops
@param nums is the vector to be searched over
@returns a Result with the sum, subvector begin, end indices
**/
Result badMSS(vector<int>& nums) {
	size_t size = nums.size();
	Result maax;
	maax.sum = 0;

	for (int i = 0; i < size; i++)
		for (int j = i; j < size; j++) {
			int tempSum = 0;

			for (int k = i; k <= j; k++)
				tempSum += nums[k];        // loop to add sum

			if (tempSum > maax.sum) {       // if local max > global max
				maax.sum = tempSum;        // set global to local
				maax.low_idx = i;          // and change indices
				maax.high_idx = j;
			}
		}
	return maax;
}

/** Finds the subvector with the largest sum
Using 2 for-loops
@param nums is the vector to be searched over
@returns a Result with the sum, subvector begin, end indices
**/
Result betterMSS(vector<int>& nums) {
	size_t size = nums.size();
	Result maax;
	maax.sum = 0;
	int tempSum;

	for (int i = 0; i < size; i++) {
		tempSum = 0;
		for (int j = i; j < size; j++) {
			tempSum += nums[j];            // keep recurring sum

			if (tempSum > maax.sum) {       // if local max > global max
				maax.sum = tempSum;        // set global to local
				maax.low_idx = i;          // and change indices
				maax.high_idx = j;
			}
		}
	}
	return maax;
}

/** Finds the subvector with the largest sum
Using recursion
Base Case: size = 1, element is largest subvector
All other: divide vector in half until size 1, find max, compare & pass up
@param nums is the vector to be searched over
@param left is the beginning of the vector (global)
@param right is the end of the vector
@param maax is the total subarray with largest sum
@param lmax is the left subarray with the largest sum
@param rmax is the right subarray with the largest sum
@param sum is the total subarray's sum
Doesn't return a value, but @maax, @lmax, @rmax, @sum are passed by reference
So those values changed and "passed up"
**/
void recursiveMSS(vector<int>& nums, int left, int right, Result& maax, Result& lmax, Result& rmax, Result& sum) {
	// base case: if there's only one element
	// sum = that element
	if (left == right) {
		maax.sum = lmax.sum = rmax.sum = sum.sum = nums[left];
		maax.low_idx = lmax.low_idx = rmax.low_idx = sum.low_idx = left;
		maax.high_idx = lmax.high_idx = rmax.high_idx = sum.high_idx = left;
	}

	// if there's more than one element
	else {
		int mid = (left + right) / 2;
		Result maax1, lmax1, rmax1, sum1;
		Result maax2, lmax2, rmax2, sum2;

		// recursively perform function on left half, right half
		recursiveMSS(nums, left, mid, maax1, lmax1, rmax1, sum1);
		recursiveMSS(nums, mid + 1, right, maax2, lmax2, rmax2, sum2);

		// find the max & indices, and pass back up
		// maax = max over the whole subarray (left, right, cross)
		maax.sum = max(max(maax1.sum, maax2.sum), rmax1.sum + lmax2.sum);
		if (maax.sum == maax1.sum) {
			maax.low_idx = maax1.low_idx;
			maax.high_idx = maax1.high_idx;
		}
		else if (maax.sum == maax2.sum) {
			maax.low_idx = maax2.low_idx;
			maax.high_idx = maax2.high_idx;
		}
		else {
			maax.low_idx = rmax1.low_idx;
			maax.high_idx = lmax2.high_idx;
		}

		// lmax = max starting in left
		lmax.sum = max(lmax1.sum, sum1.sum + lmax2.sum);
		if (lmax.sum == sum1.sum + lmax2.sum) {
			lmax.low_idx = sum1.low_idx;
			lmax.high_idx = lmax2.high_idx;
		}
		else {
			lmax.low_idx = lmax1.low_idx;
			lmax.high_idx = lmax1.high_idx;
		}

		// rmax = max ending in right
		rmax.sum = max(rmax2.sum, sum2.sum + rmax1.sum);
		if (rmax.sum == sum2.sum + rmax1.sum) {
			rmax.low_idx = rmax1.low_idx;
			rmax.high_idx = sum2.high_idx;
		}
		else {
			rmax.low_idx = rmax2.low_idx;
			rmax.high_idx = rmax2.high_idx;
		}

		// sum = sum over the whole subarray
		sum.sum = sum1.sum + sum2.sum;
	}
}


/** Finds the subvector with the largest sum
Using recursion (Base Case: size = 1, element is largest subvector)
@param nums is the vector to be searched over
@returns a Result with the sum, subvector begin, end indices
**/
Result recursiveMSS(vector<int>& nums) {
	// if empty vector, return no largest sum
	if (nums.size() == 0) {
		Result empty;
		empty.sum = 0;
		empty.low_idx = empty.high_idx = -1;
		return empty;
	}

	// if not empty vector, see helper function
	Result maax, lmax, rmax, sum;
	recursiveMSS(nums, 0, nums.size() - 1, maax, lmax, rmax, sum);
	return maax;
}


/** Finds the subvector with the largest sum
Using dynamic programming
@param nums is the vector to be searched over
@returns a Result with the sum, subvector begin, end indices
**/
Result dpMSS(vector<int>& nums) {
	size_t size = nums.size();
	Result maax, temp;
	maax.sum = temp.sum = 0;
	maax.low_idx = temp.low_idx = 0;
	maax.high_idx = temp.high_idx = 0;


	for (int i = 0; i < size; i++) {
		temp.sum += nums[i];             // running sum
		if (temp.sum <= 0) {              // if sum turns negative
			temp.sum = 0;                // reset it to 0
			if (i + 1 < size) {
				temp.low_idx = i + 1;      // next potential "largest sum" subvector
				temp.high_idx = i + 1;     // begins w/ the next element in vector
			}
		}
		else if (temp.high_idx + 1 < size && temp.low_idx != i) {
			temp.high_idx++;             // extend subvector if possible (tempSum > 0, in bounds)
		}
		if (temp.sum > maax.sum) {        // if local max > global max
			maax.sum = temp.sum;         // replace max and indices
			maax.low_idx = temp.low_idx;
			maax.high_idx = temp.high_idx;
		}
	}
	return maax;
}


/** Constructor: open file and check that file is readable
@param filename is the name of the file to open
@writes "Couldn't open file!" to console if failed to open file */
/*ReadFromFile::ReadFromFile(const string& filename) : fin(filename) {
	if (fin.fail())
		cout << "Couldn't open file!\n";

};

/** Destructor automatically closes file *//*
ReadFromFile::~ReadFromFile() {
	fin.close();
}


ReadFromFile& operator >> (ReadFromFile& input_file, int& a) {
	input_file.fin >> a;
	return input_file;
}

ReadFromFile::operator bool() {
	return !fin.fail();
}*/



OutputToFile::OutputToFile(const string& filename) : fout(filename) { }

OutputToFile& operator<<(OutputToFile& output_file, int a) {
	output_file.fout << a;
	return output_file;
}

OutputToFile& operator<<(OutputToFile& output_file, const string& s) {
	output_file.fout << s;
	return output_file;
}

OutputToFile::~OutputToFile() {
	fout.close();
}