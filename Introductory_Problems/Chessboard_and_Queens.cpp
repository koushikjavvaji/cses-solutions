#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
/*
(1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (1,7) (1,8)
(2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8)
(3,1) (3,2) (3,3) (3,4) (3,5) (3,6) (3,7) (3,8)
(4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7) (4,8)
(5,1) (5,2) (5,3) (5,4) (5,5) (5,6) (5,7) (5,8)
(6,1) (6,2) (6,3) (6,4) (6,5) (6,6) (6,7) (6,8)
(7,1) (7,2) (7,3) (7,4) (7,5) (7,6) (7,7) (7,8)
(8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (8,7) (8,8)
 
 
*/
 
void solve(){
    vector<string> s(8);
    for(int i = 0; i < 8; i++) cin >> s[i];
    int ans = 0;
    vector<int>takencols(8, 0) , takendiag1(15, 0) , takendiag2(15, 0);
    function<void(int)> f = [&](int i){
        if(i == 8) {
            ans++;
            return;
        }
        for(int j = 0; j < 8; j++){
            if(s[i][j] == '*') continue;
            bool ok = true;
            if(takencols[j] || takendiag1[j - i + 7] || takendiag2[i + j]) ok = false;
            if(ok){
                takencols[j] = 1;
                takendiag1[j - i + 7] = 1;
                takendiag2[i + j] = 1;
                f(i + 1);
                takencols[j] = 0;
                takendiag1[j - i + 7] = 0;
                takendiag2[i + j] = 0;
            }
        }
    };
    f(0);
    cout << ans << "\n";
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}