// You are a mathematician who has been fascinated with palindromic numbers since childhood. 
// One day, while working on a research project, you come across a new type of number called the Palindrome
// Extension number. Intrigued, you decide to investigate further.
// After some research, you discover that a Palindrome Extension number is a number that can be transformed
// into a palindrome by adding some leading zeros (possibly none).
// You begin to wonder how many numbers around you are Palindrome Extension.
// For example, numbers 131 and 2010200 are Palindrome Extension numbers,
// they can be transformed to strings "131" and "002010200", respectively, which are palindromes.
// One day, while walking to your office, you come across a poster for a math competition.
// The competition is based on palindromic and Palindrome Extension numbers. Excited by the opportunity,you decide to participate.
// During the competition, You are given some integer number n. Check if it's a Palindrome Extension number.
//The only line contains an integer n (1 ≤ n ≤ 10^9). This number does not begin with a zero.
//Print "YES" if number n is Palindrome Extension number. Otherwise, print "NO" (without quotes).

#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number;
    while(cin>>number){
        string palindrome = to_string(number);
        string revPalindrome = palindrome;
        reverse(revPalindrome.begin(), revPalindrome.end());
        if(palindrome == revPalindrome){
            cout<<"YES\n";
            return 0;
        }
        else{
            stringstream ss(revPalindrome);
            char testChar;
            int zeroCounter = 0;
            while(ss>>testChar){
                if(testChar == '0'){
                    zeroCounter++;
                    continue;
                }
                else
                    break;
            }
            while(zeroCounter > 0){
                palindrome = '0' + palindrome;
                zeroCounter--;
            }
            revPalindrome = palindrome;
            reverse(revPalindrome.begin(), revPalindrome.end());
            if(palindrome == revPalindrome){
            cout<<"YES\n";
            return 0;
            }
        }
        cout<<"NO\n";
        return 0;
    }
}