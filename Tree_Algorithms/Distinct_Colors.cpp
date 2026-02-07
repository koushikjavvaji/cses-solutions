/************************************************
*               Koushik's Template              *
*************************************************/
 
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
 
void dfs(int curr, vector<vector<int>>& edges, int parent, 
    vector<set<int>>& distinctColors, vector<int>& arr, vector<int>& result)
{
    distinctColors[curr].insert(arr[curr]); // Insert current node color into its set
    
    for(auto neighbours : edges[curr])
    {
        if(neighbours != parent)
        {
            dfs(neighbours, edges, curr, distinctColors, arr, result); // Pass 'result' as an argument
            if(distinctColors[curr].size() < distinctColors[neighbours].size()) // Compare set sizes
            {
                swap(distinctColors[curr], distinctColors[neighbours]);
            }
            for(auto it : distinctColors[neighbours])
            {
                distinctColors[curr].insert(it); // Insert elements correctly
            }
        }
    }
    result[curr] = distinctColors[curr].size(); // Set result for current node
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n); // Array of colors for each node
    vector<set<int>> distinctColors(n); // Vector of sets to store distinct colors for each node
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    vector<vector<int>> edges(n); // Adjacency list for the tree
    vector<int> result(n, 0); // Vector to store the result
    
    for(int i = 0; i < (n - 1); i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert 1-based index to 0-based
        edges[u].pb(v);
        edges[v].pb(u);
    }
    
    dfs(0, edges, -1, distinctColors, arr, result); // Start DFS from node 0, assuming it's the root
    
    for(int i = 0; i < n; i++)
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

