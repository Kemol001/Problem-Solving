// Jumping is healthy. But excess of anything is bad. So, You want to jump in a perfect discipline. 
// You become healthy if the absolute values of the difference between every consecutive pair of integers 
// are all numbers from 1 through n-1, where n is the size of the sequence.
// For example,4 2 1 -2 is such a sequence that can make you healthy.
// Because the absolute differences are 2, 1 and 3 respectively. Now can you help yourself to become healthy?
// The input consists of multiple lines, each containing an integer n which does not exceed 3000
// followed by n integers which represent the sequence.
// For each line of input, generate a line of output saying "Jolly" or "Not jolly".

#include <iostream>
#include <sstream>
#include <set>
#include <cstdlib>

using namespace std;

int main()
{
    int size;
    while(cin>>size){
        string line;
        getline(cin,line);
        stringstream ss(line);
        int n;
        if(line.size()==0)
            break;
        int previous;
        ss>>previous;
        bool healthy = false;
        set <int> diffrences;
        int k = 1;
        for(int i=0;i<(size-1);i++){
            diffrences.insert(size-k);
            k++;
        }
        while(--size){
            ss>>n;
            healthy = false;
            int absdiff = abs(n-previous);
            auto x =diffrences.find(absdiff);
            if(x!=diffrences.end()){
                    diffrences.erase(x);
                    previous=n;
                    healthy=true;
            }
            if(!healthy){
                cout<<"Not jolly\n";
                break;
            }
        }   
    if(diffrences.size()==0)
        cout<<"Jolly\n";
    }
    return 0;
}