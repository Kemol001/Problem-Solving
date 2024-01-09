// Given an array of N integers. Let L be the least common multiple of all of the elements in the array.
// Output all of the prime divisors of L in increasing order.
// Input
// First line of the input contains a single integer T, the number of test cases. Then T test cases follow.
// Each test case consists two lines. 
// The first line of each test case consists of a single integer n. 
// The second line contains n space separated integers , a1, a2 ... an. These are the elements of the array.
// Output
// For each test case, print Case #X: D where D is the number of prime divisors of lcm(a1, a2 ... an).
// This should be followed by D lines with the prime divisors in increasing order.
// Constraints
// T <= 100
// 1 <= N <= 100
// 1 <= ai <= 1012

#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> generatePrimes() {
    int N = 1e5;
    vector<bool> sieve(N + 1, true);
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (!sieve[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * 2; j <= N; j += i) {
            sieve[j] = false;
        }
    }
    return primes;
}

int main() {
    vector<int> primeNumbers = generatePrimes();
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int numberNumbers;
        cin >> numberNumbers;
        set<long long> LCMs;

        while (numberNumbers--) {
            long long number;
            cin >> number;
            for (int prime : primeNumbers) {
                if (number == 1)
                    break;
                if (number % prime == 0)
                    LCMs.insert(prime);
                while (number % prime == 0)
                    number /= prime;
            }
            if (number > 1)
                LCMs.insert(number);
        }

        cout << "Case #" << t << ": " << LCMs.size() << endl;
        for (auto lcm : LCMs)
            cout << lcm << endl;
    }

    return 0;
}