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
int c = 0;
 
void topoSORT(int curr, vector<vector<int>>& edges, vector<int>& vis) {
    vis[curr] = 1;
    for (auto it : edges[curr]) {
        if (!vis[it]) {
            topoSORT(it, edges, vis);
        }
    }
    topo.pb(curr);
}
 
void goCOLOR(int curr, vector<int>& vis, vector<vector<int>>& Tedges, vector<int>& col) {
    col[curr] = c;
    vis[curr] = 1;
    // cout << curr + 1 << " " << c << nline;
    for (auto it : Tedges[curr]) {
        if (!vis[it]) {
           // cout << curr << " " << it << nline;
            goCOLOR(it, vis, Tedges, col);
        }
    }
}
 
void getSCC(int n, vector<vector<int>>& edges, vector<vector<int>>& Tedges, vector<int>& k, vector<int>& vis, vector<int>& col, vector<int>& val, vector<vector<int>>& res) {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topoSORT(i, edges, vis);
        }
    }
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    for (int i = topo.size() - 1; i >= 0; i--) {
        // cout << topo[i] << nline;
        if (!vis[topo[i]]) {
            goCOLOR(topo[i], vis, Tedges, col);
            c++;
        }
    }
    val.assign(c, 0);
    res.assign(c, vector<int>());
    for (int i = 0; i < n; i++) {
        val[col[i]] += k[i];
        for (auto j : edges[i]) {
            if (col[i] != col[j]) {
                res[col[i]].pb(col[j]);
            }
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n), Tedges(n);
    vector<int> vis(n, 0), k(n), col(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
        Tedges[v].pb(u);
    }
    vector<int> val, maxi, visi;
    vector<vector<int>> res;
    getSCC(n, edges, Tedges, k, vis, col, val, res);
    debug(res);
    maxi.assign(c, 0);
    visi.assign(c, 0);
    topo.clear();
    for (int i = 0; i < c; i++) {
        if (!visi[i]) {
            topoSORT(i, res, visi);
        }
    }
    // reverse(all(topo));
    debug(topo);
    for (int i : topo) {
        maxi[i] = val[i];
        for (auto it : res[i]) {
            maxi[i] = max(maxi[i], val[i] + maxi[it]);
        }
    }
    debug(maxi);
    int answer = *max_element(all(maxi));
    cout << answer << nline;
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
