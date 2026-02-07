#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    // Vector to store the smallest tail for all increasing subsequences of different lengths
    vector<int> tails;
 
    for (int i = 0; i < n; ++i) {
        // Use binary search to find the position where a[i] can be placed
        auto it = lower_bound(tails.begin(), tails.end(), a[i]);
        
        if (it == tails.end()) {
            // If a[i] is larger than any element in tails, it extends the largest subsequence
            tails.push_back(a[i]);
        } else {
            // Otherwise, replace the first element in tails that is larger or equal to a[i]
            *it = a[i];
        }
    }
 
    // The size of the tails array is the length of the longest increasing subsequence
    cout << tails.size() << endl;
 
    return 0;
}
