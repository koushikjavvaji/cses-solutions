/************************************************
*               Koushik's Template              *
*          Om Namho Venkatesaya                 *
*************************************************/
 
/************************************************
*                 Includes                      *
*************************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
/************************************************
*                 Macros                        *
*************************************************/
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
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
 
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m) { a %= m; b %= m; return (a + b) % m; }
ll mod_mul(ll a, ll b, ll m) { a %= m; b %= m; return (a * b) % m; }
ll mod_sub(ll a, ll b, ll m) { a %= m; b %= m; return (a - b + m) % m; }
ll mod_expo(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
bool revsort(ll a, ll b) { return a > b; }
vector<ll> sieve(int n) { vector<bool> is_prime(n+1, true); vector<ll> primes; for (ll i = 2; i <= n; i++) { if (is_prime[i]) { primes.push_back(i); for (ll j = i * i; j <= n; j += i) is_prime[j] = false; } } return primes; }
 
/************************************************
*              Debugging Section                *
*************************************************/
#ifdef Koushik
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#elif !defined(ONLINE_JUDGE)
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/************************************************
*               Main Function                   *
*************************************************/
vector<int> topo;
void topoSORT(int curr, vector<vector<int>>& edges, vector<int>& vis) {
    vis[curr] = 1;
    for (auto it : edges[curr]) {
        if (!vis[it]) {
            topoSORT(it, edges, vis);
        }
    }
    topo.pb(curr);
}
void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>edges(n);
    for(int i = 0 ;i < m ;i++)
    {
        int u , v;
        cin >> u >> v;
        u--;v--;
        edges[u].pb(v);
    }
    vector<int>vis(n , 0);
    for(int i = 0 ;i < n ;i++)
    {
        if(!vis[i])
        {
    topoSORT(0 , edges , vis);
}
    }
    reverse(topo.begin() , topo.end());
    vector<int>dp(n , 0);
    vector<int>parent(n , -1);
    parent[0] = -1;
    bool flag = 0;
    dp[0] = 1;
    for(int i = 0 ; i < n ;i++)
    {
        if(topo[i] == 0) flag = true;
        if(flag)
        {
            for(auto it : edges[topo[i]])
            {
                // dp[it] = max(dp[it] , dp[topo[i]] + 1);
                if((dp[topo[i]] + 1) > dp[it])
                {
                    parent[it] = topo[i];
                    dp[it] = dp[topo[i]] + 1;
                }
            }
        }
    }
    debug(dp);
    vector<int>res;
    debug(parent);
        int curr = n - 1;
        while(curr != -1)
        {
            res.pb(curr);
            curr = parent[curr];
        }
        debug(res);
        reverse(res.begin(),res.end());
        if(res[0] != 0)
        {
            cout << "IMPOSSIBLE" << nline;
        }
        else
        {
        cout << res.size() << nline;
        for(int i = 0 ;i < res.size() ; i++)
        {
            cout << res[i] + 1 << " ";
        }
        cout << nline;
    }
    }
int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
