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
void dfs(int curr , vector<vector<int>>&edges , int parentNode , vector<vector<int>>&parent)
{
    parent[0][curr] = parentNode;
    for(auto neighbour : edges[curr])
    {
        if(neighbour != parentNode)
        {
            dfs(neighbour , edges , curr , parent);
        }
    }
}
int findkParent(int x , int k , vector<vector<int>>&parent , int maxN)
{
    for(int i = 0 ;i < maxN ; i++)
    {
        if(k & (1 << i))
        {
            x = parent[i][x];
            if(x == -1)
            {
                return x;
            }
        }
    }
    return x;
}
void solve() {
    int n , q;
    cin >> n >> q;
    vector<vector<int>>edges(n);
   int maxN = log2(n) + 5;
   vector<vector<int>>parent(maxN , vector<int> (n , -1));
    for(int i = 1 ;i < (n) ; i++)
    {
        int u;
        cin >> u;
        u--;
        edges[u].pb(i);
        edges[i].pb(u);
    }
    dfs(0 , edges , -1 ,parent);
    for(int i = 1 ;i < maxN ;i++)
    {
        for(int j = 0 ;j < n ;j++)
        {
            int temp = parent[i - 1][j];
            if(temp != -1)
            {
            parent[i][j] = parent[i - 1][temp];
            }
        }
    }
    // for(int i = 0 ; i < maxN ; i++)
    // {
    //     for(int j = 0 ;j < n ; j++)
    //     {
    //         cout << parent[i][j] << " ";
    //     }
    //     cout << nline;
    // }
    while(q--)
    {
        int x , k;
        cin >> x >> k;
        x--;
        int ans = findkParent(x, k , parent , maxN);
        if(ans != -1)
        {
         cout << ans + 1<< nline;
        }
        else
        {
            cout << -1 << nline;
        }
    }
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

