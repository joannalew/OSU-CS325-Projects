/*********************************
 
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * Project 2: Coin Change
 
**********************************/

#include <iostream>
#include <vector>
#include <string>
#include "functions.hpp"

using namespace std;

int main() {
    ReadFromFile fin("Input.txt");
    OutputToFile fout("Output.txt");
    vector<int> coinValues;
    vector<int> result;
    int amount = 0;
    int sum;
    
    fout << "Algorithm changeslow: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);
        getrow(fin, amount);
        
        for (int& values : coinValues)
            fout << values << " ";
        fout << "\n";
        
        result = changeslow(coinValues, amount);
        for (int& count : result){
            fout << count << " ";
            sum += count;
        }
        fout << "\n";
        fout << sum << "\n";
        
        coinValues.clear();
        if (fin.checkEnd())
            break;
    }
    
    fin.beginAnew();
    fout << "\n";
    
    fout << "Algorithm changegreedy: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);
        getrow(fin, amount);
        
        for (int& values : coinValues)
            fout << values << " ";
        fout << "\n";
        
        result = changegreedy(coinValues, amount);
        for (int& count : result){
            fout << count << " ";
            sum += count;
        }
        fout << "\n";
        fout << sum << "\n";
        
        coinValues.clear();
        if (fin.checkEnd())
            break;
    }

    fin.beginAnew();
    fout << "\n";
    
    fout << "Algorithm changedp: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);
        getrow(fin, amount);
        
        for (int& values : coinValues)
            fout << values << " ";
        fout << "\n";
        
        result = changedp(coinValues, amount);
        for (int& count : result){
            fout << count << " ";
            sum += count;
        }
        fout << "\n";
        fout << sum << "\n";
        
        coinValues.clear();
        if (fin.checkEnd())
            break;
    }
    
    return 0;
}
