/**************************************************
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
    int n, m;
    cin >> n >> m;
    pii start;
    queue<pii>pq , pqA;
    vector<vector<int>>timer(n , vector<int> (m , INT_MAX));
    vector<vector<int>>timerA(n , vector<int> (m , INT_MAX));
    vector<vector<char>> grid(n , vector<char> (m));
    for(int i = 0 ;i < n ;i++){
        for(int j = 0 ;j < m ;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                start = {i , j};
                timerA[i][j] = 0;
            }
            if(grid[i][j] == 'M') {
                pq.push({i , j});
                timer[i][j] = 0;
            }
        }
    }
    vector<vector<int>>vis(n , vector<int> (m , 0));
    vector<vector<int>>visA(n , vector<int> (m , 0));
    vector<vector<pii>>parent(n , vector<pii> (m , {-1 , -1}));
    pii top = pq.front();
    vis[top.ff][top.ss] = 1;
    while(!pq.empty()){
        pii curr = pq.front();
        pq.pop();
        for(int i = 0 ;i < 4 ; i++){
            int nx = curr.ff + dx[i];
            int ny = curr.ss + dy[i];
            if((nx >= 0 && (nx < n)) && ( ny >= 0 && (ny < m))){
                if(grid[nx][ny] != '#'){
                    if(!vis[nx][ny]){
                        vis[nx][ny] = 1;
                        timer[nx][ny] = min(timer[nx][ny] , timer[curr.ff][curr.ss] + 1);
                        pq.push({nx , ny});
                    }
                }
            }
        }
    }
    pqA.push({start.ff , start.ss});
    visA[start.ff][start.ss] = 1;
    while(!pqA.empty()){
         pii curr = pqA.front();
         pqA.pop();
         for(int i = 0 ;i < 4 ; i++){
             int nx = curr.ff + dx[i];
             int ny = curr.ss + dy[i];
             if((nx >= 0 && (nx < n)) && ( ny >= 0 && (ny < m))){
                 if(grid[nx][ny] != '#'){
                     if(!visA[nx][ny]){
                         visA[nx][ny] = 1;
                         parent[nx][ny] = {curr.ff , curr.ss};
                         timerA[nx][ny] = min(timerA[nx][ny] , timerA[curr.ff][curr.ss] + 1);
                         pqA.push({nx , ny});
                     }
                 }
             }
         }
     }
     debug(timer);
     debug(timerA);
     int flag = 0;
     pii dest;
     for (int i = 0; i < n; i++) {
        if (grid[i][m - 1] != '#' && timer[i][m - 1] > timerA[i][m - 1]) {
            flag = 1;
            dest = {i, m - 1};
            break;
        }
        if (grid[i][0] != '#' && timer[i][0] > timerA[i][0]) {
            flag = 1;
            dest = {i, 0};
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (grid[n - 1][i] != '#' && timer[n - 1][i] > timerA[n - 1][i]) {
            flag = 1;
            dest = {n - 1, i};
            break;
        }
        if (grid[0][i] != '#' && timer[0][i] > timerA[0][i]) {
            flag = 1;
            dest = {0, i};
            break;
        }
    }
    debug(dest);
    debug(flag);
     if(flag){
        cout << "YES" << nline;
       vector<char>res;
       pii curr = dest;
       while(curr != start){
        pii par = parent[curr.ff][curr.ss];
        if(par.ff > curr.ff){
            res.pb('U');
        }
        else if(par.ff < curr.ff){
            res.pb('D');
        }
        else if(par.ss > curr.ss){
            res.pb('L');
        }
        else{
            res.pb('R');
        }
        curr = par;
       }
       reverse(res.begin(),res.end());
       cout << res.size() << nline;
       for(int i = 0 ;i < res.size() ; i++){
        cout << res[i];
       }
       cout << nline;
     }
     else{
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
