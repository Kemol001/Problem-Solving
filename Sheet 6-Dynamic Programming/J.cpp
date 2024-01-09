#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int prices[4500],favs[10];
int dp[4500][10];
int pocketMoney,nItems;

int solve(int curr,int pocketMoney){

    if(abs(pocketMoney-prices[curr]) > 200)
        return 0;
    
    int& ret = dp[curr][pocketMoney];

    if(~ ret)
        return ret;

    int take = 0;

    if(abs(pocketMoney-prices[curr]) < 200)
        take = favs[curr] + solve(curr+1,pocketMoney-prices[curr]);

    int leave = solve(curr +1,pocketMoney);
    
    ret = max(take,leave);

    return ret;
}

int main()
{
    while(true){
        cin>>pocketMoney>>nItems;
        for(int i = 1;i <= nItems;i++){
            cin>>prices[i]>>favs[i]; 
        }
        memset(dp,-1,sizeof dp);
        cout<<solve(1,pocketMoney)<<endl;
    }
}