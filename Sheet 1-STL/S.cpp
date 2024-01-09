#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int operationNum, input;
    string operation;
    multiset<int> set;
    vector<pair<string, int>> finalOperations;
    cin >> operationNum;
    for (int i = 0; i < operationNum; i++)
    {
        cin >> operation;
        if (operation == "insert")
        {
            cin >> input;
            set.insert(input);
            finalOperations.push_back({operation, input});
        }
        else if (operation == "removeMin")
        {
            if (set.empty())
            {
                finalOperations.push_back({"insert", 0});
                finalOperations.push_back({operation, 0});
            }
            else
            {
                set.erase(set.begin());
                finalOperations.push_back({operation, 0});
            }
        }
        else if (operation == "getMin")
        {
            cin >> input;
            if (set.find(input) == set.end())
            {
                set.insert(input);
                finalOperations.push_back({"insert", input});
            }
            while (*set.begin() != input)
            {
                set.erase(set.begin());
                finalOperations.push_back({"removeMin", 0});
            }
            finalOperations.push_back({operation, *set.begin()});
        }
    }
    cout << finalOperations.size() << endl;
    for (auto i : finalOperations)
    {
        if (i.first == "removeMin")
        {
            cout << i.first << endl;
            continue;
        }
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}