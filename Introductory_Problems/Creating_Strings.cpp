#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve(){
    string s;
    cin >> s;
 
    sort(s.begin(), s.end());
    vector<string> permutations;
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
 
    cout << permutations.size() << endl;
    for (const auto& perm : permutations) {
        cout << perm << endl;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}