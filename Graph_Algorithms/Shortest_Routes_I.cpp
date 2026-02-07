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
*               Main Function                   *
*************************************************/
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {-1 , 1 , 0 , 0};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> edges(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 0-based indexing
        edges[u].pb({v, w});
    }
 
    vector<int> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap priority queue
    pq.push({0, 0}); // (distance, node)
 
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        int u = curr.ss, d = curr.ff;
 
        // If current distance is greater than the best known distance, skip
        if (d > dist[u]) continue;
 
        // Relax all neighbors
        for(auto &it : edges[u]) {
            int v = it.ff, w = it.ss;
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
 
    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << nline;
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
