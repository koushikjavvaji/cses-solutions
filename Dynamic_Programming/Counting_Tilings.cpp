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
 
void solve() {
    // Your code goes here
    int n , m;
    cin >> n >> m;
    vector<vector<int>>transitions((1 << n));
     function<void(int, int, int)> generate = [&](int index, int mask1, int mask2) {
        if(index > n)
        {
            return;
        }
        if (index == n) { 
            transitions[mask1].pb(mask2);
            return;
        }
        generate(index + 1, mask1 | (1 << index), mask2);  
        generate(index + 1, mask1, mask2 | (1 << index));  
        generate(index + 2, mask1, mask2); 
    };
 
    generate(0, 0, 0);
    
    vector<vector<int>>dp(m , vector<int> (1 << n , -1));
    
    function<int(int, int)> f = [&](int index, int mask) -> int {
    if (index == m) {
        return (mask == 0 ? 1 : 0);
    }
    if (dp[index][mask] != -1) {
        return dp[index][mask];
    }
    int answer = 0;
    for (auto &newmask : transitions[mask]) {
        answer = (answer + f(index + 1, newmask)) % MOD;
    }
    return dp[index][mask] = answer;
};
 
 
    cout << f(0,0) << nline;
    
}
 
int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
