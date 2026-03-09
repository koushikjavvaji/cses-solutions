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
#define int long long
#define INF 1000000002
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

struct SegTree{
    int n;
    vector<int>tree , indi;
    SegTree(int size , vector<int>&x){
        n = size;
        tree.resize(4 * n , 0);
        indi.resize(4 * n , 0);
        build(1 , 0 , n - 1 , x);
    }
    void build(int idx , int l , int r , vector<int>&x){
        if(l == r){
            tree[idx] = x[l];
            indi[idx] = l;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx , l , mid , x);
        build(2 * idx + 1 , mid + 1 , r , x);
        if(tree[2 * idx] >= tree[2 * idx + 1]){
            tree[idx] = tree[2 * idx];
            indi[idx] = indi[2 * idx];
        }else{
            tree[idx] = tree[2 * idx + 1];
            indi[idx] = indi[2 * idx + 1];
        }
    }
    pii query(int idx , int l , int r , int ql , int qr){
        if(l > qr || r < ql) return {-LLONG_MAX, -1};
        if(ql <= l && r <= qr) return {tree[idx] , indi[idx]};
        int mid = (l + r) / 2;
        pii left = query(2 * idx , l , mid , ql , qr);
        pii right = query(2 * idx + 1 , mid + 1 , r , ql , qr);
        
        if(left.ff == -LLONG_MAX) return right;
        if(right.ff == -LLONG_MAX) return left;

        if(left.ff == right.ff)
            return {left.ff, min(left.ss, right.ss)};
        if(left.ff > right.ff)
            return left;
        return right;
    }
};

void solve(){
    int n , q;
    cin >> n >> q;
    vector<int>a(n);
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
    }
    vector<int>nxt(n , n);
    stack<int>st;
    
    for(int i = n - 1 ; i >= 0 ; i--){
        while(!st.empty() && (a[st.top()] <= a[i])){
            st.pop();
        }
        
        if(!st.empty()){
            nxt[i] = st.top();
        }
        st.push(i);
    }
    
    vector<int>suff(n , 0);
    
    for(int i = n - 1 ; i >= 0 ; i--){
        if(nxt[i] != n){
            suff[i] = a[i] * (nxt[i] - i) + suff[nxt[i]];
        }else{
            suff[i] = a[i] * (nxt[i] - i);
        }
    }
    
    vector<int>pref(n , 0);
    pref[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        pref[i] = pref[i - 1] + a[i];
    }
    
    SegTree stree(n , a);
    
    for(int i = 0 ; i < q; i ++){
        int a , b;
        cin >> a >> b;
        
        a--; b--;
        
        pii maxi = stree.query(1 , 0 , n - 1 , a , b);
        int prefMaxSum = 0 , prefSum = 0;
        
        prefMaxSum = suff[a] - suff[maxi.ss];
        prefMaxSum += ((b - maxi.ss + 1) * maxi.ff);
        
        if(a == 0){
            prefSum = pref[b];
        }else{
            prefSum = pref[b] - pref[a - 1];
        }
        
        cout << prefMaxSum - prefSum << nline;
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
