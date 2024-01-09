// Twin primes are pairs of integers p, p+2 such that p and p+2 are both prime.
// Some examples of twin prime pairs are (11, 13), (17, 19), and (29, 31).
// Given an integer n, find the nth twin prime pair.
// Input
// Input will consist of multiple test cases. Each test case will be on a single line and will consist of a single
// integer n, 1<=n<=105. There will be at most 104 test cases.
// Output
// For each test case, output the n-th twin prime pair on a single line in the following format :
// (p, q)
// You can assume that the 100000th twin prime pair is less than 2 * 107.

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <bitset>
#define MAX 20000000
using namespace std;

vector<pair<int, int>> primePairs;
bitset<MAX> bitSet;

void sieve() {
    bitSet.set();
    bitSet[0] = bitSet[1] = 0;
    for (long long i = 2; i <= MAX; i++) {
        if (bitSet[i]) {
            for (long long j = i * i; j <= MAX; j += i) {
                bitSet[j] = 0;
            }
        }
    }

    for (long long x = 3; x <= MAX - 2; x++) {
        if (bitSet[x] && bitSet[x + 2]) primePairs.push_back(make_pair(x, x + 2));
    }
}

int main() {
    sieve();
    int number;
    while (cin >> number) {
        cout << "(" << primePairs[number - 1].first << ", " << primePairs[number - 1].second << ")" << endl;
    }
    return 0;
}