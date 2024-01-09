#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a[200009];
    long long n,m,k,s;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        a[i]=abs(a[i]);
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(long long i=1;i<n;i++){
        long long lb=lower_bound(a+1, a+n+1, 2*a[i]+1)-a;
        if(lb==n+1){
            lb--;
        }
        while(a[lb]>2*a[i]){
            lb--;
        }
        ans+=lb-i;
    }
    cout<<ans;
    return 0;
}