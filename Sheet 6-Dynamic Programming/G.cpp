#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int test = 1e3+5;


int dp[100][test];
int weight[100], value[100];

int solve(int bag,int remainingWeight) {
    if (bag <= 0 || remainingWeight <= 0)
        return 0;
    
    int& ret = dp[bag][remainingWeight];

    if (~ ret)
        return ret;

    int take = 0;
    if (weight[bag] <= remainingWeight) {
        take = value[bag] + solve(bag - 1, remainingWeight - weight[bag]);
    }

    int leave = solve(bag - 1, remainingWeight);
    dp[bag][remainingWeight] = max(take, leave);

    return dp[bag][remainingWeight];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int maxWeight, nBags;
        cin >> maxWeight >> nBags;

        for (int i = 1; i <= nBags; i++) {
            cin >> weight[i] >> value[i];
        }

        memset(dp,-1,sizeof dp);

        cout << "Hey stupid robber, you can get " << solve(nBags,maxWeight) << "." << endl;
    }

    return 0;
}