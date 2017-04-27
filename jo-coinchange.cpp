/*********************************
 
 * Joanna Lew
 * Project 2: Coin Change
 
**********************************/

#include <iostream>
#include <vector>

using namespace std;

/** Greedy approach to coin change
    @param coins is a vector of available coin values
    @param num is the amount being converted to coin change
    @returns the number of coins necessary to turn num to coins */
int changegreedy(vector<int> coins, int num){
    int i = coins.size() - 1;       // largest coin value
    int count = 0;                  // number of coins
    
    while (i >= 0 && num != 0){
        if (coins[i] <= num){       // subtract largest coin
            num -= coins[i];        // from amount
            ++count;
        }
        else                        // if amount < coin value
            --i;                    // go down a coin size
    }
    return count;
}



/********************************************
        MAIN
 ********************************************/

int main() {
    vector<int> coins = {1, 5, 10, 25};
    int number = 40;
    
    cout << changegreedy(coins, number) << "\n";
    
    return 0;
}
