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
    int x, n;
    cin >> x >> n;
 
    set<int> pos;
    multiset<int> len;
 
    pos.insert(0);
    pos.insert(x);
 
    len.insert(x);
 
    for(int i = 0; i < n; i++){
        int curr;
        cin >> curr;
 
        auto it = pos.upper_bound(curr);
        int r = *it;
        int l = *prev(it);
 
        len.erase(len.find(r - l));
 
        len.insert(curr - l);
        len.insert(r - curr);
 
        pos.insert(curr);
 
        cout << *len.rbegin() << " ";
    }
}
 
int32_t main() {
    fastio();
    solve();
    return 0;
}
