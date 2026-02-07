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
// cm
 
struct SegTree{
    int n;
    vector<int>tree;
    SegTree(int size , vector<int>&a){
        n = size;
        tree.resize(4 * n , 0);
        build(1 , 0 , n - 1 , a);
    }
    void build(int idx , int l , int r , vector<int>&a){
        if(l == r){
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx , l , mid , a);
        build(2 * idx + 1 , mid + 1 , r , a);
        tree[idx] = min(tree[2 * idx] , tree[2 * idx + 1]);
    }    
    void update(int idx , int l , int r , int pos, int val , int sign){
        if(l == r){
            if(sign == 1) tree[idx] = val - (pos + 1);
            else tree[idx] = val + (pos + 1);
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid){
            update(2 * idx , l , mid , pos , val , sign);
        }else{
            update(2 * idx + 1 , mid + 1 , r , pos , val , sign);
        }
        tree[idx] = min(tree[2 * idx] , tree[2 * idx + 1]);
    }
    
    int query(int idx , int l , int r , int ql , int qr){
        if(l > qr || r < ql) return LLONG_MAX;
        if(ql <= l && r <= qr){
            return tree[idx];
        }
        int mid = (l + r) / 2;
        int left = query(2 * idx , l , mid , ql , qr);
        int right = query(2 * idx + 1 , mid + 1 , r , ql , qr);
        return min(left , right);
    }
};
void solve() {
    int n , q;
    cin >> n >> q;
    vector<int>a(n) , t1(n) , t2(n);
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
        t1[i] = a[i] - (i + 1);
        t2[i] = a[i] + (i + 1);
    }
    SegTree st1(n , t1) , st2(n , t2);
    for(int i = 0 ; i < q ; i++){
        int x;
        cin >> x;
        if(x == 1){
            int k , u;
            cin >> k >> u;
            st1.update(1 , 0 , n - 1 , k - 1 , u , 1);
            st2.update(1 , 0 , n - 1 , k - 1 , u , 2);
        }else{
            int k;
            cin >> k;
            int ans1 = st1.query(1 , 0 , n - 1 , 0 , k - 1);
            int ans2 = st2.query(1 , 0 , n - 1 , k - 1 , n - 1);
            cout << min(ans1 + k, ans2 - k) << nline;
        }
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
