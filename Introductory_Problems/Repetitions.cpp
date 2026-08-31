#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int res = 0 , cnt = 0;
    for(int i = 1 ; i < n ; i++){
        if(s[i] == s[i - 1]){
            cnt++;
        }else{
            cnt = 0;
        }
        res = max(res , cnt);
    }
    cout << res + 1 << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}