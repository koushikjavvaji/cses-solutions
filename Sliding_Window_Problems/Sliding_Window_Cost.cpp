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
struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        if (a.first == b.first)
            return a.second > b.second; 
        return a.first < b.first;      
    }
};
void solve(){
    int n , k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0 ;i < n ; i++){
        cin >> arr[i];
    }
    if (k == 1){
        for(int i = 0 ;i < n ; i++){
            cout << 0 << " ";
        }
        cout << nline;
        return;
    }
    multiset<int> low, high;
    int sumLow = 0 , sumHigh = 0;
    auto balance = [&]() {
        while ((int)low.size() > (int)high.size() + 1){
            int val = *low.rbegin();
            low.erase(low.find(val));
            sumLow -= val;

            high.insert(val);
            sumHigh += val;
        }
        while ((int)low.size() < (int)high.size()){
            int val = *high.begin();
            high.erase(high.begin());
            sumHigh -= val;

            low.insert(val);
            sumLow += val;
        }
    };  
    for (int i = 0 ;i < n ; i++){
        if (i >= k) {
            if (low.find(arr[i - k]) != low.end()) {
                low.erase(low.find(arr[i - k]));
                sumLow -= arr[i - k];
            } else {
                auto it = high.find(arr[i - k]);
                if (it != high.end()) {
                    high.erase(it);
                    sumHigh -= arr[i - k];
                }
            }
            balance();
        }
        
        if (low.empty() || arr[i] <= *low.rbegin()){
            low.insert(arr[i]);    
            sumLow += arr[i];
        } else{
            high.insert(arr[i]);
            sumHigh += arr[i];
        }
        balance();
        if (i >= k - 1) {
            int median = *low.rbegin();

            int cost = median * (int)low.size() - sumLow+ sumHigh - median * (int)high.size();

            cout << cost << " ";
        }
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
