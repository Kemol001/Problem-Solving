#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int get_earliest_start_time(int queried_job, vector<int>& times, vector<vector<int>>& jobs_we_depend_on){
    queue<int> jobs;
    int time_sum = -times[queried_job];
    vector<bool> visited(times.size(), false);
    jobs.push(queried_job);
    visited[queried_job] = true;
    while(!jobs.empty()){
        int temp_job = jobs.front();
        jobs.pop();
        time_sum += times[temp_job];
        for(int job : jobs_we_depend_on[temp_job]){
            if(!visited[job]){
                jobs.push(job);
                visited[job] = true;
            }
        }
    }
    return time_sum;
}

int get_latest_start_time (int queried_job, int Max_times, vector<int>& times, vector<vector<int>>& jobs_that_depend_on_us){
    queue<int> jobs;
    vector<bool> visited(times.size(), false);
    jobs.push(queried_job);
    visited[queried_job] = true;
    while(!jobs.empty()){
        int temp_job = jobs.front();
        jobs.pop();
        Max_times -= times[temp_job];
        for(int job : jobs_that_depend_on_us[temp_job]){
            if(!visited[job]){
                jobs.push(job);
                visited[job] = true;
            }
        }
    }
    return Max_times;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int jobs, dependencies, tc_counter = 1;

    while (cin >> jobs >> dependencies, jobs)
    {
        vector<int> times(jobs + 1);
        vector<vector<int>> jobs_we_depend_on(jobs + 1);
        vector<vector<int>> jobs_that_depend_on_us (jobs + 1);
        int Max_times = 0;
        for (int i = 1; i < jobs + 1; i++)
        {
            int time;
            cin >> time;
            Max_times += time;
            times[i] = time;
        }
        for (int i = 0; i < dependencies; i++)
        {
            int job, dependent;
            cin >> job >> dependent;
            jobs_we_depend_on[dependent].push_back(job);
            jobs_that_depend_on_us[job].push_back(dependent);
        }

        int queries;
        cin >> queries;
        cout << "Case #" << tc_counter++ << ":\n";
        for(int i = 0;  i< queries ; ++i)
        {
            int queried_job;
            cin >> queried_job;
            cout << get_latest_start_time(queried_job, Max_times, times, jobs_that_depend_on_us) - get_earliest_start_time(queried_job, times, jobs_we_depend_on) << '\n';
        }
        cout << '\n';
    }

    return 0;
}