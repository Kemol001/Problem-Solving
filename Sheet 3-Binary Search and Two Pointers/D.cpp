// There are n workers. The proficiency of the ith worker is ai.
// You are asked to form a group of workers. You want the number of workers in the group to be as large as possible. 
// A group is called good if the difference in proficiency between any two workers in the group does not exceed 5.
// What is the maximum number of workers in a good group?
// The first line contains a single integer n. 1 <= n <= 200000
// The second line contains n integers a1, a2,...,an which are the proficiencies of each worker. 1 <= ai <= 109
// Print one integer — the maximum possible number of workers in a good group.

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> proficiency(n);

    for (int i = 0; i < n; i++)
        cin >> proficiency[i];

    sort(proficiency.begin(), proficiency.end());

    int i = 0, j = 0, maxWorkers = 0, currentWorkers = 0;

    while (j < n) {
        while (j < n && proficiency[j] - proficiency[i] <= 5) {
            j++;
            currentWorkers++;
        }

        maxWorkers = max(maxWorkers, currentWorkers);

        // Move the starting index of the window
        i++;
        currentWorkers--;
    }

    cout << maxWorkers << endl;

    return 0;
}
