#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i < (1 << n) ; i++){
        int gray = i ^ (i >> 1);

        for(int j = n - 1 ; j >= 0 ; j--){
            cout << ((gray >> j) & 1);
        }
        cout << endl;
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