// You own a website, some users on the website want to change their usernames. 
// For a user to change their username, they must provide their old username and their new username.
// The new username must not have been used by anyone at any point up to the username change request.
// Given a list of username change requests, output the initial and final usernames of all users who
// requested username changes.
// The first line contains integer n (1 ≤ n ≤ 1000), the number of username change requests.
// The following n lines will contain the descriptions of the requests.
// Each request consists of two strings s and t, separated by a space.The strings may have lowercase 
// and uppercase letters and digits. The two strings of each requests are not the same. 
// The length of both strings does not exceed 20.
// The requests are given chronologically. So, it is guaranteed that by the moment of a query 
// there is a single person with username s, and handle t is not used and has not been 
// used by anyone.
// Output the integer l — the number of users that changed their handles at least once.
// In the next l lines print the mapping between the old and the new usernames of the users. 
// You may output lines in any order.
// Each user who changes the username must occur exactly once in this description.

#include <iostream>
#include <map>

using namespace std;

int main()
{   
    int nRequests;
    cin>>nRequests;
    map <string , string> usernames;
    while(nRequests--){
        string oldUsername,newUsername;
        cin>>oldUsername>>newUsername;
        bool newname = true;
        for(auto i : usernames){
            if(oldUsername == i.second){
                string dummy = i.first;
                usernames.erase(i.first);
                usernames[dummy] = newUsername;
                newname =false;
                break;
            }
        }
        if(newname){
            usernames[oldUsername] = newUsername;
        }
    }
    cout<<usernames.size()<<endl;
    for(auto i : usernames){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}