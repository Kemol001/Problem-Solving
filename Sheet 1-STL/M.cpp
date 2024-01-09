// Given a set of lowercase English letters, count the number of distinct elements in the set.
// The first and only line contains the set, beginning with an opening curved bracket, 
// followed by the elements of the set separated by commas then a closing curved bracket. 
// The number of elements in the set does not exceed 1000.
// Output the number of distinct letters in the set.
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <char> letters;
    char letter;
    while(cin>>letter){
        if((letter>=97 && letter<=122)){
            letters.insert(letter);
        }
    }
    cout<<letters.size()<<endl;
    return 0;
}