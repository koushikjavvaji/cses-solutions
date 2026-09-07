#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (auto &row : grid)
        cin >> row;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if ((i + j) % 2 == 0) {
                if (grid[i][j] != 'A')
                    grid[i][j] = 'A';
                else
                    grid[i][j] = 'B';
            }
            else {
                if (grid[i][j] != 'C')
                    grid[i][j] = 'C';
                else
                    grid[i][j] = 'D';
            }
        }
    }

    for (auto &row : grid)
        cout << row << '\n'; 
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}