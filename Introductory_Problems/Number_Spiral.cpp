#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int y , x;
    cin >> y >> x;
    int res;
    if(x > y){
        if(x & 1){
            res = (x * x) - (y - 1);
        }else{
            res = (((x - 1) * (x - 1)) + 1) + (y - 1);
        }
    }else{
        if(!(y & 1)){
            res = (y * y) - (x - 1);
        }else{
            res = (((y - 1) * (y - 1)) + 1) + (x - 1);
        }
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}