#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    int ans = LLONG_MAX;
    
    function<void(int , int)> f = [&](int i, int s){
        if(i == n){
            ans = min(ans, abs(sum - 2 * s));
            return;
        }
        f(i + 1, s);
        f(i + 1, s + a[i]);
    };
 
    f(0, 0);
 
    cout << ans << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}
