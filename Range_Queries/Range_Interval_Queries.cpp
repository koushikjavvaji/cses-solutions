/*
*************************************************
*               Koushik's Template              *
*          Om namho Venkatesaya                 *
*************************************************
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

/************************************************
*                 Macros                        *
*************************************************/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 998244353
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
// #define int long long
/************************************************
*                 Typedefs                      *
*************************************************/
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;


// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/************************************************
*             Utility Functions                 *
*************************************************/
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m) { a %= m; b %= m; return (a + b) % m; }
ll mod_sub(ll a, ll b, ll m) { a %= m; b %= m; return (a - b + m) % m; }
ll mod_mul(ll a, ll b, ll m) {return (a % m * (b % m)) % m;}
ll mod_expo(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
bool revsort(ll a, ll b) { return a > b; }
vector<ll> sieve(int n) { vector<bool> is_prime(n+1, true); vector<ll> primes; for (ll i = 2; i <= n; i++) { if (is_prime[i]) { primes.push_back(i); for (ll j = i * i; j <= n; j += i) if(j<=n) is_prime[j] = false; } } return primes; }

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
// cm
const int N = 2e5;
int n , a[N];
vector<int>seg[4 * N];

void build(int node , int start , int end){
    
    if(start == end){
        seg[node].pb(a[start]);
        return;
    }
    
    int mid = (start + end) / 2;
    
    build(2 * node , start , mid);
    build(2 * node + 1 , mid + 1 , end);
    
    seg[node].reserve(seg[2 * node].size() + seg[2 * node + 1].size());
    merge(seg[2 * node].begin() , seg[2 * node].end() , seg[2 * node + 1].begin() , seg[2 * node + 1].end() , back_inserter(seg[node]));
}

int query(int node, int l, int r, int ql, int qr, int lo, int hi) {
    if (qr < l || r < ql) return 0;

    if (ql <= l && r <= qr) {
        return upper_bound(seg[node].begin(), seg[node].end(), hi)
             - lower_bound(seg[node].begin(), seg[node].end(), lo);
    }

    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, ql, qr, lo, hi)
         + query(node << 1 | 1, mid + 1, r, ql, qr, lo, hi);
}

void solve() {
    int q;
    cin >> n >> q;
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 4 * n; i++) seg[i].clear();

    build(1 , 0 , n - 1);
    
    while(q--){
        int a , b , c , d;
        cin >> a >> b >> c >> d;
        a--; b--;
        cout << query(1, 0, n - 1, a , b, c, d) << nline;
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
