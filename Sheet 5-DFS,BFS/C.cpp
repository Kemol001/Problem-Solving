// Given two integers S and t, you have to print all ways to partition the number S into 
// t elements such that they are co-primes with each other (it means the GCD of any two of them is 1) 
// and their sum is S.
// Input
// The first line contains a single integer T (1 <= T <= 40) - The number of test cases.
// For each test, Given two numbers S and t (0 < S <= 100) (1 <= t <= 30). So you have to partition S into 
// t co-prime numbers.
// For each test case, you have to output "Case {num}:". Then
// Each line should contain one possible partition. In a partition, the printed numbers
// should be ordered in non-decreasing order and two consecutive numbers should be separated by a single space.
// The partitions should be printed in ascending order.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isCoprimeWithAll(int a, const vector<int>& v) {
    for (int element : v) {
        if (__gcd(a, element) != 1) {
            return false; 
        }
    }
    return true; 
}

void dfs(int S, int t, vector<int>& partition, int current, int last) {
    if (S == 0 && t == 0) {
        for (int i = 0; i < partition.size(); i++) {
            if (i > 0) cout << " ";
            cout << partition[i];
        }
        cout << "\n";
        return;
    }
    int optimization = floor(static_cast<double>(S)/t);

    for (int i = current; i <= optimization; i++) {
        if (isCoprimeWithAll(i, partition)  &&  i >= current) {
            partition.push_back(i);
            dfs(S - i, t - 1, partition, i, current);
            partition.pop_back();
        }
    }
}

int main() {
    int T;
    cin >> T;
    int i = 1;
    while(T--){
        int S, t;
        cin >> S >> t;

        cout << "Case " << i << ":\n";
        i++;
        vector<int> partition;
        dfs(S, t, partition, 0, 0);
    }

    return 0;
}