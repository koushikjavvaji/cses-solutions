#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    int temp = 5;
    int res = 0;
    while(true){
        if((n / temp) == 0){
            break;
        }else{
            res += (n / temp);
            temp *= 5;
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