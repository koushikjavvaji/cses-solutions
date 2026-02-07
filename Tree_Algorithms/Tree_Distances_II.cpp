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
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
/************************************************
*               Main Function                   *
*************************************************/
int answer = 0;
int n;
void dfs1(int curr , vector<vector<int>>&edges , int parent ,
 vector<int>&level ,vector<int>&subtreeSize , int currLevel)
{
    answer += currLevel;
    // cout << answer << " " << nline;
    subtreeSize[curr] = 1;
    for(auto neighbours : edges[curr])
    {
        if(neighbours != parent)
        {
            dfs1(neighbours , edges , curr , level , subtreeSize , currLevel + 1);
            subtreeSize[curr] += subtreeSize[neighbours];
            
        }
    }
}
void dfs2(int curr , vector<vector<int>>&edges , int parent , 
    int answer , vector<int>&subtreeSize , vector<int>&result)
{
    result[curr] = answer;
    for(auto neighbours : edges[curr])
    {
        if(neighbours != parent)
        {
            dfs2(neighbours , edges , curr , (answer + n) - (2 * subtreeSize[neighbours]) , subtreeSize , result);
        }
    }
}
void solve() {
    cin >> n;
    vector<vector<int>>edges(n);
    vector<int>level(n) ,subtreeSize(n);
    vector<int> result(n , 0);
    int currLevel = 0;
    for(int i = 0 ;i < (n - 1) ;i++)
    {
        int u , v;
        cin >> u >> v;
        u--;v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs1(0 , edges , -1 , level , subtreeSize , currLevel);
    // cout << answer << nline;
    dfs2(0 , edges , -1 , answer , subtreeSize , result);
    for(int i = 0 ;i < n ;i++)
    {
        cout << result[i] << " ";
    }
    cout << nline;
}
 
int32_t main() {
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
