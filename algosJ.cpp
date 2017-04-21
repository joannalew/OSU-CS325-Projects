/***********
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * 4/20/17
 * Project 1 : Subarray with Max Sum
 ***********/

#include <iostream>
#include <vector>
using namespace std;


struct Result {
    int sum;
    int low_idx;
    int high_idx;
};

/** Gets the larger of two numbers
    @param a is the first integer to be compared
    @param b is the second integer to be compared
    @returns the larger of the two integers; either a or b
 **/
int max(int a, int b){
    return (a > b) ? a : b;
}


/** Finds the subvector with the largest sum
    Using 3 for-loops
    @param nums is the vector to be searched over 
    @returns a Result with the sum, subvector begin, end indices 
**/
Result badMSS(vector<int>& nums){
    size_t size = nums.size();
    Result maax;
    maax.sum = 0;
    
    for (int i=0; i < size; i++)
        for (int j=i+1; j < size; j++){
            int tempSum = 0;
            
            for (int k=i; k <= j; k++)
                tempSum += nums[k];        // loop to add sum
            
            if (tempSum > maax.sum){       // if local max > global max
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
Result betterMSS(vector<int>& nums){
    size_t size = nums.size();
    Result maax;
    maax.sum = 0;
    int tempSum;
    
    for (int i=0; i < size; i++){
        tempSum = 0;
        for (int j=i; j < size; j++){
            tempSum += nums[j];            // keep recurring sum
            
            if (tempSum > maax.sum){       // if local max > global max
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
void recursiveMSS(vector<int>& nums, int left, int right, Result& maax, Result& lmax, Result& rmax, Result& sum){
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
        if (maax.sum == maax1.sum){
            maax.low_idx = maax1.low_idx;
            maax.high_idx = maax1.high_idx;
        }
        else if (maax.sum == maax2.sum){
            maax.low_idx = maax2.low_idx;
            maax.high_idx = maax2.high_idx;
        }
        else{
            maax.low_idx = rmax1.low_idx;
            maax.high_idx = lmax2.high_idx;
        }
        
        // lmax = max starting in left
        lmax.sum = max(lmax1.sum, sum1.sum + lmax2.sum);
        if (lmax.sum == sum1.sum + lmax2.sum){
            lmax.low_idx = sum1.low_idx;
            lmax.high_idx = lmax2.high_idx;
        }
        else{
            lmax.low_idx = lmax1.low_idx;
            lmax.high_idx = lmax1.high_idx;
        }
        
        // rmax = max ending in right
        rmax.sum = max(rmax2.sum, sum2.sum + rmax1.sum);
        if (rmax.sum == sum2.sum + rmax1.sum){
            rmax.low_idx = rmax1.low_idx;
            rmax.high_idx = sum2.high_idx;
        }
        else{
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
Result recursiveMSS(vector<int>& nums){
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
Result dpMSS(vector<int>& nums){
    size_t size = nums.size();
    Result maax;
    maax.sum = 0;
    int tempSum = 0;
    
    for (int i=0; i < size; i++){
        tempSum += nums[i];             // running sum
        
        if (tempSum <= 0){              // if sum turns negative
            tempSum = 0;                // reset it to 0
            maax.low_idx = i+1;         // next potential "largest sum" subvector
            maax.high_idx = i+1;        // begins at next element, i+1
        }
        else if (tempSum > maax.sum){   // if local sum > global
            maax.sum = tempSum;         // replace global with local
            maax.high_idx++;            // extend the subvector
        }
    }
    return maax;
}

// testing
int main() {
    vector<int> testVec = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    Result res = dpMSS(testVec);
    cout << res.sum << endl;
    
    for (int i = res.low_idx; i <= res.high_idx; i++)
        cout << testVec[i] << " ";
    cout << endl;
    cout << "Subvector: " << "[" << res.low_idx << ", ";
    cout << res.high_idx << "]" << endl;

    cout << endl;
    
    return 0;
}
