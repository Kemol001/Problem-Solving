#include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;

 long long calculateSum(long long m,long long n,long long a[]) {
    vector<long long> b;
    for (int i = 1; i <= n; i++) {
        b.push_back(a[i] + i * m);
    }
    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        sum += b[i];
    }
    return sum;
 }

 void solve() {
    int N = 1e5 + 1;
    long long n, s, a[N];
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int left = 0, right = n, ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (calculateSum(mid,n,a) <= s) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << " " << calculateSum(ans,n,a);
 }

 int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
 }