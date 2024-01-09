#include <iostream>
#include<algorithm>
using namespace std;
int arr[5];

bool find23(int index, long long sum){
    if(index == 5)
        return sum == 23;
    
    return find23(index + 1, sum + arr[index]) || find23(index + 1, sum - arr[index]) || find23(index + 1, sum * arr[index]);
}

int main()
{
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4], arr[0] != 0){
        sort(arr, arr + 5);
        bool res = false;
        do{  
            res = find23(1, arr[0]);
            if(res)
                break;
        }while(next_permutation(arr, arr + 5));
        
        if(res)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}