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
#define MOD 1000000007
#define INF 1e14
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
typedef int ll;
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
// solutions are easy just find patterns
// if you struck for loooong think new approach stop thinking about old one 
// think dp logic more clearly and make proper state
 
struct SegTree {
    int n;
    vector<int> tree;
    
    SegTree(int size){
        n = size;
        tree.resize(4 * n);
    }
    
    void build(int idx , int l , int r , vector<int> &a) {
        if(l == r){
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx , l , mid , a);
        build(2 * idx + 1 , mid + 1 , r , a);
        tree[idx] = tree[idx * 2] ^ tree[idx * 2 + 1];
    }
    
    void update(int idx , int l , int r , int pos , int val) {
        if(l == r){
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid){
            update(idx * 2 , l , mid , pos , val);
        }else{
            update(idx * 2 + 1 , mid + 1 , r , pos , val);
        }
        tree[idx] = tree[idx * 2] ^ tree[idx * 2 + 1];
    }
    
    int query(int idx , int l , int r , int ql , int qr) {
        if(l > qr || r < ql){
            return 0;
        }
        if(ql <= l && r <= qr){
            return tree[idx];
        }
        int mid = (l + r) / 2;
        return query(2 * idx , l , mid , ql , qr) ^ query(2 * idx + 1 , mid + 1 , r , ql , qr);
    }
};
 
void solve() {
    int n , q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
    }
    SegTree st(n);
    st.build(1 , 0 , n - 1 , a);
    
    for(int i = 0 ;i < q ; i++){
       int l , r;
       cin >> l >> r;
       cout << st.query(1 , 0 , n - 1 , l - 1 , r - 1) << nline;
    }
}
int32_t main() {
    fastio();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
