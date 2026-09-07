#include <iostream>
#include <vector>
using namespace std;
 
#define int long long
 
void solve() {
    int n;
    cin >> n;
 
    vector<vector<int>> a(n, vector<int>(n, 0));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i ^ j;
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
}