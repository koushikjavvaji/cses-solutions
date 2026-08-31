#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
    }
    int res = 0;
    for(int i = 1 ; i < n ; i++){
        res += max(0 * 1LL , a[i - 1] - a[i]);
        if(a[i] < a[i - 1]){
            a[i] = a[i - 1];
        }
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