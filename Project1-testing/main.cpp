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

int main(int argc, char* argv[]) {
   
    vector<int> testVec;
   
    //take input from file and fill vector 
    ReadFromFile fin(argv[0]);       
    int temp = 0;        
    
    while (fin >> temp)        
        testVec.push_back(temp);        
    
    //display original array
    cout << "array from file: \n";
    for(auto x : testVec)        
        cout << x << " ";
    cout << endl << endl;
    
    //run algorithm 1
    Result res = badMSS(testVec);    
    //write result to file
    OutputToFile fout("Output.txt");
    fout << "max subarray for algorithm #1:\n";
    for (int i = res.low_idx; i <= res.high_idx; i++)        
        fout << testVec[i] << " ";    
    fout << "/n";
    fout << "sum: " << res.sum << "\n";
    
    //run algorithm 2
    res = betterMSS(testVec);
    //write result to file
    fout << "max subarray for algorithm #2:\n";    
    for (int i = res.low_idx; i <= res.high_idx; i++)                
        fout << testVec[i] << " ";        
    fout << "/n";    
    fout << "sum: " << res.sum << "\n";
    
    //run algorithm 3
    res = recursiveMSS(testVec);
    //write result to file
    fout << "max subarray for algorithm #3:\n";    
    for (int i = res.low_idx; i <= res.high_idx; i++)                
        fout << testVec[i] << " ";        
    fout << "/n";    
    fout << "sum: " << res.sum << "\n";
    
    //run algorithm 4
    res = dppMSS(testVec);
    //write result to file
    fout << "max subarray for algorithm #4:\n";    
    for (int i = res.low_idx; i <= res.high_idx; i++)                
        fout << testVec[i] << " ";        
    fout << "/n";    
    fout << "sum: " << res.sum << "\n";

    return 0;
}



