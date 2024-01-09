#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> arr(size), prefixSum(size);

    int elem;
    for (int i = 0; i < size; i++) {
        cin >> elem;
        arr[i] = elem;
    }

    for (int i = 0; i < size; i++) {
        prefixSum[i] = arr[i];
        if (i > 0) {
            prefixSum[i] += prefixSum[i - 1];
        }
    }

    int operations, start, finish;
    vector<int> result;
    cin >> operations;

    for (int i = 1; i <= operations; i++) {
        cin >> start >> finish;
        int sum = prefixSum[finish] - (start > 0 ? prefixSum[start - 1] : 0);
        result.push_back(sum);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}

