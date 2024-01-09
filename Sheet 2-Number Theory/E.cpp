// Let us say that two integers x and y are friends if there is a digit that they both have in their decimal
// representation.For example, 15 and 81 are friends, but 76 and 12 are not.
// You are given an array of N integers. Count the number of pairs of elements in the array that are friends.
// Input
// The first line contains a single integer N, which is the length of the array. 1 <= N <= 5*10^5.
// The second line contains N integers which represent the elements of the array. 
// All numbers in the array are distinct. All numbers are positive integers less that 10^18.
// Output
// Output a single integer on a line, the number of pairs of elements in the array that are friends.

#include <cstdio>
using namespace std;

int main()
{
    int testCases;
    scanf("%d", &testCases);
    char number[20] ;
    int frequency[1<<10] = {0};
    long long solution = 0;
    for (int testCase = 0; testCase < testCases; testCase++)
    {
        scanf("%s", number);
        int mask = 0;
        for (int i = 0; number[i] != '\0'; ++i)
        {
            mask |= 1<<(number[i] - '0');
        }
        solution += frequency[mask];
        ++frequency[mask];
    }
    for (int i = 0; i < 1<<10; ++i)
    {
        for (int j = i + 1; j < 1<<10; ++j)
        {
            if(i & j)
            {
                solution += (long long)frequency[i] * frequency[j];
            }
        }
    }
    printf("%lld\n" , solution);
}