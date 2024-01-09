// Given a list of numbers A, find the length of the longest increasing subsequence in it. 
// A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements 
// without changing the order of the remaining elements. An increasing subsequence is a subsequence in which 
// each element is greater than all previous elements.
// For example, in the list {33 , 11 , 22 , 44}:
// The subsequences {33 , 44} and {11} are increasing subsequences while {11 , 22 , 44} is the longest 
// increasing subsequence.
// Input
// First line contains a single integer N (1 <= N <= 10) the length of the list A.
// The second line contains N numbers (1 <= each number <= 20), the numbers in the list A separated by spaces.
// Output
// One line containing the lenght of the longest increasing subsequence in A.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> list(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && list[i] < list[j] + 1) {
                list[i] = list[j] + 1;
            }
        }
    }

    return *max_element(list.begin(), list.end());
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = longestIncreasingSubsequence(A);
    cout << result << endl;

    return 0;
}
