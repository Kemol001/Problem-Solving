// You will be given an integer N, count the number of 1s present in the numbers from 1 to N inclusive if
// they are written in binary.
// For example, if N=4, the numbers from 1 to 4 in binary are: 1, 10, 11, 100. So, there are 5 ones.
// Input
// First line contains, T, the number of test cases. Each test case consists of one integer per line denoting N.
// Output
// Print the required answer.
// Constraints
// 1 ≤ T ≤ 1000
// 1 ≤ N ≤ 1000

#include <iostream>

using namespace std;

int countOnes(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num > 0) {
            if (num % 2 == 1) {
                ++count;
            }
            num /= 2;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << countOnes(N) << endl;
    }

    return 0;
}
