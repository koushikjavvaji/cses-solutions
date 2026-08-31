#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int>a(n , LLONG_MAX);
    for(int i = 0 ;i < n - 1 ; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    for(int i = 1 ; i <= n ;i++){
        if(a[i - 1] != i){
            cout << i << endl;
            break;
        }
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