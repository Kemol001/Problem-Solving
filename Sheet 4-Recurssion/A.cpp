#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits.h>

using namespace std;

void solve(int capacity,vector<int>&capacityJewels,vector<int>&solutions,vector<int>&bestSolution,int least,int n){
    if(solutions.size() != 0){
        int sum = accumulate(solutions.begin(),solutions.end(),0);
        if(sum + least > capacity || capacityJewels.size() == 0){
            int sum2 = accumulate(bestSolution.begin(),bestSolution.end(),0);
            if(sum > sum2 && sum <= capacity)
                bestSolution = solutions;
            return;
        }
        if(capacityJewels.size() == 1 && sum + least <= capacity){
            solutions.push_back(capacityJewels[0]);
            bestSolution = solutions;
            return;
        }
    }

    vector<int> test = capacityJewels;
    for(int i = 0;i < capacityJewels.size();i++){
        solutions.push_back(capacityJewels[i]);
        auto it = capacityJewels.begin()+i;
        capacityJewels.erase(it);
        vector<int> test2 = capacityJewels;
        sort(test2.begin(),test2.end());
        if(test2.size() == 0)
            solve(capacity,capacityJewels,solutions,bestSolution,least,n);
        else
            solve(capacity,capacityJewels,solutions,bestSolution,test2[0],n);
        if(bestSolution.size() == n)
            return;
        capacityJewels = test;
        solutions.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int capacity,numberofJewels;

    while(cin>>capacity>>numberofJewels){
        vector<int>capacityJewels,solutions,bestSolution,sorted;
        for(int i=0;i < numberofJewels;i++){
            int jewel;
            cin>>jewel;
            capacityJewels.push_back(jewel);
        }
        sorted = capacityJewels;
        sort(sorted.begin(),sorted.end());
        solve(capacity,capacityJewels,solutions,bestSolution,sorted[0],numberofJewels);
        int sum = 0;
        for(auto it : bestSolution){
            sum += it;
            cout<<it<<" ";
        }
        cout<<"sum:"<<sum<<endl;
    }
    return 0;
}