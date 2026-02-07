/**************************************************
*               Koushik's Template              *
*          Om Namho Venkatesaya                 *
*************************************************
*/
 
/************************************************
*                 Includes                      *
*************************************************/
 
#include <bits/stdc++.h>
 
using namespace std;
 
/************************************************
*                 Macros                        *
*************************************************/
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 998244353
#define INF LLONG_MAX // Updated to LLONG_MIN
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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/************************************************
*               Main Function                   *
*************************************************/
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {-1 , 1 , 0 , 0};
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pii>> edges(n);
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
 
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges[u].pb({v, w});
    }
 
    // Identify connected components and set dist[node] = 0 for one node in each component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            dist[i] = 0; // Set distance for the first node in the component
 
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto &edge : edges[u]) {
                    int v = edge.ff;
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
 
    vector<int> p(n, -1); // Parent array
    vector<int> temp;
 
    // Bellman-Ford algorithm to detect negative cycles
    for (int j = 1; j <= n + 1; j++) {
        for (int i = 0; i < n; i++) {
            for (auto &it : edges[i]) {
                if (dist[i] != INF && dist[i] + it.ss < dist[it.ff]) {
                    dist[it.ff] = dist[i] + it.ss;
                    p[it.ff] = i;
                }
            }
        }
        if (j == n) temp = dist;
    }
 
    debug(temp);
    debug(dist);
 
    int curr = -1;
    if (temp != dist) {
        for (int i = 0; i < n; i++) {
            if (temp[i] != dist[i]) {
                curr = i;
                break;
            }
        }
    }
 
    if (curr == -1) {
        cout << "NO" << nline;
    } else {
        vector<int> cycle;
        for (int i = 0; i < n; i++) curr = p[curr]; // Move to a node inside the cycle
 
        int start = curr;
        do {
            cycle.pb(curr);
            curr = p[curr];
        } while (curr != start);
        cycle.pb(start);
 
        reverse(all(cycle));
 
        cout << "YES" << nline;
        for (int x : cycle) {
            cout << x + 1 << " ";
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
