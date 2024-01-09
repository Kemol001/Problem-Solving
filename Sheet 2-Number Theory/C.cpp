// You will be given an odd integer x which is greater than 2.
// Find the smallest integer p such that p is a prime number and p is a divisor of x.
// Constraints
// 2 <= x <= 100000000
// Input
// The input consists of multiple test cases.
// Each test case consists of a single integer on a line on its own.
// The last test case will contain the integer 0. This test case should not be processed.
// Output
// For each test case, output the answer for this test case on a single line.

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int smallestPrimeDivisor(int x) {
    for (int p = 3; p <= sqrt(x); p += 2) {
        if (x % p == 0 && isPrime(p)) {
            return p;
        }
    }
    return x;  
}

int main() {
    int x;

    while (true) {
        cin >> x;

        if (x == 0) {
            break;
        }

        int result = smallestPrimeDivisor(x);
        cout << result << endl;
    }

    return 0;
}
