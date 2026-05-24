#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

void solve() {

    int n, k;
    cin >> n >> k;

    ordered_set s;

    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    int pos = 0;

    while (!s.empty()) {

        pos = (pos + k) % s.size();

        auto it = s.find_by_order(pos);

        cout << *it << " ";

        s.erase(it);
    }

    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}
