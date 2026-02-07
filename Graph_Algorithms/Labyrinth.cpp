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
#define MOD 998244353
#define MOD1 1000000007LL 
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
// PIGEON - HOLE PRINCIPLE 
// DO NOT USE GPT (DEBUG YOURSELF)
// TRY TO PROVE INSTEAD OF GUESSING IT
// READ >>>>>>> WATCH
// CONTRIBUTION
int dx[4] = {0 , 0 , 1 , -1};
int dy[4] = {1 , -1 , 0 , 0};
void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<char>>grid(n , vector<char>(m));
    pair<int , int>start , end;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ;j < m ; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                start.ff = i;
                start.ss = j;
            }
            if(grid[i][j] == 'B'){
                end.ff = i;
                end.ss = j;
            }
        }
    }
    vector<vector<int>>vis(n , vector<int>(m , 0));
    vector<vector<char>>ans(n , vector<char>(m , '#'));
    queue<pair<int , int>>qu;
    qu.push({start.ff , start.ss});
    vis[start.ff][start.ss] = 1;
    while(!qu.empty()){
        auto curr = qu.front();
        qu.pop();
        if (curr == end) break;
        for(int i = 0 ;i < 4 ; i++){
            int nx = curr.ff + dx[i];
            int ny = curr.ss + dy[i];
            
            if((nx >= 0 && nx < n) && (ny >= 0 && ny < m) && (grid[nx][ny] != '#') && !vis[nx][ny]){
                vis[nx][ny] = 1;
                qu.push({nx , ny});
                if(i == 0){
                    ans[nx][ny] = 'R';
                }else if(i == 1){
                    ans[nx][ny] = 'L';
                }else if(i == 2){
                    ans[nx][ny] = 'D';
                }else{
                    ans[nx][ny] = 'U';
                }
            }
        }
    }
    debug(vis);
    debug(ans);
    if(vis[end.ff][end.ss]){
        string path;
    int x = end.ff, y = end.ss;
    while(make_pair(x, y) != start){
        char d = ans[x][y];
        path += d;
        if(d == 'R') y -= 1;
        else if(d == 'L') y += 1;
        else if(d == 'D') x -= 1;
        else if(d == 'U') x += 1;
    }
    reverse(all(path));
 
    cout << "YES" << nline;
    cout << path.size() << nline;
    cout << path << nline;
    }else{
        cout << "NO" << nline;
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
