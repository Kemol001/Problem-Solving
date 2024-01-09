// The first line is the number of test cases, followed by a blank line.
// Each test case of your program consists of a list of the species of every tree observed by the satellite;
// one tree per line. No species name exceeds 30 characters. There are no more than 10,000 species and
// no more than 1,000,000 trees.
// There is a blank line between each consecutive test cases.
// For each test case print the name of each species represented in the population, in alphabetical order,
// followed by the percentage of the population it represents, to 4 decimal places.
// Print a blank line between 2 consecutive test cases.

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    string ssize;
    getline(cin,ssize);
    int size = stoi(ssize);
    string test;
    getline(cin,test);
    while(size--){
        map <string,float> trees;
        string tree;
        float population =0.00;
        while(getline(cin,tree) && tree.size() > 0){
            if(trees.find(tree) == trees.end()){
                trees[tree]=1.00;
                population++;
            }
            else{
                trees[tree] = trees[tree] + 1.00;
                population++;
            }
        }
        for(auto i : trees){
            float ratio = i.second / population;
            float percentage = ratio * 100;
            cout<<i.first<<" "<<fixed<<setprecision(4)<<percentage<<endl;
        }
        if(size>0)
            cout<<"\n";
    }
    return 0;
}