// There are n houses and m signal stations on a line. The houses and the stations can be represented 
// as points on an x-axis.
// The stations provide network connection for the houses. A station can provide network connection for a house if 
// the distance between the station and the house does not exceed r. All stations have the same signal strength.
// Given the positions of the houses and the signal stations along the x-axis, find the minimum r such that 
// all of the houses are covered by some signal station.
// The input consists of a single test case.
// The first line contains two positive integers n and m (1 ≤ n, m ≤ 105) — 
// the number of houses and the number of signal stations.
// The second line contains a sequence of n integers a1, a2, ..., an ( - 109 ≤ ai ≤ 109) — 
// the coordinates of houses. There may be multiple houses at the same point. All coordinates ai are given 
// in non-decreasing order.
// The third line contains a sequence of m integers b1, b2, ..., bm ( - 109 ≤ bj ≤ 109) — 
// the coordinates of signal stations. There may be multiple signal stations at the same point. 
// All coordinates bj are given in non-decreasing order.
// Output the minimum r so that each house will be covered by at least one signal station.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long nHouses,nStations,signal = 0;
    cin>>nHouses>>nStations;
  
    long long houses[nHouses], stations[nStations];
    
    for(long long i =0 ; i<nHouses ; i++)
        cin>>houses[i];
    
    for(long long i =0 ; i<nStations ; i++)
        cin>>stations[i];
    for(long long i =0 ; i<nHouses ; i++){
        long long left = 0, right = nStations-1 ,  mid = left + (right - left)/2;
        
        while((right - left)>1){
            
            mid = left + (right - left)/2;
            
            if(houses[i] < stations[mid])
                right = mid;
            else 
                left = mid;          
        }
        if (houses[i] > stations[mid])
            mid++;

        long long strength = abs(houses[i]-stations[mid]);
        
        if(mid != 0 && strength > abs(houses[i]-stations[mid-1]))
            strength = abs(houses[i]-stations[mid-1]);

        if(signal < strength)
            signal = strength;
    
    }
    
    cout<<signal<<endl;
    return 0;
}