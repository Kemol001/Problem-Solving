// A group of workers are making a company. However, they haven't yet figured out who is going to
// manage who in the company.
// They know that one of the workers will be the main manager, and each of the other workers will have exactly 
// one manager (and that manager, if he is not the main manager, will have a manager of his own too).
// Every manager will have a strictly greater salary than all of his subordinates - therefore, there are no cycles.
// Therefore, the hierarchy of the company can be represented as a rooted tree.
// In order to agree on who is going to be who's manager, they've chosen the K most successful workers,
// and each of them has given a statement: I want to be the superior of him, him, and him 
// (they could be successful or unsuccessful). Being a superior means to be the manager, or to be one of the 
// manager's superiors (so a superior of a worker is not necessary his direct manager).
// Help this immature company and create a hierarchy that will satisfy all of the successful workers' wishes. 
// A solution, not necessary unique, will exist in all of the test data.
// Input
// In the first line of input, read positive integers N (N ≤ 100 000), total number of workers, and K (K < N), 
// the number of successful workers. All workers are numbered 1..N, while the successful ones are numbered 1..K.
// Then follow K lines. In Ath of these lines, first read an integer W (the number of wishes of the worker A, 1 ≤ W ≤ 10),
// and then W integers from the range [1, N] which denote workers which worker A wants to be superior to.
// Output
// Output N integers. The Ath of these integers should be 0 if worker A is the main manager, and else it should
// represent the manager of the worker A.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sort(int nWorkers,int nSWorkers,vector<vector<int>>& wishes,vector<int>& indegree){
    queue<int> zeroInDegree;
        for (int i = 1; i <= nWorkers; i++) {
            if (indegree[i] == 0)
                zeroInDegree.push(i);
        }
 
        vector<int> ans(nWorkers+1);
        bool flag = false;
        int previous;
        while (!zeroInDegree.empty()) {
            if (flag == false){
                int node = zeroInDegree.front();
                zeroInDegree.pop();
                ans[node]=0;
                previous = node;
                flag = true;
                for (auto e: wishes[node]) {
                    indegree[e]--;
                    if (indegree[e] == 0)
                        zeroInDegree.push(e);
                }
            }
            else{
                int node = zeroInDegree.front();
                zeroInDegree.pop();
                ans[node]=previous;
                previous = node;
                for (auto e: wishes[node]) {
                    indegree[e]--;
                    if (indegree[e] == 0)
                        zeroInDegree.push(e);
                }
            }
        }
        for(int i=1;i<ans.size();i++)
            cout<<ans[i]<<endl;
}

int main()
{
    int nWorkers,nSWorkers;

    cin>>nWorkers>>nSWorkers;

    vector<vector<int>> wishes(nWorkers+1);
    vector <int> indegree(nWorkers+1);
    for(int i=1 ;i <= nSWorkers;i++){
        int nWishes;
        cin>>nWishes;
        while(nWishes--){
            int number;
            cin>>number;
            wishes[i].push_back(number);
            indegree[number]++;
        }
    }
    for (int i=nSWorkers+1;i<nWorkers+1;i++){
        wishes[1].push_back(i);
        indegree[i]++;
    }

    vector<pair<int,vector<int>>> hierarchy(nWorkers+1);
    sort(nWorkers,nSWorkers,wishes,indegree);
}