/*********************************
 
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * Project 2: Coin Change
 
 **********************************/

#include <iostream>
#include <vector>
#include <string>
#include "functions.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc > 2){
        cout << "Too many arguments. \n";
        return 0;
    }
    else if (argc < 2){
        cout << "Please enter filename. \n";
        return 0;
    }
    
    string outfile = argv[1];
    outfile = outfile.substr(0,outfile.size()-4);
    outfile += "change.txt";
    cout << "outfile: " << outfile << "\n";
    
    ReadFromFile fin(argv[1]);
    OutputToFile fout(outfile);
    vector<int> coinValues;
    vector<int> result;
    int amount = 0;
    int sum;
    
    fout << "Algorithm changeslow: \n";
    while (true){
        sum = 0;
        getrow(fin, coinValues);
        getrow(fin, amount);
        
        if (coinValues.empty())
            break;
        
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
        
        if (coinValues.empty())
            break;
        
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
        
        if (coinValues.empty())
            break;
        
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

