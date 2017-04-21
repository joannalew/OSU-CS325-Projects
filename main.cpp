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
int main(int argc, char* argv[]) {
    
    // Console
    vector<int> testVec;
   
    // Reading from a File    
    // Xcode: Project Navigator -> Products -> right click exec file    
    //  -> show in finder -> make a file named "Input.txt" -> put numbers in   
    ReadFromFile fin(argv[0]);       
    int temp = 0;        
    
    while (fin >> temp)        
        testVec.push_back(temp);        
    
    for(auto x : v)        
        cout << x << "\n";
    
    Result res = dpMSS(testVec);    
    cout << res.sum << endl;        
    
    for (int i = res.low_idx; i <= res.high_idx; i++)        
        cout << testVec[i] << " ";    
    cout << endl;    
    
    cout << "Subvector: " << "[" << res.low_idx << ", ";    
    cout << res.high_idx << "]" << endl;
    cout << endl;
    
    
    
    
    
    // Writing to a File
    OutputToFile fout("Output.txt");
    for (int i=0; i < 10; i++){
        fout << i << " ";
    }
    
    

    
    return 0;
}



