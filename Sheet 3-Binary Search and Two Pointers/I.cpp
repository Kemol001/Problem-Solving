#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1e5 + 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    char s[maxn];
    vector<int> v;

    scanf("%d%d%s", &n, &k, s + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == '0')
            v.push_back(i);
    }

    int len = v.size(), ans = maxn;

    for (int i = 1; i <= len - k; i++) {
        int l = i - 1, r = i + k - 1, mid, midmid, temp;

        while (l + 1 < r) {
            mid = (l + r) >> 1;
            midmid = (mid + r) >> 1;

            int x = max(v[mid] - v[i - 1], v[i + k - 1] - v[mid]);
            int y = max(v[midmid] - v[i - 1], v[i + k - 1] - v[midmid]);

            if (x >= y)
                l = mid;
            else
                r = midmid;
        }

        ans = min(ans, max(v[l] - v[i - 1], v[i + k - 1] - v[l]));
    }

    printf("%d\n", ans);
    return 0;
}