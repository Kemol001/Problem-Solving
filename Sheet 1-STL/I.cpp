// Andy, 8, has a dream - he wants to produce his
// very own dictionary. This is not an easy task for
// him, as the number of words that he knows is,
// well, not quite enough. Instead of thinking up all
// the words himself, he has a briliant idea. From
// his bookshelf he would pick one of his favourite
// story books, from which he would copy out all
// the distinct words. By arranging the words in
// alphabetical order, he is done! Of course, it is
// a really time-consuming job, and this is where a
// computer program is helpful.
// You are asked to write a program that lists
// all the different words in the input text. In this
// problem, a word is defined as a consecutive sequence of alphabets, in upper and/or lower case.
// Words with only one letter are also to be considered. Furthermore, your program must be CaSe InSeNsItIvE. 
// For example, words like “Apple”, “apple” or “APPLE” must be considered the same.
// The input file is a text with no more than 5000 lines. An input line has at most 200 characters. Input
// is terminated by EOF.
// Your output should give a list of different words that appears in the input text, one in a line. The
// words should all be in lower case, sorted in alphabetical order. You can be sure that he number of
// distinct words in the text does not exceed 5000.

#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int main()
{
    set <string> dictionary;
    string word;
    while(cin>>word){
        if(word.size()==1){
            if((word[0]>=65 && word[0]<=90)||(word[0]>=97 && word[0]<=122)){
                word[0] = tolower(word[0]);
                dictionary.insert(word);
            }
            else
                continue;
        }
        else{
            string lowerWord = "";
            for(int i=0;i<word.size();i++){
                if((word[i]>=65 && word[i]<=90)||(word[i]>=97 && word[i]<=122)){
                    word[i] = tolower(word[i]);
                    lowerWord = lowerWord + word[i];
                }
                else if(i!=0 || i!=word.size()-1){
                    if(lowerWord.size() != 0){
                        dictionary.insert(lowerWord);
                        lowerWord = "";
                        continue;
                    }
                }
                else{
                    word.erase(i,1);
                    i--;
                }
            }
            if(lowerWord.size() != 0)
                dictionary.insert(lowerWord);
        }
    }
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it){
        cout<<*it<<endl;
    }
    return 0;
}