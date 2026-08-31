#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n & 1){
            n *= 3;
            n++;
        }else{
            n /= 2;
        }
    }
    cout << 1 << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}