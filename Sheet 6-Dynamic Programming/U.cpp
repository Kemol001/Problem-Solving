#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long dp[101][101][11][11];
long long fmen, hmen, fnum, hnum;
const long long modulo = 1e8;

long long ADD(const long long& a1, const long long& a2){
    return ((a1%modulo) + (a2 % modulo))%modulo;
}

long long solve(long long footmen, long long horsemen, long long footMenNum, long long horseMenNum){

    if(footmen == 0 && horsemen == 0){
        return 1;
    }

    long long& ret = dp[footmen][horsemen][footMenNum][horseMenNum];
    if(~ret)
        return ret;
    long long opt1 = 0, opt2 = 0;
    if(footmen > 0 && footMenNum > 0)
        opt1 = solve(footmen-1, horsemen, footMenNum - 1, hnum);
    if(horsemen > 0 && horseMenNum > 0)
        opt2 = solve(footmen, horsemen-1, fnum, horseMenNum - 1);

    return ret = ADD(opt1, opt2);
}

int main(){
    cin >> fmen >> hmen >> fnum >> hnum;
    memset(dp, -1, sizeof dp);
    cout << solve(fmen,hmen,fnum,hnum);
    return 0;
}