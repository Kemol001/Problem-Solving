
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countLessEqual(long long x, int n, int m) {
    long long count = 0;
    for (int i = 1; i <= n; ++i) {
        count += min((long long)m, x / i);
    }
    return count;
}

long long findLargestElement(int n, int m, int l) {
    long long left = 1;
    long long right = static_cast<long long>(n) * m;

    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long count = countLessEqual(mid, n, m);

        if (count < l) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    long long result = findLargestElement(n, m, l);
    cout << result << endl;
    return 0;
}

