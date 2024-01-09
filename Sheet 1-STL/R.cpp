// Given an array a of length n. Count the number of unordered pairs of elements of the array whose 
// sum is a power of 2.
// The first line contains the single positive integer n (1 ≤ n ≤ 105) — the number of integers.
// The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).
// Print the number of unordered pairs of elements whose sum is a power of 2.

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int size;
    long long counter=0;
    cin>>size;
    map <int,int> numbers;
    while(size--){
        int number;
        cin>>number;
        for(int i=0;i <=31;i++){
            int target = pow(2,i) - number;
            if(numbers.find(target) != numbers.end()){
                counter = counter + numbers[target];
            }
        }
        numbers[number]++;
    }
    cout<<counter<<endl;
    return 0;
}