// There is a game called "I Wanna Be the Guy", consisting of n levels. 
// Little X and his friend Little Y are addicted to the game. Each of them wants to pass the whole game.
// Little X can pass only p levels of the game. And Little Y can pass only q levels of the game. 
// You are given the indices of levels Little X can pass and the indices of levels Little Y can pass. 
// Will Little X and Little Y pass the whole game, if they cooperate each other?
// The first line contains a single integer n (1 ≤  n ≤ 100).
// The next line contains an integer p (0 ≤ p ≤ n) at first, 
// then follows p distinct integers a1, a2, ..., ap (1 ≤ ai ≤ n).
// These integers denote the indices of levels Little X can pass. 
// The next line contains the levels Little Y can pass in the same format. 
// It's assumed that levels are numbered from 1 to n.
// If they can pass all the levels, print "I become the guy.".
// If it's impossible, print "Oh, my keyboard!" (without the quotes).

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int level;
    cin>>level;
    set<int> levels;
    for(int i =1; i<=level ;i++){
        levels.insert(i);
    }
    int xlevels,ylevels;
    cin>>xlevels;
    while(xlevels--){
        int num;
        cin>>num;
        if(levels.find(num) != levels.end()){
            levels.erase(num);
        }
    }
    cin>>ylevels;
    while(ylevels--){
        int num;
        cin>>num;
        if(levels.find(num) != levels.end()){
            levels.erase(num);
        }
    }
    if(levels.size() == 0){
        cout<<"I become the guy.\n";
    }
    else
        cout<<"Oh, my keyboard!\n";

    return 0;
}