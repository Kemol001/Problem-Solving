// Given is an ordered deck of n cards numbered 1
// to n with card 1 at the top and card n at the
// bottom. The following operation is performed as
// long as there are at least two cards in the deck:
// Throw away the top card and move
// the card that is now on the top of the
// deck to the bottom of the deck.
// Your task is to find the sequence of discarded
// cards and the last, remaining card.
// Each line of input (except the last) contains a
// number n ≤ 50. The last line contains ‘0’ and
// this line should not be processed
// For each number from the input produce two
// lines of output. The first line presents the sequence of discarded cards, the second line reports 
// the last remaining card. No line will have
// leading or trailing spaces.

#include <iostream>
#include <list>

using namespace std;

int main()
{
    int num;
    while(cin>>num && num!=0){
        if(num == 1){
          cout<<"Discarded cards:\n";
          cout<<"Remaining card: "<<1<<"\n";
          continue;
        }
        list<int>deck;
        for(int i=1;i<=num;i++){
            deck.push_back(i);
        }
        list<int>discarded;
        while(deck.size() != 1){
            int n = deck.front();
            discarded.push_back(n);
            deck.pop_front();
            deck.push_back(deck.front());
            deck.pop_front();
        }
        int last = discarded.back();
        discarded.pop_back();
        cout<<"Discarded cards: ";
        for(auto i = discarded.begin();i != discarded.end();i++){
            cout<<*i<<", ";
        }
        cout<<last;
        cout<<"\n"<<"Remaining card: "<<deck.front()<<"\n";
    }
    return 0;
}