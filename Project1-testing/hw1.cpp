/*********************************
 
 * Joanna Lew
 * OSU CS 325 - Spring 2017
 * Homework 1
 * Comparing experimental run times of merge sort and insertion sort
 
**********************************/

#include <iostream>
#include <chrono>
#include <random>
#include <vector>

typedef std::chrono::high_resolution_clock Clock;

/** Sorts a vector of integers in ascending order using Insertion Sort
    @param vec is the vector to be sorted (changed by function) */
void insertionSort(std::vector<int> &vec){
    size_t size = vec.size();
    int temp = 0;
    
    // for every element after the first element
    for (int i = 1; i < size; ++i){
        // compare each element with previous element
        // if element is smaller, swap with previous
        for (int j = i; j > 0 && vec[j-1] > vec[j]; --j){
            temp = vec[j];
            vec[j] = vec[j-1];
            vec[j-1] = temp;
        }
    }
    return;
}

/** Helper Function for mergeSort
    Merges two subvectors in ascending order
    @param left is a subvector
    @param right is a subvector
    @param result is the resulting merged vector (changed by function) */
void merge(std::vector<int> left, std::vector<int> right, std::vector<int> &result){
    size_t lsize = left.size();
    size_t rsize = right.size();
    int lindex = 0;
    int rindex = 0;
    result.clear();
    
    // While there are elements in both subvectors
    // Compare first element of each subvector to see which is smaller
    // Add smaller element to result vector
    while (lindex < lsize && rindex < rsize){
        if (left[lindex] <= right[rindex]){
            result.push_back(left[lindex]);
            ++lindex;
        }
        else{
            result.push_back(right[rindex]);
            ++rindex;
        }
    }
    
    // Put any leftover elements in subvector
    // into result vector
    while (lindex < lsize){
        result.push_back(left[lindex]);
        ++lindex;
    }
    
    while(rindex < rsize){
        result.push_back(right[rindex]);
        ++rindex;
    }
    
    return;
}

/** Sorts a vector of integers in ascending order using Merge Sort
    @param vec is the vector to be sorted (changed by function) */
void mergeSort(std::vector<int> &vec){
    size_t size = vec.size();
    
    // base case: a list of 0 or 1 elements is sorted by definition
    if (size <= 1)
        return;
    
    // recursive case:
    // divide the vector into equal-sized subvectors
    // consisting of the first half and second half of vector
    std::vector<int> left;
    std::vector<int> right;
    
    for (int i=0; i < size; ++i){
        if (i < size / 2)
            left.push_back(vec[i]);
        else
            right.push_back(vec[i]);
    }
    
    // recursively divide subvectors
    // until they are trivially sorted
    mergeSort(left);
    mergeSort(right);
    
    // merge sublists in sorted order
    merge(left, right, vec);
    
    return;
}


/** Merges two subvectors into one vector
    @param left is a subvector to be merged
    @param right is a subvector to be merged
    @param res is the resulting vector (changed by function) */
void mergeUnsorted(std::vector<int> left, std::vector<int> right, std::vector<int> &res){
    size_t lsize = left.size();
    size_t rsize = right.size();
    res.clear();
    
    for (int i=0; i < lsize; ++i)
        res.push_back(left[i]);
    for (int j=0; j < rsize; ++j)
        res.push_back(right[j]);
    
    return;
}

/** Generates worst case vector for Merge Sort
    @param vec is the vector to be turned into worst case 
        (changed by function) */
void unsort(std::vector<int> &vec){
    size_t size = vec.size();
    
    if (size <= 1)
        return;
    
    if (size == 2){
        int swap = vec[0];
        vec[0] = vec[1];
        vec[1] = swap;
        return;
    }
    
    std::vector<int> left;
    std::vector<int> right;
    
    for (int i=0; i < size; i+=2)
        left.push_back(vec[i]);
        
    for (int i=1; i < size; i+=2)
        right.push_back(vec[i]);

    
    unsort(left);
    unsort(right);
    mergeUnsorted(left, right, vec);
    
    return;
}

/********************************************
        MAIN
 ********************************************/

int main() {
    int numEle = 0;
    std::vector<int> vlist;
    
    // get the number of elements from user
    while (numEle < 1){
        std::cout << "Please enter the number of elements in the vector: ";
        std::cin >> numEle;
    }
    
    // set the seed for random numbers in [0, vector size]
    // 'rd' for non-deterministic 32-bit seed
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, numEle);
    
    // average case:
    // fill the vector with random numbers from [0, vector size]
    
    for (int i=0; i < numEle; ++i)
        vlist.push_back(dist(mt));
    
    
    // best case:
    // fill the vector with numbers in ascending order
    /*
    for (int i=0; i < numEle; ++i)
        vlist.push_back(i);
    */
    
    // insertion sort worst case:
    // fill the vector with numbers in descending order
    /*
    for (int i=numEle; i > 0; --i)
        vlist.push_back(i);
    */
    
    // merge sort worst case:
    // make it so each subvector has the greatest # of comparisons/swaps
    /*
    for (int i=0; i < numEle; ++i)
        vlist.push_back(i);
    unsort(vlist);
    */
    
    // perform sort
    auto t1 = Clock::now();
    //insertionSort(vlist);
    mergeSort(vlist);
    auto t2 = Clock::now();
    
    // get the time it took to perform sort
    std::cout << "Delta t2-t1: "
    << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
    << " nanoseconds" << std::endl;
    std::cout << std::endl;
    
    
    // Check if in sorted order
    /*
    for (auto x : vlist)
        std::cout << x << " ";
    std::cout << std::endl;
    */
    
    
    return 0;
}
