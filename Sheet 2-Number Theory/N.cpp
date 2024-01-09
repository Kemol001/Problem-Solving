// Some positive integers can be represented by a sum of one or more consecutive prime numbers. How
// many such representations does a given positive integer have? For example, the integer 53 has two
// representations 5+7+11+13+17 and 53. The integer 41 has three representations 2+3+5+7+11+13,
// 11 + 13 + 17, and 41. The integer 3 has only one representation, which is 3. The integer 20 has no
// such representations. Note that summands must be consecutive prime numbers, so neither 7 + 13 nor
// 3 + 5 + 5 + 7 is a valid representation for the integer 20. Your mission is to write a program that reports
// the number of representations for the given positive integer.
// Input
// The input is a sequence of positive integers each in a separate line. The integers are between 2 and
// 10000, inclusive. The end of the input is indicated by a zero.
// Output
// The output should be composed of lines each corresponding to an input line except the last zero. An
// output line includes the number of representations for the input integer as the sum of one or more
// consecutive prime numbers. No other characters should be inserted in the output.

#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveToNumber(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int number = 2; number * number <= limit; ++number) {
        if (isPrime[number]) {
            for (int multiple = number * number; multiple <= limit; multiple += number) {
                isPrime[multiple] = false;
            }
        }
    }

    vector<int> primesList;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primesList.push_back(i);
        }
    }

    return primesList;
}

int countReperesentaions(int target, const vector<int>& primes) {
    int count = 0;
    for (int i = 0; i < primes.size(); ++i) {
        int sum = 0;
        for (int j = i; j < primes.size(); ++j) {
            sum += primes[j];
            if (sum == target) {
                ++count;
                break;
            } 
            else if (sum > target) {
                break;
            }
        }
    }
    return count;
}

int main() {
    vector<int> primeList = sieveToNumber(10000);
    int number;
    while (true) {
        cin >> number;
        if (number == 0) {
            break;
        }
        int representations = countReperesentaions(number, primeList);
        cout << representations << endl;
    }
    return 0;
}