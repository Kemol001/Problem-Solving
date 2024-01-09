#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int numberItems;
    long long amountSpecial;
    cin >> numberItems >> amountSpecial;

    long long amountNeeded[numberItems];
    long long amountItem[numberItems];

    for (int i = 0; i < numberItems; i++)
        cin >> amountNeeded[i];

    for (int i = 0; i < numberItems; i++)
        cin >> amountItem[i];

    if (numberItems == 1) {
        long long ans = (amountItem[0] + amountSpecial) / amountNeeded[0];
        cout << ans;
        return 0;
    }

    multimap<int, long long> limiters;
    for (int i = 0; i < numberItems; i++)
        limiters.insert(pair<long long, int>(floor(amountItem[i] / amountNeeded[i]), i));

    while (amountSpecial > 0) {
        int target = limiters.begin()->second;
        int newtarget = (limiters.begin()++)->first;

        if(newtarget == limiters.begin()->first)
            newtarget++;
        long long diff = (amountNeeded[target] * newtarget) - amountItem[target];

        if ((amountSpecial - diff) >= 0) {
            amountSpecial -= diff;
            amountItem[target] += diff;
            limiters.erase(limiters.begin());
            limiters.insert(pair<long long, int>(floor(amountItem[target] / amountNeeded[target]), target));
        } 
        else{
            amountSpecial -= amountSpecial;
            amountItem[target] += amountSpecial;
            limiters.erase(limiters.begin());
            limiters.insert(pair<long long, int>(floor(amountItem[target] / amountNeeded[target]), target));
            break;
        }
    }

    long long ans = limiters.begin()->first;
    cout << ans;
    return 0;
}