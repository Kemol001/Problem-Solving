// In motorsports it is very common that the leader pilot in a race, at a certain moment, overtakes the
// last pilot. The leader, at this moment, is one lap ahead of the last pilot, who then becomes a straggler.
// In this task, given the time it takes for the fastest pilot, and for the slowest pilot, to complete one lap,
// you have to determine in which lap the slowest pilot will become a straggler. You should consider that,
// at the beginning, they are side by side at the start line of the circuit, both at the start of lap number 1
// (the first lap of the race); and that a new lap always begins right after the leader crosses the start line.
// The input contains several test cases. Each test case consists of one line with two integers X and
// Y (1 ≤ X < Y ≤ 10000), the times, in seconds, that it takes for the fastest and the slowest pilot,
// respectively, to complete one lap.
// For each test case in the input program should output line, containing one integer: the lap in which
// the slowest pilot will become a straggler.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double racer1,racer2;
    int lap;

    while(cin>>racer1>>racer2){
        lap = ceil(racer2/(racer2-racer1));
        cout<<lap<<endl;
    }
    return 0;
}