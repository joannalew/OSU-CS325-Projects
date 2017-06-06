/*********************************
 
 * Joanna Lew
 * Project 2: Coin Change
 
**********************************/

#include <iostream>
#include <vector>

using namespace std;

/** Helper function for recursive approach to coin change
    @param values is a vector of available coin values
    @param amount is the (remaining) amount being converted to coin change
    @param coins is the total coins needed for amounts [1 ... specified amount]
    @param subcoins is the # of each coin needed for amounts [1 ... specified amount]
    @returns minimum total coins needed for amount specified  
    @returns @coins and @subcoins are passed by reference, and changed */
int slowHelper(vector<int>& values, int amount, vector<int>& coins, vector<int>& subcoins){
    int size = values.size();               // number of coins available
    
    if (amount < 0)                         // trivial cases
        return -1;
    else if (amount == 0)
        return 0;
    
    if (coins[amount - 1] != -123)          // if # of coins for amount already calculated
        return coins[amount - 1];           // use that value
    
    // calculate the least number of coins by
    // finding the minimum # of coins needed to make (amount - coin) cents
    int min = amount + 1;
    for (int i=0; i < size; i++){
        int res = slowHelper(values, amount - values[i], coins, subcoins);
        if (res >= 0 && res < min){
            min = res + 1;
            // save the individual coin count
            for (int j=0; j < size; j++)
                subcoins[amount * size + j] = subcoins[(amount - values[i]) * size + j];
            subcoins[amount * size + i]++;
        }
    }
    coins[amount - 1] = min;
    return coins[amount - 1];
}

/** Recursive approach to coin change
    @param values is a vector of available coin values
    @param amount is the amount being converted to coin change
    @returns vector of coin count  */
vector<int> changeslow(vector<int>& values, int amount){
    int subSize = values.size() * (amount + 1);
    vector<int> coins(amount, -123);                // total count of all coins for the amount
    vector<int> subcoins(subSize, 0);               // count of each coin for the amount
    
    // if amount is 0, return 0 coins each
    // otherwise, see helper function
    if (amount == 0)
        return subcoins;
    slowHelper(values, amount, coins, subcoins);
    
    // return the individual coin count for amount specified
    vector<int> result;
    for (int i = subSize - values.size(); i < subSize; i++){
        result.push_back(subcoins[i]);
    }
    return result;
}


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
    int max = amount + 1;                   // arbritary large value
    int size = values.size();               // number of available coins
    int csize = size * max;
    vector<int> coins(csize, 0);            // holds coin count for every amount
    vector<int> dp(max, max);               // holds sum(coin count) for every amount
    dp[0] = 0;                              // initial condition
    
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
    vector<int> values = {1, 3, 7, 12, 15};
    int sum = 0;
    int number = 0;
    
    cout << "Recursive: \n";
    vector<int> recur = changeslow(values, number);
    for (int& x : recur){
        cout << x << " ";
        sum += x;
    }
    cout << "\n" << sum << "\n";
    cout << "\n";
    
    sum = 0;
    
    cout << "Greedy: \n";
    vector<int> greedy = changegreedy(values, number);
    for (int& x : greedy){
        cout << x << " ";
        sum += x;
    }
    cout << "\n" << sum << "\n";
    cout << "\n";
    
    sum = 0;
    
    cout << "Dynamic: \n";
    vector<int> dp = changedp(values, number);
    for (int& x : dp){
        cout << x << " ";
        sum += x;
    }
    cout << "\n" << sum << "\n";
    cout << "\n";
    
    return 0;
}
