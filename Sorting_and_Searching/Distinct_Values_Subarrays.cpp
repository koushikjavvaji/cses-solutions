/*
*************************************************
*               Koushik's Template              *
*          Om namho Venkatesaya                 *
*************************************************
*/
 
#include <bits/stdc++.h>
using namespace std;
 
/************************************************
*                 Macros                        *
*************************************************/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 998244353
#define nline "\n"
#define pb push_back
#define ff first
#define ss second
#define int long long
 
typedef long long ll;
 
/************************************************
*               Main Function                   *
*************************************************/
void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    map<int , int> mp;
    int res = 0;
    int left = 0;
 
    for(int i = 0 ; i < n ; i++){
        if(mp.count(a[i])){
            left = max(left, mp[a[i]]);
        }
        res += (i - left + 1);
        mp[a[i]] = i + 1;
    }
 
    cout << res << nline;
}
 
int32_t main() {
    fastio();
    solve();
    return 0;
}
