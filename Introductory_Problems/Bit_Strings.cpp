#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define MOD 1000000007
 
void solve(){
    int n;
    cin >> n;
    int res = 1;
    for(int i = 1 ; i <= n ; i++){
        res = ((res % MOD) * 2) % MOD; 
    }
    cout << res << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}