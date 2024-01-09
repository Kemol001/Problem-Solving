// Given an array of integers of size N ( 1<=N<=105 ). You are asked to perform 2 types of queries :
// (i) Query 1 : 1 l r
// Given 2 integers l and r. ( 1 <= l <= r <= the current size of the array ). 
// Print the sum of all the elements with indices between l and r inclusive.
// (ii) Query 2 : 2 p
// Given a single integer p ( |p| <= 109 ). Add this element to the beginning of the array.
// Notice that this operation changes the indices of all other elements of the array. All of the indices are 
// increased by 1 and the newly added element has index 1. Also, the size of the array is increased by 1.
// Input
// The first line contains a single integer N ( 1 <= N <= 105 ), the number of elements initially in the array.
// The second line contains N space separated integers, a1 a2 .... aN. ( |ai| <= 109 )
// The next line contains a single integer Q, the number of operations you will be asked to perform. 
// ( 1 <= Q <= 105 )
// The following Q lines each contain a single query. Each such line starts with either the number 1 or the
// number 2. This indicates the type of operation that you are required to perform. 
// The format of these queries are as described above.
// Output
// For each query of type 1, output the answer for this query on a new line. 
// No output needs to be printed for queries of type 2.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int size;
    cin >> size;
    long long arr[size];
    vector<long long> prefixSum(size);

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    prefixSum[0] = arr[size - 1];
    for (int i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[size - i - 1];
    }

    int operations;
    cin >> operations;
    long long result;

    for (int i =0 ; i < operations; i++) {
        int operationNumber;
        cin >> operationNumber;

        if (operationNumber == 1) {
            int start, finish;
            cin >> start >> finish;

            if (start == 1) {
                if (finish == prefixSum.size()) {
                    cout << prefixSum[prefixSum.size() - 1] << '\n';
                } else {
                    cout << prefixSum[prefixSum.size() - 1] - prefixSum[prefixSum.size() - finish - 1] << endl;
                }
            } else {
                if (finish == prefixSum.size()) {
                    cout << prefixSum[prefixSum.size() - start] << "\n";
                } else {
                    cout << prefixSum[prefixSum.size() - start] - prefixSum[prefixSum.size() - finish - 1] << endl;
                }
            }
        } else {
            long long numberToAdd;
            cin >> numberToAdd;
            long long number = prefixSum[prefixSum.size() - 1] + numberToAdd;
            prefixSum.push_back(number);
        }
    }

    return 0;
}