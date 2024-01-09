// There is a company with 
// N employees. Employees are managed by other employees. The owner of the company is the only employee who is 
// not managed by any other employee. An employee who does not manage another employee is called a worker. 
// The employees that a certain employee manages are called his subordinates.
// Workers (employees who do not manage any other employees) can file requests to increase their salary.
// These requests are filed to their direct manager. If a direct manager receives requests from at least 
// T percent of his direct subordinates, he must file a request to his direct manager to increase the salaries. 
// If the owner receives requests from at least T percent of his direct subordinates, 
// then he finally decides to accept the requests and increase the salaries.
// Find the minimum number of workers who need to file requests for the owner to make the decision to 
// increase the salaries.
// Every employee has a unique ID which is an integer from 1 to 
// N. The ID of the owner is 0.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int dfs(vector<vector<int>>& hierarchy, int current, int t_percent, int total_subordinates) {
    vector <int> minimum_needed;
    int target = ceil(((static_cast<double>(t_percent))/100)*hierarchy[current].size());

    for (int subordinate : hierarchy[current]) {
        int sub_result = dfs(hierarchy, subordinate, t_percent, hierarchy[subordinate].size());
        minimum_needed.push_back(sub_result);
    }
    sort(minimum_needed.begin(),minimum_needed.end());
    int sum = 0;
    for(int i=0;i<target;i++)
        sum += minimum_needed[i];
    
    // Check if the current manager is a leaf (does not manage any other employee)
    if (hierarchy[current].size() == 0) {
            return 1; 
    }
    return sum; 
}

int main() {
    int N, T;

    while (true) {
        cin >> N >> T;

        if (N == 0 && T == 0) {
            break;
        }

        vector<vector<int>> hierarchy(N + 1); 

        for (int i = 1; i <= N; ++i) {
            int manager;
            cin >> manager;
            hierarchy[manager].push_back(i);
        }

        int owner = 0;
        int total_subordinates = hierarchy[owner].size();
        int ans = dfs(hierarchy, owner, T, total_subordinates);

        cout << ans << endl;
        ans = 0;
    }

    return 0;
}