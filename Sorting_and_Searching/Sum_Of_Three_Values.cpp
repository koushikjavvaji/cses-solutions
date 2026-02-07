#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
 
    // Sort the array based on the values
    sort(a.begin(), a.end());
 
    // Iterate over each pair of elements
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int required = x - a[i].first - a[j].first;
 
            // Perform binary search for the required value
            int left = j + 1, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[mid].first == required) {
                    cout << a[i].second << " " << a[j].second << " " << a[mid].second << endl;
                    return 0;
                } else if (a[mid].first < required) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    }
 
    // If no such triplet is found
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
