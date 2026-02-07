/************************************************
*               Koushik's Template              *
*          Om Namho Venkatesaya                 *
*************************************************/
 
/************************************************
*                 Includes                      *
*************************************************/
 
#include<bits/stdc++.h>
using namespace std;
 
/************************************************
*                 Macros                        *
*************************************************/
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define nline "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
 
/************************************************
*                 Typedefs                      *
*************************************************/
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/************************************************
*             Utility Functions                 *
*************************************************/
 
ll mod_add(ll a, ll b, ll m) { a %= m; b %= m; return (a + b) % m; }
ll mod_mul(ll a, ll b, ll m) { a %= m; b %= m; return (a * b) % m; }
 
/************************************************
*              Debugging Section                *
*************************************************/
 
#ifdef Koushik
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
/************************************************
*               Main Function                   *
*************************************************/
int n;
int dp[20][11][2][2]; // lastDigit mapped to [-1, 9] --> index [-1 + 1] => [0, 10]
 
// DP function
int f(int index , int lastDigit , int limit , int started , string &hl)
{
    if(index == n) return 1;
    
    if(dp[index][lastDigit + 1][limit][started] != -1)
    {
        return dp[index][lastDigit + 1][limit][started];
    }
    
    int ans = 0;
    int hp = (limit == 1) ? (hl[index] - '0') : 9;
    
    for(int i = 0; i <= hp; i++)
    {
        if(!started && i == 0)
        {
            int newIndex = index + 1;
            int newLastDigit = -1;
            int newLimit = (limit == 1 && i == hp) ? 1 : 0;
            int newStarted = 0;
            ans += f(newIndex , newLastDigit , newLimit , newStarted , hl);
        }
        else
        {
           if(lastDigit == i)
           {
            continue;
           } 
           int newIndex = index + 1;
           int newLastDigit = i;
           int newLimit = (limit == 1 && (i == hl[index] - '0')) ? 1 : 0;
           int newStarted = 1;
           ans += f(newIndex , newLastDigit , newLimit , newStarted , hl);
        }
    }
    
    return dp[index][lastDigit + 1][limit][started] = ans;
}
 
// A helper function to find valid numbers from 0 to hl (string)
int count_valid_numbers(string hl) {
    n = hl.size();
    memset(dp, -1, sizeof(dp));  // DP array reset
    return f(0, -1, 1, 0, hl);
}
 
// Solve for range l to r
void solve() {
    int l, r;
    cin >> l >> r;
 
    string r_str = to_string(r);
    string l_str = to_string(l - 1);  // We need to find for (l-1)
 
    // Calculate f(r) and f(l-1)
    int res_r = count_valid_numbers(r_str);
    int res_l = count_valid_numbers(l_str);
 
    cout << res_r - res_l << nline;
}
 
int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
