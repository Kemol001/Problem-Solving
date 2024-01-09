#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[101][50005];
int coins[101];
int num_coins;

int solve(int current_coin, int person_1, int person_2){
    if(current_coin == num_coins)
        return abs(person_1 - person_2);

    int& ret = dp[current_coin][abs(person_1 - person_2)];

    if (~ret)
        return ret;

    ret = min(solve(current_coin + 1, person_1 + coins[current_coin], person_2) , solve(current_coin + 1, person_1, person_2 + coins[current_coin]));

    return ret;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin >> num_coins;
        for(int i = 0; i < num_coins; i++){
            cin >> coins[i];
        }
        cout << solve(0,0,0) << "\n";
    }
    return 0;
}