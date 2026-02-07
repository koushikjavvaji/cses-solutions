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
*               Main Function                   *
*************************************************/
struct BinaryLifting {
    int n;
    int maxLog;
    ll maxRequirement;
    vector<vector<int>> parent;
    vector<int> logValues;
    bool precomputedLogs = false;
    BinaryLifting(int n1, vector<int> *edges, ll requirement, int root) {
        n = n1;
        parent.resize(n);
        maxLog = log2(requirement + 1);
        maxRequirement = requirement;
        for (int i = 0; i < n; i++) {
            parent[i].resize(maxLog + 1);
            for (int j = 0; j <= maxLog; j++) {
                parent[i][j] = -1;
            }
        }
        fillParentTable(root, edges);
        if (maxRequirement <= 1000000LL)
            precomputeLogs();
    }
    void fillParentTable(int root, vector<int> *edges) {
        vector<bool> visited(n);
        dfsBinaryLifting(root, edges, visited);
        int intermediate = -1;
        for (int i = 1; i <= maxLog; i++) {
            for (int j = 0; j < n; j++) {
                intermediate = parent[j][i - 1];
                if (intermediate != -1) {
                    parent[j][i] = parent[intermediate][i - 1];
                }
            }
        }
    }
    void dfsBinaryLifting(int root, vector<int> *edges, vector<bool> &visited) {
        visited[root] = true;
        for (auto i : edges[root]) {
            if (!visited[i]) {
                parent[i][0] = root;
                dfsBinaryLifting(i, edges, visited);
            }
        }
    }
    void precomputeLogs() {
        precomputedLogs = true;
        logValues.resize(maxRequirement + 1);
        logValues[1] = 0;
        for (int i = 2; i <= maxRequirement; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }
    }
    int kthParent(int start, int k) {
        int a = start;
        while (k > 0) {
            int x = getLog(k);
            a = parent[a][x];
            if (a == -1)
                return a;
            k -= (1 << x);
        }
        return a;
    }
    inline int getLog(ll x) {
        return precomputedLogs ? logValues[x] : log2(x);
    }
};
 
struct LCA {
    int n;
    vector<int> level;
    LCA(int n1, vector<int> *edges, int root) {
        n = n1;
        level.resize(n);
        dfsLCA(root, edges, -1);
    }
    void dfsLCA(int root, vector<int> *edges, int parent) {
        for (auto i : edges[root]) {
            if (i != parent) {
                level[i] = level[root] + 1;
                dfsLCA(i, edges, root);
            }
        }
    }
    int getLCA(int a, int b, BinaryLifting &bl_object) {
        if (level[a] > level[b]) {
            swap(a, b);
        }
        b = bl_object.kthParent(b, level[b] - level[a]);
        if (a == b)
            return a;
        for (int i = bl_object.maxLog; i >= 0; i--) {
            int parent1 = bl_object.parent[a][i];
            int parent2 = bl_object.parent[b][i];
            if (parent2 != parent1 && parent1 != -1 && parent2 != -1) {
                a = parent1;
                b = parent2;
            }
        }
        return bl_object.parent[a][0];
    }
};
void resdfs(int curr , vector<int> *edges ,int parentNode , vector<int>&result , vector<int>&diff)
{
    result[curr] = diff[curr];
    for(auto i : edges[curr])
    {
        if(i != parentNode)
        {
            resdfs(i , edges , curr , result , diff);
            result[curr] += (result[i]);
        }
    }
}
void solve() {
    // Your code goes here
    int n,m;
    cin >> n >> m;
    vector<int>edges[n];
    vector<int>diff(n,0);
    vector<int>result(n,0);
    for(int i = 0 ;i < (n - 1) ; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int root = 0;
    int requirement = n + 5;
    BinaryLifting bl(n, edges, requirement, root);
    LCA lcaSolver(n, edges, root);
    for(int i = 0 ;i < m ;i++)
    {
        int a , b;
        cin >> a >> b;
        a--;b--;
        int lca = lcaSolver.getLCA(a, b, bl);
        int parent = bl.kthParent(lca, 1);
        if(lca != a && lca != b)
        {
            diff[lca]--;
            if(parent != -1)
            {
                diff[parent]--;
            }
            diff[a]++;
            diff[b]++;
        }
        else
        {
            if(parent != -1)
            {
                diff[parent]--;
            }
            if(lca == a)
            {
                diff[b]++;
            }
            else
            {
                diff[a]++;
            }
        }
    }
    resdfs(root , edges , -1 ,result , diff);
    for(int i = 0 ;i < n ; i++)
    {
        cout << result[i] << " ";
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
