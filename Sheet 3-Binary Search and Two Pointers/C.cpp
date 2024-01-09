// Ahmed has an array of integers a of size n. Belal has an array of integers b of size m.
// Belal wants to find out, for each integer bj in his array, how many integers in Ahmed's
// array are less than or equal to bj.
// The input consists of a single test case.
// The first line contains two integers n, m (1 ≤ n, m ≤ 2·105).
// The second line contains n integers — the elements of array a ( - 109 ≤ ai ≤ 109).
// The third line contains m integers — the elements of array b ( - 109 ≤ bj ≤ 109).
// Output m space-separated integers: the j-th of which is the number of elements in Ahmed's array 
// that are less than or equal to the value of the j-th element in Belal's array.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int nAhmed,nBelal;
    cin>>nAhmed>>nBelal;
    vector<int> ahmed(nAhmed)  , belal(nBelal);

    for(int i =0 ; i<nAhmed ; i++)
        cin>>ahmed[i];

    for(int i =0 ; i<nBelal ; i++)
        cin>>belal[i];
    sort(ahmed.begin() , ahmed.end());

    for(int i =0 ; i<nBelal ; i++){
       int countLessOrEqual = upper_bound(ahmed.begin(), ahmed.end(), belal[i]) - ahmed.begin();
        cout << countLessOrEqual << " ";

    }
    return 0;    
}
