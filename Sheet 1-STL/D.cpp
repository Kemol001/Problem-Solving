// Eve and Alex had an argument about the price and quality of laptops. Eve thinks that the more expensive a 
// laptop is, the better it is. But Alex does not agree with Eve. He thinks that there are two laptops,
// such that the price of the first laptop is less (strictly smaller) than the price of the second laptop but
// the quality of the first laptop is higher (strictly greater) than the quality of the second laptop.
// Please, check the guess of Alex. You are given descriptions of L laptops.
// Determine whether two described above laptops exist.
// The first line contains an integer L (1 ≤ L ≤ 105) — the number of laptops.
// Next L lines contain two integers each, pi and qi (1 ≤ pi, qi ≤ n),
// where pi denotes the price of the i-th laptop, and qi represents the quality of 
// the i-th laptop (the larger the number is, the higher is the quality).
// Note that, all pi are distinct. Also, all qi are distinct.
// You have to output a single line. Output "Poor Alex" if Alex's guess is wrong, but if he is right, 
// output "Happy Alex".

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int size,price,quality;
    cin>>size;
    map<int,int,greater <int>> Laptops;
    while(size--){
        cin>>price>>quality;
        Laptops[price]=quality;
    }
    int lowestPriceQuality = Laptops.begin()->second;
    for(auto counter:Laptops){
        if(lowestPriceQuality < counter.second ){
            cout<<"Happy Alex\n";
            return 0;
        }
        else if(lowestPriceQuality > counter.second){
            lowestPriceQuality = counter.second;
        }
    }
    cout<<"Poor Alex\n";
    return 0;
}