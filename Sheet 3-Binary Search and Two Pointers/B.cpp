#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double k;
    cin >> n >> k;

    vector<double> v(n);

    double left = 0, right = 100000 , mid = (left + right) / 2;;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    while (right - left > 0.0000000001) {
        mid = (left + right) / 2;
        double batteryJ = 0, batteryI = 0;

        for (double val : v) {
            if (val >= mid) {
                batteryI += val - mid;
            } 
            else {
                batteryJ += (mid - val) / (1.0 - k / 100.0);
            }
        }

        if (batteryJ > batteryI) {
            right = mid;
        } 
        else {
            left = mid;
        }
    }

    cout << fixed << setprecision(9) << left << "\n";
    return 0;
}