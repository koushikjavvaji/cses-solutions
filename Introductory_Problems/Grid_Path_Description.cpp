#include <bits/stdc++.h>

using namespace std;

#define int long long

string s;
bool visited[7][7];

int ans = 0;

bool valid(int r, int c) {
    return r >= 0 && r < 7 && c >= 0 && c < 7 && !visited[r][c];
}

void dfs(int r, int c, int step) {

    if (r == 6 && c == 0) {
        if (step == 48) ans++;
        return;
    }

    if (step == 48) return;

    if (!valid(r - 1, c) && !valid(r + 1, c) &&
        valid(r, c - 1) && valid(r, c + 1))
        return;

    if (!valid(r, c - 1) && !valid(r, c + 1) &&
        valid(r - 1, c) && valid(r + 1, c))
        return;

    visited[r][c] = true;

    if ((s[step] == 'D' || s[step] == '?') && valid(r + 1, c))
        dfs(r + 1, c, step + 1);

    if ((s[step] == 'U' || s[step] == '?') && valid(r - 1, c))
        dfs(r - 1, c, step + 1);

    if ((s[step] == 'L' || s[step] == '?') && valid(r, c - 1))
        dfs(r, c - 1, step + 1);

    if ((s[step] == 'R' || s[step] == '?') && valid(r, c + 1))
        dfs(r, c + 1, step + 1);

    visited[r][c] = false;
}

void solve() {

    cin >> s;

    dfs(0, 0, 0);

    cout << ans << '\n';
}

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

}