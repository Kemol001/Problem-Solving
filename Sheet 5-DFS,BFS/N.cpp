// We have a string, denoted as 's', consisting of two characters, 'a' and 'b'. A group is defined as a maximal
// consecutive substring containing the same character. Any group g in s, with a length of at least two,
// can be removed, resulting in a new string formed by concatenating the remaining left and right substrings of 's.
// This process is repeated until the string either becomes empty or no more groups of length at least two exist.
// For instance, consider the string 's = babbbaaabb', which contains groups 'b', 'a', 'bbb', 'aaa', and 'bb'.. The
// string 's' can be transformed into the empty string by removing the groups in the following sequence:
// babbbaaabb→ baaaabb → bbb → empty string
// but this way won't lead to an empty string
// babbbaaabb→ babbbaaa→ baaaa →b
// You have to write a program that determines whether a given string can be converted into an empty string
// through some sequence of removing operations.
// Input
// The first line contains a single integer T - The number of test cases.
// Each test case, Given a string s consisting of 'a's and 'b's only (1 <= |s| <= 25) - |s| denotes the length
//  of the string s.
// Output
// For each test case, print '1' the string s can be turned into an empty string by using the operation otherwise 
// print '0'.

#include <iostream>
#include <vector>

using namespace std;

int dfs(string AB,vector<string>& groups){
    bool flag = false;
    if(AB.size()==0){
        return 1;
    }
    string curr;
    char cur;
    for(int i=0 ; i<AB.size() ; i++){
        if(i == 0){
            cur = AB[i];
            curr += AB[i];
            continue;
        }
        else if(AB[i] != cur){
            groups.push_back(curr);
            cur = AB[i];
            curr.clear();
            curr += AB[i];
            continue;
        }
        curr += AB[i];
    }
    groups.push_back(curr);

    vector <string> test = groups;
    for (int i=0;i<groups.size();i++){
        if(groups[i].size()>1){
            auto it = groups.begin()+i;
            groups.erase(it);
            AB.clear();
            for (int i=0;i<groups.size();i++)
                AB += groups[i];

            groups.clear();
            int ans = dfs(AB,groups);
            if(ans == 0){
                groups = test;
                continue;
            }
            else if(ans == 1){
                return 1;
            }
            flag = true;
        } 
    }
    if(!flag)
        return 0;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        vector<string> groups;
        cout<<dfs(s,groups)<<endl;
    }
    return 0;
}