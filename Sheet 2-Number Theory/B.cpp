// You are given a function G(x) which is defined as follows:
// At x = 0, G(x) = 0
// At x = 1, G(x) = 1
// At x = 2, G(x) = 2
// If x is an odd prime, G(x) = 0
// Otherwise, x can be represented as a * b where the sum of a and b is minimum, then G(x) = G(a) + G(b).
// Given an integer n, evaluate G(n).
// Constraints
// 1 <= n <= 100000
// Input
// The input consists of a single integer n.
// Output
// Output the value of G(n) on a single line.

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int computeG(int x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;

    bool isOddPrime = true;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            isOddPrime = false;
            break;
        }
    }

    if (isOddPrime) {
        return 0;
    }

    vector<pair<int,int>> factors;

    for (int i = 2; i*i <= x; i++) {
        if(x % i == 0)
            factors.push_back(pair<int,int>(i,x/i)); 
    }
    int minSum = INT_MAX;
    int minIndex = -1;
    for (int j = 0; j<factors.size(); j++){
        int sum = factors[j].first+factors[j].second;
        if(minSum > sum){
            minSum = sum;
            minIndex = j;
        }
    }
    return computeG(factors[minIndex].first)+computeG(factors[minIndex].second);
}

int main() {
    int n;
    cin >> n;

    cout << computeG(n) << endl;

    return 0;
}