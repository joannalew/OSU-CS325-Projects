/***********
 * Daniel Olivas, Nathan Stauffer, Joanna Lew
 * 6/6/17
 * Project 3 : TSP
 ***********/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include "functions.hpp"

using namespace std;

int findDistance(vector<int> cities, int city1, int city2){
    double distance = sqrt( pow(cities[city2*3 + 1] - cities[city1*3 + 1], 2) +
                            pow(cities[city2*3 + 2] - cities[city1*3 + 2], 2) );
    int rounded = round(distance);
    
    return rounded;
}


int main() {
    vector<int> cities;
    vector<int> distances;
    vector<int> visited;
    int distance;
    
    ReadFromFile fin("Input.txt");
    
    // get the data from file; shove into vector called cities
    // format is [id, x, y, id, x, y, ...]
    while (true){
        getrow(fin, cities);
    
        if (fin.checkEnd())
            break;
    }
    
    int num_cities = cities.size() / 3;
    int start = 0;
    
    // create a n*n sized vector with all the distances
    // format is [d00, d01, d02, ..., d0n, d10, d11, d12, ...]
    for (int i = 0; i < num_cities; i++){
        for (int j = 0; j < num_cities; j++){
            distance = findDistance(cities, i, j);
            distances.push_back(distance);
        }
    }
    
    
    
    
    return 0;
}



