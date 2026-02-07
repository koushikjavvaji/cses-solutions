/*
*************************************************
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
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {-1 , 1 , 0 , 0};
void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<char>>grid(n , vector<char>(m));
    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j < m ;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>>edges((n * m) + 1);
    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j < m ;j++){
            int idx = i * m + j + 1;
            for(int k = 0 ;k < 4 ; k++){
                int ind1 = i + dx[k];
                int ind2 = j + dy[k];
                if((ind1 >= 0) && (ind1 < n) && (ind2 >= 0) && (ind2 < m)){
                    if(grid[ind1][ind2] != '#' && (grid[i][j] != '#')){
                        int neighborIdx = ind1 * m + ind2 + 1;
                        edges[(idx)].push_back(neighborIdx);
                        edges[neighborIdx].push_back(idx);
                    }
                }
            }
        }
    }
    vector<int>vis((n * m) + 1 , 0);
    function<void(int)> f = [&](int curr) -> void {
        vis[curr] = 1;
        for(auto it : edges[curr]){
            if(!vis[it]){
                f(it);
            }
        }
    };
    debug(edges);
    int res = 0;
    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j < m ;j++){
            int idx = i * m + j + 1;
            if(!vis[idx] && (grid[i][j] != '#')){
                res++;
                f(idx);
            }
        }
    }
    cout << res << nline;
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
