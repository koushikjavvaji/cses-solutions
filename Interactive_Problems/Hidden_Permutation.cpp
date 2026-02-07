/*
*************************************************
*               Koushik's Template              *
*          Om Namho Venkatesaya                 *
*************************************************
*/
 
#include <bits/stdc++.h>
using namespace std;
 
/************************************************
*                 Macros                        *
*************************************************/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD2 1000000007
#define INF 1e9
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
int n;
 
bool compare(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string res;
    cin >> res;
    return res == "YES"; // means a[i] < a[j]
}
void solve() {
    cin >> n;
    
    vector<int> sorted; // stores indices in sorted order
    sorted.push_back(1); // start with first index
 
    for (int i = 2; i <= n; ++i) {
        int lo = 0, hi = sorted.size();
        // Binary search the correct position to insert
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (compare(i, sorted[mid])) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        sorted.insert(sorted.begin() + lo, i);
    }
 
    // Assign values based on position in sorted
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[sorted[i] - 1] = i + 1;
    }
 
    // Output the permutation
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << perm[i] << " ";
    }
    cout << endl;
    cout.flush();
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
