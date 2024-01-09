#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    int n = 30;
    vector <pair<int,int>> factors;
    for(int i=2 ;i*i <= n; i++){
        int power = 0;
        while (n % i == 0){
            power++;
            n/=i;
        }
        if(power > 0)
            factors.emplace_back(i ,power);
    }
    if(n != 1){
        factors.emplace_back(n,1);
    }
    return 0;
}
