// There are n cities in a far away land, numbered 1 through n. Cities are arranged in one long row. 
// The distance between cities i and j is equal to |i - j|.
// Ahmed is a detective. He lives in a city p. His job is to catch thieves. 
// It's hard because he doesn't know in which cities thieves are. Though, he knows that there is at most one 
// thief in each city.
// Ahmed is going to use a special device called the theif detector (TD). 
// The TD will tell Ahmed how many thieves there are for every distance from city p. 
// After that, Ahmed can catch a thief in each city for which he is sure that there must be a thief.
// You know in which cities thieves are. Count the number of criminals Ahmed will catch, after he uses the TD.
// The first line of the input contains two integers n and p (1 ≤ p ≤ n ≤ 100) — the number 
// of cities and the index of city where Ahmed lives.
// The second line contains n integers t1, t2, ..., tn (0 ≤ ti ≤ 1). There are ti thieves in the i-th city.
// Print the number of thieves Ahmed will catch.

#include <iostream>

using namespace std;

int main()
{
    int nCities, index, counter = 0;
    cin >> nCities >> index;
    int Cities[nCities];

    for (int i = 0; i < nCities; i++)
        cin >> Cities[i];

    index--; 

    for (int i = 0; i <= max(index, nCities - 1 - index); i++)
    {
        int left = index - i;
        int right = index + i;

        if (left >= 0 && right < nCities)
        {
            if (left == right && Cities[left] == 1)
                counter++;
            else if (Cities[left] == 1 && Cities[right] == 1)
                counter += 2;
        }
        else if (left >= 0 && Cities[left] == 1)
            counter++;
        else if (right < nCities && Cities[right] == 1)
            counter++;
    }

    cout << counter << endl;
    return 0;
}
