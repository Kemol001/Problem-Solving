// Rafi and his girlfriend go to the mall. They get in to a stall. Rafi thinks that if he buys her the cheapest 
// product, it will disgrace him. But, he does not have enough money at this moment to buy the expensive products.
// So, he decides to buy the product with the second lowest price. He also decides that the price of the product 
// should be strictly greater than the lowest one. If no such product exist, they will leave the shop,
// telling the shop owner ‘NO’. Help Rafi choose the product.
// The input consists of two lines. The first of which contains a single integer n (1 ≤ n ≤ 100) which denotes 
// the number of products. The second line contains n space-separated integers which denote the prices of the
// products. These may be negative but their absolute value is less that or equal to 100.
// If the given pricelist has a product with the second lowest price, output this price, otherwise output NO

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    int size;
    cin>>size;
    string prices;
    getc(stdin);
    getline(cin,prices);
    if(prices.size()==0)
        return 0;
    if(size==1){
        cout<<"NO";
        return 0;
    }
    stringstream ss(prices);
    int Prices[size];
    int x;
    int j=0;
    while(ss>>x){
        Prices[j]=x;
        j++;
    }
    int minN = 10000;
    for(int i=0;i<size;i++){
        minN=min(minN,Prices[i]);
    }
    int minN2 = 10000;
    for(int i=0;i<size;i++){
        if(Prices[i]!=minN)
            minN2=min(minN2,Prices[i]);
    }
    if(minN2 > minN && minN2 != 10000)
        cout<<minN2;
    else
        cout<<"NO";    
    return 0;
}