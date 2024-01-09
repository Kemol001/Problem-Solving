// There are n customers waiting to be serviced in the queue of a certain shop.
// We know that the ith customer needs time ti to be serviced.
// A customer is angry if the time he spends waiting in the queue is more than the
// time needed to serve him. A customer waits in the queue for a time equal to the sum of servicing
// times of the customers in front of him in the queue. You can swap people in the queue.
// What is the maximum number of non angry customers that can be achieved by swapping people 
// in the queue.
// The first line contains integer n (1 ≤ n ≤ 105).
// The next line contains n integers ti (1 ≤ ti ≤ 109), separated by spaces.
// Print a single number — the maximum number of not angry people in the queue.

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int size,happy = 0;
    cin>>size;
    int waitingtime = 0;
    multiset <int> wqueue;
    while(size--){
        int time;
        cin>>time;
        wqueue.insert(time);
    }
    for(auto i: wqueue){
        if(i >= waitingtime){
            happy++;
            waitingtime = waitingtime + i;
        }      
    }
    cout<<happy<<endl;
    return 0;
}