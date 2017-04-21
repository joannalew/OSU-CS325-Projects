/***********
 * Joanna Lew
 * 4/13/17
 * Project 1 Algorithm 3 : Recursive MSS
 ***********/

#include <iostream>
#include <vector>
using namespace std;

struct Result {
    int sum;
    int low_idx;
    int high_idx;
};


int max(int a, int b){
    return (a > b) ? a : b;
}


void maxSubArray(vector<int>& nums, int left, int right, Result& maax, Result& lmax, Result& rmax, Result& sum) {
    
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
        maxSubArray(nums, left, mid, maax1, lmax1, rmax1, sum1);
        maxSubArray(nums, mid + 1, right, maax2, lmax2, rmax2, sum2);
        
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

Result maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) {
        Result empty;
        empty.sum = 0;
        empty.low_idx = -1;
        empty.high_idx = -1;
        
        return empty;
    }
    
    Result maax, lmax, rmax, sum;
    maxSubArray(nums, 0, nums.size() - 1, maax, lmax, rmax, sum);
    return maax;
}


// testing
int main() {
    vector<int> testVec = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    Result res = maxSubArray(testVec);
    cout << res.sum << endl;
    
    for (int i = res.low_idx; i <= res.high_idx; i++)
        cout << testVec[i] << " ";
    cout << endl;
    cout << "Subvector: " << "[" << res.low_idx << ", ";
    cout << res.high_idx << "]" << endl;

    cout << endl;
    
    return 0;
}
