/*********************************
 
 * Joanna Lew
 * Project 2: Coin Change
 
**********************************/

#include <iostream>
#include <vector>

using namespace std;

/** Greedy approach to coin change
    @param values is a vector of available coin values
    @param amount is the amount being converted to coin change
    @returns vector of coin count  */
vector<int> changegreedy(vector<int>& values, int amount){
    int i = values.size() - 1;              // largest coin value
    vector<int> coins(values.size(), 0);    // number of each coin
    
    while (i >= 0 && amount != 0){
        if (values[i] <= amount){           // subtract largest coin
            amount -= values[i];            // from amount
            coins[i]++;
        }
        else                                // if amount < coin value
            --i;                            // go down a coin size
    }
    return coins;
}

/** Dynamic programming approach to coin change
    @param values is a vector of available coin values
    @param amount is the amount being converted to coin change
    @returns vector of coin count */
vector<int> changedp(vector<int>& values, int amount){
    int max = amount + 1;               // arbritary large value
    int size = values.size();           // number of available coins
    int csize = size * max;
    vector<int> coins(csize, 0);        // holds coin count for every amount
    vector<int> dp(max, max);           // holds sum(coin count) for every amount
    dp[0] = 0;                          // initial condition
    
    // go through every amount from [1 ... given amount]
    // and test each coin combination
    for (int i=1; i <= amount; ++i){
        for (int j=0; j < size; ++j){
            // if value subtractable, must be previous number of coins + 1
            // save the coin count subvector
            if (values[j] <= i){
                dp[i] = min(dp[i], dp[i - values[j]] + 1);
                if (dp[i] == dp[i - values[j]] + 1){
                    for (int k=0; k < size; ++k)
                        coins[i * size + k] = coins[(i - values[j]) * size + k];
                    coins[i * size + j]++;
                }
            }
        }
    }
    
    // return only the coin count subvector for amount given
    vector<int> subCoins;
    for (int i = csize - size; i < csize; i++){
        subCoins.push_back(coins[i]);
    }
    
    return subCoins;
}



/********************************************
        MAIN
 ********************************************/

int main() {
    vector<int> values = {1, 3, 7, 12};
    int sum = 0;
    int number = 29;
    
    cout << "Greedy: \n";
    vector<int> coins = changegreedy(values, number);
    for (auto& x : coins){
        cout << x << " ";
        sum += x;
    }
    cout << "\n" << sum << "\n";
    cout << "\n";
    
    sum = 0;
    
    cout << "Dynamic: \n";
    vector<int> dp = changedp(values, number);
    for (auto& x : dp){
        cout << x << " ";
        sum += x;
    }
    cout << "\n" << sum << "\n";
    cout << "\n";
    
    return 0;
}
