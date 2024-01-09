#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }

    return true;
}

int getNextPrime(int current) {
    do {
        current++;
    } while (!isPrime(current));

    return current;
}

int getPreviousPrime(int current) {
    do {
        current--;
    } while (!isPrime(current));

    return current;
}

int primeGap(int number) {
    if (isPrime(number)) return 0;

    int lowerPrime = getPreviousPrime(number);
    int upperPrime = getNextPrime(number);

    return upperPrime - lowerPrime;
}

int main() {
    while (true) {
        int number;
        cin >> number;

        if (number == 0) break;

        int gap = primeGap(number);
        cout << gap << endl;
    }

    return 0;
}