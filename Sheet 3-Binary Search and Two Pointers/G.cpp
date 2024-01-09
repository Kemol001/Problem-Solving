// Lautaro has two sequences a
// and b, both of n elements.
// He has to choose some k and some distinct indexes i1,i2,...,ik∈{1,2,3,...,n}such that there are not two indexes x
// ,y∈{i1,i2,...,ik} such that |ax−ay|≥d . Gennady, his teacher, asks Lautaro to maximize ∑j=1kbij.
// Lautaro will give you a candy if you solve this problem, will you be able to get the candy?
// The first line of the input contains two space-separated integers, n and d (1≤n≤105, 1≤d≤109). Next n lines contain
// two numbers ai,bi(0≤ai,bi≤109) — the i-th elements of sequences a and b, respectively).
// Print the maximum posible sum ∑kj=1bij
// , such that the coditions stated in the statement holds.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> sequences; 

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        sequences.push_back({a, b});
    }

    sort(sequences.begin(), sequences.end());

    long long maxSum = 0;
    vector<long long> prefixSum(n);

    prefixSum[0] = sequences[0].second;
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + sequences[i].second;
    }

    for (int i = 0; i < n; i++) {
    
        int rightIndex = upper_bound(sequences.begin(), sequences.end(), make_pair(sequences[i].first + d, 0)) - sequences.begin() - 1;
        
        long long currentSum = prefixSum[rightIndex];
        if (i > 0) {
            currentSum -= prefixSum[i - 1];
        }

        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}
