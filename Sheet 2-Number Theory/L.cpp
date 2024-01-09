// Let X and Y be non-negative integers. Let A be the bit-wise AND of X and Y.
// Let O be the bit-wise OR of X and Y.
// Given A and O, find a pair of integers X and Y such that A is their bit-wise AND,
// O is their bit-wise OR, and the absolute difference between X and Y is minimal.
// If there is no such pair, report so.
// Input
// The first line of input contains the integer T, the number of test cases (T ≤ 100).
// T cases follow on each subsequent line, each of them containing integers A and O (0 ≤ A, O < 231).
// Output
// For each test case, print the integers X and Y on a single line with a space between them.
// Make sure that X <= Y. If there are no such integers, print -1 instead.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int largestBit(int num) {
    for(int i = 30; i >= 0; i--) {
        if((num & (1 << i)) > 0) {
            return num & (1 << i);
        }
    }
    return 0;
}

bool validPair(int C, int D) {
    for(int i = 0; i < 31; i++){
        if((C & (1 << i)) > (D & (1 << i))) {
            return false;
        }
    }
    return true;
}

int main() {
    int T, X, Y, A, B, diff;
    cin >> T;
    for(int i =0 ; i < T ;i++) {
        cin >> A >> B;
        if(validPair(A, B)) {
            diff = B - A;
            Y = largestBit(diff);
            X = diff - Y;
            Y += A;
            X += A;
            cout << X << ' ' << Y << '\n';
        } 
        else 
            cout << -1 << '\n'; 
    }
    return 0;
}