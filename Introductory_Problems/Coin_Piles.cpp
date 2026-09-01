#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int a , b;
    cin >> a >> b;
    if((a + b) % 3 != 0){
        cout << "NO" << endl;
    }else if((a > (2 * b)) || (b > (2 * a))){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}