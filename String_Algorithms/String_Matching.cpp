#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
int KadaneAlgorithm(const vector<int>& array) {
    int best = 0, sum = 0;
    for (int k = 0; k < array.size(); k++) {
        sum = max(array[k], sum + array[k]);
        best = max(best, sum);
    }
    return best;
}
const int MOD = 1000000007;
const int BASE1 = 5689;
const int BASE2 = 8861;
 
struct Hash {
    vector<pair<int, int>> Hashvalues, Powers;
    Hash(string &s) {
        Hashvalues.assign(s.size() + 1, {1, 1});
        Powers.assign(s.size() + 1, {1, 1});
        for (int i = 0; i < (int)(s.size()); i++) {
            Hashvalues[i + 1] = { (1ll * Hashvalues[i].first * BASE1 + ((s[i] - 'a') + 1)) % MOD, ( 1ll * Hashvalues[i].second * BASE2 + ((s[i] - 'a') + 1)) % MOD };
            Powers[i + 1] = {(1ll * Powers[i].first * BASE1) % MOD, (1ll * Powers[i].second * BASE2) % MOD};
        }
    }
    pair<int, int> Query(int l, int r) {
        l++, r++;
        int hash1 = (Hashvalues[r].first - (1ll * Hashvalues[l - 1].first * Powers[r - l + 1].first) % MOD + MOD) % MOD;
        int hash2 = (Hashvalues[r].second - (1ll * Hashvalues[l - 1].second * Powers[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    cin >> s1;
    cin >> s2;
    int m = s2.size();
    int n = s1.size();
    Hash ash1(s1),ash2(s2);
    ll cnt = 0;    
    for(int i = 0 ;i + m - 1< n; i++)
    {
        if(ash1.Query(i,i+m-1) == ash2.Query(0,m-1))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
