#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> network;

int bfs(int A, int B) {
    int n = network.size(), counter = 0;
    vector<int> v(n, 0);
    queue<pair<int, int>> q;
    q.push({0, A});

    while (!q.empty()) {
        pair<int, int> x = q.front();
        q.pop();
        if (v[x.second]) continue;
        v[x.second] = 1;
        for (int v : network[x.second]) {
            if (v == B) return x.first;
            q.push({x.first + 1, v});
        }
    }
    return -1;  
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int nodes;
        cin >> nodes;

        network.clear(); 
        network.resize(nodes);

        int Size, _;
        int x;

        for (int i = 0; i < nodes; ++i) {
            cin >> _ >> Size;
            for (int j = 0; j < Size; j++)
                cin >> x, network[_].push_back(x);
        }

        int A, B;
        cin >> A >> B;
        cout<<A<<" "<<B<<" "<<bfs(A, B)<<( (t==0) ? "\n" : "\n\n"  );
    }
}