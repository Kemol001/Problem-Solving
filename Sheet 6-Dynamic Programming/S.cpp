#include <iostream>
#include <cstring>

using namespace std;

const int num = 1e5+5;
const int N = 1e9+7;

int dp[num];

string s;
int solve (int curr){
    if(curr >= s.size()-1)
        return 1;

    int& ret = dp[curr];
    
    if(~ ret)
        return ret;

    int opt1 =0 , opt2 = 0;

    if((s[curr] == s[curr+1] && (s[curr] =='u' || s[curr] == 'n'))){
        opt1 = solve(curr+2)%N;
    }
    opt2 = solve(curr+1)%N;

    ret = (opt1 + opt2)%N;

    return ret;
}


int main()
{
    cin>>s;

    memset(dp,-1,sizeof dp);

    if(s.find('w') !=s.npos || s.find('m')!=s.npos)
        cout << 0 << endl;
    else
        cout << solve(0) << endl;

    return 0;
}