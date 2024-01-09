// As you may know, there are currently two main sets of measurement units in the world:
// the metric system and the imperial system. The imperial system receives its name from the British empire,
// which was the place of its invention and its main user until recently. Nowadays, Britain’s heir,
// the United States of America, is the only country where a variation of the imperial system is the official
// measurement system.
// For a particular magnitude, in a given measurement system there are N different units U1, U2, ... UN
// (the number of units depends on both the magnitude and the system). For every i (1 ≤ i ≤ N − 1),
// a certain number of Ui is equivalent to a certain number of Ui+1. In the metric system we always have that
// 1Ui is equivalent to 10Ui+1. For instance, 1 decimeter is equivalent to 10 centimeters, 1 gram is equivalent
// to 10 decigrams, and 1 decaliter is equivalent to 10 liters. On the contrary, in some variations of the
// imperial system we may have other positive integers instead of 1 and 10. For instance, 32 drams are equivalent
// to 875 grains.
// Since you were born and raised using the much more sensible metric system, you need help learning the imperial
// system and its variations. You want to be able to transform directly from U1 to UN, that is, 
// you need to know that a certain number of U1 is equivalent to a certain number of UN.
// To ease further calculations, you want to express the equivalence using only integers values,
// and these values must be as small as possible.
// Input
// Each test case is described using several lines.
// The first line contains an integer N indicating the number of units in the measurement system (2 ≤ N ≤ 10).
// Line i of the next N − 1 lines describes the relationship between units Ui and Ui+1 with two integers Ai and Bi
// representing that Ai Ui is equivalent to Bi Ui+1 (1 ≤ Ai < Bi ≤ 100). The end of input is indicated with a line
// containing a single −1.
// Output
// For each test case, output a single line with two positive integers C and D representing that CU1 is
// equivalent to DUN. If there are several alternatives, choose the minimum possible value for C.

#include <iostream>
using namespace std;

long long GCD(long long a, long long b)
{
    if(a%b == 0)
        return b;

    return GCD(b,a%b);
}
int main() {
    long long number;
    while (true)
    {
        cin >>number;
        if (number == -1)
            break;

        long long a =1;
        long long b =1;
        for(int i=0; i < number-1;i++)
        {
            long long x1,x2;
            cin >> x1 >> x2;
            a *= x1;
            b *= x2;
        }
        long long g = GCD(a,b);
        cout << a/g << " " << b/g << "\n";
    }
    return 0;
}