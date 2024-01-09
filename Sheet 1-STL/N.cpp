// Our good friend Mole is trying to code a big message. He is typing on an unusual keyboard with characters 
// arranged in following way:
// qwertyuiop
// asdfghjkl;
// zxcvbnm,./
// Unfortunately Mole is blind, so sometimes it is problem for him to put his hands accurately.
// He accidentally moved both his hands with one position to the left or to the right.
// That means that now he presses not a button he wants, but one neighboring button 
// (left or right, as specified in input).
// We have a sequence of characters he has typed and we want to find the original message
// First line of the input contains one letter describing direction of shifting 
// ('L' or 'R' respectively for left or right).
// Second line contains a sequence of characters written by Mole. 
// The size of this sequence will be no more than 100. 
// Sequence contains only symbols that appear on Mole's keyboard. 
// It doesn't contain spaces as there is no space on Mole's keyboard.
// It is guaranteed that even though Mole hands are moved, 
// he is still pressing buttons on keyboard and not hitting outside it
// Print a line that contains the original message.

#include <iostream>

using namespace std;

int main()
{
    char keyboard1[] = {'q','w','e','r','t','y','u','i','o','p'};
    char keyboard2[] = {'a','s','d','f','g','h','j','k','l',';'};
    char keyboard3[] = {'z','x','c','v','b','n','m',',','.','/'};
    char key,message;
    cin>>key;
    while((key == 'R' ||key == 'L') && cin>>message){
        for(int i=0;i<10;i++){
            if(keyboard1[i] == message){
                if(key == 'R'){
                    cout<<keyboard1[i-1];
                    break;
                }
                else if(key == 'L'){
                    cout<<keyboard1[i+1];
                    break;
                }
            }
            else if(keyboard2[i] == message){
                if(key == 'R'){
                    cout<<keyboard2[i-1];
                    break;
                }
                else if(key == 'L'){
                    cout<<keyboard2[i+1];
                    break;
                }
            }
            else if(keyboard3[i] == message){
                if(key == 'R'){
                    cout<<keyboard3[i-1];
                    break;
                }
                else if(key == 'L'){
                    cout<<keyboard3[i+1];
                    break;
                }
            }
        }
    }
    return 0;
}