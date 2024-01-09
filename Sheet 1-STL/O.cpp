// You are playing a video game. In the current level, you must defeat n enemies. 
// You and each of the enemies have a certain power, which is represented by an integer. 
// The result of a duel between you and a certain enemy is determined by your current power and the enemy's power. Initially, your power is r.
// If you start dueling with the i-th (1 ≤ i ≤ n) enemy and your power is not greater than the enemy's power pi,
// then you lose the duel and die. But if your power is greater than the enemy's power, 
// then you defeat the enemy and your power increases by qi.
// You can fight the enemies in any order. Can you fight the enemies in an order such 
// that you do not lose any duel?
// The first line contains two space-separated integers r and n (1 ≤ r ≤ 104, 1 ≤ n ≤ 103). 
// Then n lines follow: the i-th line contains space-separated integers pi and qi (1 ≤ pi ≤ 104, 0 ≤ qi ≤ 104) 
// — the i-th enemy's power and the bonus for defeating it.
// On a single line print "YES", if you can fight the enemies in such a way that you lose no duel and print "NO" otherwise.

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int myPower,numEnemies;
    cin>>myPower>>numEnemies;
    multimap <int,int> enemies;
    while(numEnemies--){
        int enemyPower,Bonus;
        cin>>enemyPower>>Bonus;
        enemies.insert( pair<int,int> (enemyPower,Bonus));
    }
    while(enemies.size() != 0){
        if(myPower > enemies.begin()->first){
            myPower = myPower + enemies.begin()->second;
            enemies.erase(enemies.begin());
        }
        else{
            break;
        }
    }
    if(enemies.size() == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;  
}