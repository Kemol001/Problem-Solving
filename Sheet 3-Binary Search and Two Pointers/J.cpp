// Ahmed and his k family members want to stay in a hotel which has n rooms.
// Ahmed wants to book a set of k + 1 unoccupied rooms for him and his family members.
// He wants his family to stay as close as possible to him,
// so he wishes to minimize the maximum distance from his room to the room of a family member.
// The distance between rooms i and j is defined as |j - i|.
// Help Ahmed by calculating this minimum possible distance.
// The first line of the input contains two integers n and k (1 ≤ k < n ≤ 100 000) — 
// the number of rooms in the hotel and the number of Ahmed's family members.
// The second line contains a string of length n describing the rooms. The i-th character of the string will be '0'
// if the i-th room is free, and '1' if the i-th room is occupied. It is guaranteed that at least k + 1 characters 
// of this string are '0', so there exists at least one possible choice of k + 1 rooms for Ahmed and his family
// to stay in.
// Print the minimum possible distance between Ahmed and his farthest family member.

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main()
{
    int nRooms,nFamily;
    cin>>nRooms>>nFamily;

    string rooms;
    cin>>rooms;
    vector <int> free;
    for(int i=0;i<nRooms;i++){
        if(rooms[i] == '0')
            free.push_back(i);
    }
    free.shrink_to_fit();
    int left = 0,right = nFamily ,ahmed = lower_bound(free.begin(),free.end(),((free[left]+free[right])/2))-free.begin(),minDistance = INT_MAX;
    while(right < free.size()){
        int distance1 = max(abs(free[ahmed]-free[left]),abs(free[right]-free[ahmed]));
        int distance2 = max(abs(free[ahmed-1]-free[left]),abs(free[right]-free[ahmed-1]));
        int distance = min(distance1,distance2);
        if(minDistance > distance){
            minDistance = distance;
        }
        left++;
        right++;
        ahmed = lower_bound(free.begin(),free.end(),((free[left]+free[right])/2))-free.begin();
    }
    cout<<minDistance;
    return 0;
}