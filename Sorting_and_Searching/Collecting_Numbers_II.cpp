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
ll mod_sub(ll a, ll b, ll m) { a %= m; b %= m; return (a - b + m) % m; }
ll mod_mul(ll a, ll b, ll m) {return (a % m * (b % m)) % m;}
ll mod_expo(ll a, ll b, ll m) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res; }
bool revsort(ll a, ll b) { return a > b; }
vector<ll> sieve(int n) { vector<bool> is_prime(n+1, true); vector<ll> primes; for (ll i = 2; i <= n; i++) { if (is_prime[i]) { primes.push_back(i); for (ll j = i * i; j <= n; j += i) if(j<=n) is_prime[j] = false; } } return primes; }
 
/************************************************
*               Main Function                   *
*************************************************/
void solve(){
    int n , m;
    cin >> n >> m;
    vi a(n);
    for(int i = 0 ;i < n ; i++){
        cin >> a[i];
    }
    map<int , int>mp;
    vector<int>pos(n + 1 , 0);
    int res = 1;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(pos[a[i] - 1] != 0) res++;
        pos[a[i]] = i + 1;
    }
    
    for(int i = 0 ; i < m ; i++){
        int a1 , b1;
        cin >> a1 >> b1;
        a1--; 
        b1--;
    
        int val1 = a[a1] , val2 = a[b1];
    
        set<int> s;
        s.insert(val1);
        s.insert(val2);
        s.insert(val1 - 1);
        s.insert(val2 - 1);
    
        for(auto x : s){
            if(x >= 1 && x < n){
                if(pos[x] > pos[x + 1]) res--;
            }
        }
    
        swap(a[a1] , a[b1]);
    
        pos[val1] = b1 + 1;
        pos[val2] = a1 + 1;
        
        for(auto x : s){
            if(x >= 1 && x < n){
                if(pos[x] > pos[x + 1]) res++;
            }
        }
    
        cout << res << nline;
    }
}
 
int32_t main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
