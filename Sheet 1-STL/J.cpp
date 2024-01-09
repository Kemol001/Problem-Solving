// The first line of input contains 2 positive integers: m ≤ 1000, the number of words in the Hay Point
// dictionary, and n ≤ 100, the number of job descriptions. m lines follow; each contains a word (a string
// of up to 16 lower-case letters) and a dollar value (a real number between 0 and 1,000,000). Following
// the dictionary are the n job descriptions. Each job description consists of one or more lines of text; for
// your convenience the text has been converted to lower case and has no characters other than letters,
// numbers, and spaces. Each job description is terminated by a line containing a period
// For each job description, output the corresponding salary computed as the sum of the Hay Point values
// for all words that appear in the description. Words that do not appear in the dictionary have a value
// of ‘0’.

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int numberWords,numberDescriptions;
    cin>>numberWords>>numberDescriptions;
    map <string , int> vals;
    while(numberWords--){
        string word;
        int value;
        cin>>word>>value;
        vals[word]=value;
    }
    while(numberDescriptions--){
        int salary = 0;
        string jobDescription;
        while(cin>>jobDescription && jobDescription != "."){
            if(vals.find(jobDescription) != vals.end()){
                salary = salary + vals[jobDescription];
            }
            else
                continue;
        }
        cout<<salary<<endl;
    }
    return 0;
}