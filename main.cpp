/***********
 * Joanna Lew
 * 4/13/17
 * HW 2(a) : Quaternary Search
 ***********/

#include <iostream>
#include <vector>
using namespace std;

int algo1(vector<int> vec){
    size_t size = vec.size();
    int sum = 0;
    int max = 0;
    int maxlength = 0;
    int left = 0;
    
    for (int i=0; i < size; i++){
        for (int j=i+1; j < size; j++){
            sum = 0;
            for (int k=i; k <= j; k++){
                sum += vec[k];
            }
            if (sum > max){
                left = i;
                maxlength = j-i+1;
                max = sum;
            }
        }
    }
    cout << "SubVector: ";
    for (int i=left; i < maxlength; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << "Sum: " << max << endl;

    return 0;
}


int algo2(vector<int> vec){
    size_t size = vec.size();
    int sum = 0;
    int max = 0;
    int maxlength = 0;
    int left = 0;
    
    for (int i=0; i < size; i++){
        sum = 0;
        for (int j=i+1; j < size; j++){
            sum += vec[j];
            if (sum > max){
                left = i;
                maxlength = j-i+1;
                max = sum;
            }
        }
    }
    cout << "SubVector: ";
    for (int i=left; i < maxlength; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << "Sum: " << max << endl;
    
    return 0;
}


int max(int a, int b){
    return (a > b) ? a : b;
}

int max(int a, int b, int c){
    return max(max(a, b), c);
}

int algo3Helper(vector<int> vec, int start, int end, int mid){
    int sum = 0, leftSum = 0, rightSum = 0;
    
    for (int i = mid; i >= start; i--){
        sum += vec[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    
    sum = 0;
    for (int i = mid+1; i <= end; i++){
        sum += vec[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    
    return leftSum + rightSum;
}

int algo3(vector<int> vec, int start, int end){
    int mid = (end + start)/2;
    
    if (vec.size() == 1)
        return vec[0];
    
    return (max(algo3(vec, start, mid),
                algo3(vec, mid+1, end),
                algo3Helper(vec, start, end, mid)));
    
}


int algo4(vector<int> vec){
    vector<int> v2;
    
    
    
    return 0;
}



// testing
int main() {
    vector<int> testVec = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    algo2(testVec);
    
    return 0;
}
