// You have an array of N non-negative integers, and you need to answer Q queries.
// Each query is described as follows: 
// Given l,r you need to find the pairwise product sum
// alal+
// al+1al+1 + al+1al +
// al+2al+2 + al+2al+1 + al+2al +
// ...
// + arar + arar-1 + ... + aral
// Input
// The first line will contain a single integer N. The second line will contain an array of N integers.
// The third line will contain a single integer Q. The following Q lines will contain queries of the form li, ri.
// Note that li and ri are zero-based.
// Constraints
// 0 <= l <= r < N
// N <= 100000
// Q <= 100000
// 0 <= ai <= 1000000
// Output
// Print the answer for each query in a separate line.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    vector<long long> prefixSum(N + 1), prefixSquareSum(N + 1);
    for (int i = 1; i <= N; i++) {
        int currNum = numbers[i - 1];
        prefixSum[i] = prefixSum[i - 1] + currNum;
        prefixSquareSum[i] = prefixSquareSum[i - 1] + 1LL * currNum * currNum;
    }

    int Q;
    cin >> Q;
    for (int i =0; i<Q ; i++) {
        int left, right;
        cin >> left >> right;
        right++;
        long long squareSum = prefixSquareSum[right] - prefixSquareSum[left];
        long long sum = prefixSum[right] - prefixSum[left];
        cout << ((sum * sum) + squareSum) / 2 << endl;
    }

    return 0;
}