// We say that x is a perfect square if, for some integer b, x = b^2
// Similarly, x is a perfect cube if, for some integer b, x = b^3
// More generally, x is a perfect pth power if, for some integer b, x = b^p
// Given an integer x you are to determine the largest
// p such that x is a perfect pth power.
// Input
// Each test case is given by a line of input containing x. The
// value of x will have magnitude at least 2 and be within the
// range of a (32-bit) int in C, C++, and Java. A line containing
// ‘0’ follows the last test case.
// Output
// For each test case, output a line giving the largest integer p
// such that x is a perfect pth power.

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long long number;
    while (true)
    {
        cin >> number;
        if (number == 0)
        {
            break;
        }

        for (long long i = 31 ; i>=1 ; i--)
        {
            long long x = round(pow (abs(number), 1.0 / i));
            if (pow(x,i) == abs(number) && !(i%2 == 0  && number < 0))
            {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}