/***********
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * 4/20/17
 * Project 1 : Subarray with Max Sum
 ***********/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "functions.hpp"

using namespace std;

// testing
int main() {
    /*
    // Console
    vector<int> testVec = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    Result res = dpMSS(testVec);
    cout << res.sum << endl;
    
    for (int i = res.low_idx; i <= res.high_idx; i++)
        cout << testVec[i] << " ";
    cout << endl;
    cout << "Subvector: " << "[" << res.low_idx << ", ";
    cout << res.high_idx << "]" << endl;

    cout << endl;
    */
    
    // Writing to a File
    OutputToFile fout("Output.txt");
    for (int i=0; i < 10; i++){
        fout << i << " ";
    }
    
    // Reading from a File
    // Xcode: Project Navigator -> Products -> right click exec file
    //  -> show in finder -> make a file named "Input.txt" -> put numbers in
    ReadFromFile fin("Input.txt");
    vector<int> v;
    int temp = 0;
    
    while (fin >> temp)
        v.push_back(temp);
    
    for(auto x : v)
        cout << x << "\n";

    
    return 0;
}



