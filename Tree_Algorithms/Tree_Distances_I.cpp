/*
*************************************************
*               Koushik's Template              *
*          Om Namho Venkatesaya                 *
*************************************************
*/
 
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
 
typedef long long ll; // Define ll as long long
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
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ll t) {cerr << t;}
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
#else
#define debug(x);
#endif
 
/************************************************
*              LCA Section                      *
*************************************************/
 
const int MAXN = 2e5 + 5;
const int LOG = 20; // for 2^20 > 10^5
 
vector<int> adj[MAXN];
int up[MAXN][LOG]; // up[v][j] is the 2^j-th ancestor of v
int depth[MAXN];
 
void dfs_lca(int v, int parent) {
    up[v][0] = parent;
    for (int i = 1; i < LOG; i++) {
        if (up[v][i - 1] != -1)
            up[v][i] = up[up[v][i - 1]][i - 1];
        else
            up[v][i] = -1;
    }
    for (int u : adj[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs_lca(u, v);
        }
    }
}
 
int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
 
    // Lift u to the same level as v
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v])
            u = up[u][i];
    }
 
    if (u == v) return u;
 
    // Lift u and v together until their LCA is found
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
 
    return up[u][0];
}
 
/************************************************
*               Main Function                   *
*************************************************/
void dfs(int curr , vector<vector<int>>&edges , int parentNode , vector<int>&level , 
    int currLevel , vector<int>&leaf , vector<int>&farthestNode)
{
    level[curr] = currLevel;
    farthestNode[curr] = curr;
    for(auto neighbour : edges[curr])
    {
        if(neighbour != parentNode)
        {
            dfs(neighbour , edges , curr , level , currLevel + 1 , leaf , farthestNode);
            if((leaf[neighbour] + 1) > leaf[curr])
            {
                leaf[curr] = leaf[neighbour] + 1;
                farthestNode[curr] = farthestNode[neighbour];
            }
        }
    }
}
void solve() {
    // Your code goes here
    int n;
    cin >> n;
    vector<vector<int>>edges(n);
    vector<int>level(n , 0);
    vector<int>leaf(n , 0);
    vector<int>farthestNode(n , 0);
    // int currLevel = 0;
    for(int i = 0 ;i < (n - 1) ; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;v--;
        edges[u].pb(v);
        edges[v].pb(u);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0 , edges , -1 ,level , 0 , leaf , farthestNode);
    int d1 = farthestNode[0];
    level.assign(n ,0);
    leaf.assign(n , 0);
    farthestNode.assign(n , 0);
    dfs(d1 , edges , -1 ,level , 0 , leaf , farthestNode);
    int d2 = farthestNode[d1];
 
    // LCA preprocessing
    depth[d1] = 0;
    dfs_lca(d1, -1);
 
    // Now, you can use lca(u, v) to find the LCA of any two nodes u and v.
    // cout << d1 << " " << d2 << nline;
    for(int i = 0 ;i < n ;i++)
    {
        // int inter = 0;
        int dist1;
        if((lca(i , d1) != i) && (lca(i , d1) != d1) )
        {
            dist1 = level[i] + level[d1] - (2 * level[lca(i,d1)]);
            cout << dist1 << " "<< i << " " << d1 << nline;
            cout << dist1 << " "<< level[i] << " " << level[d1] << nline;
            cout << lca(i , d1) << nline;
        }
        else
        {
            dist1 = abs(level[i] - level[d1]);
        }
        int dist2;
        if((lca(i , d2) != i) && (lca(i , d2) != d2) )
        {
            dist2 = level[i] + level[d2] - (2 * level[lca(i,d2)]);
        }
        else
        {
            dist2 = abs(level[i] - level[d2]);
        }
        // cout << level[i] << " " << level[d1] << " " << level[d2] << nline;
        // cout << dist1 << " " << dist2 << nline;
         cout << max(dist1 , dist2)<< " ";
    }
}
int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
