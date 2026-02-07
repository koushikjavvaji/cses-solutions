#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define BASE1 5689
#define BASE2 8861
 
struct Hash {
    vector<pair<ll, ll>> Hashvalues, Powers;
    Hash(string &s) {
        Hashvalues.assign(s.size() + 1, {1, 1});
        Powers.assign(s.size() + 1, {1, 1});
        for (int i = 0; i < (int)(s.size()); i++) {
            Hashvalues[i + 1] = { 
                (1ll * Hashvalues[i].first * BASE1 + ((s[i] - 'a') + 1)) % MOD,
                (1ll * Hashvalues[i].second * BASE2 + ((s[i] - 'a') + 1)) % MOD
            };
            Powers[i + 1] = {
                (1ll * Powers[i].first * BASE1) % MOD,
                (1ll * Powers[i].second * BASE2) % MOD
            };
        }
    }
    pair<ll, ll> Query(int l, int r) {
        l++, r++;
        ll hash1 = (Hashvalues[r].first - (1ll * Hashvalues[l - 1].first * Powers[r - l + 1].first) % MOD + MOD) % MOD;
        ll hash2 = (Hashvalues[r].second - (1ll * Hashvalues[l - 1].second * Powers[r - l + 1].second) % MOD + MOD) % MOD;
        return {hash1, hash2};
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    Hash ash(s);
    int n = s.length();
    for (int i = 0; i < n; i++) {
 
		int curidx = 0;
 
		bool ok = true;
 
		while (curidx < n) {
 
			int len = min(i + 1, n - curidx);
 
			ok &= ash.Query(0, len - 1) == ash.Query(curidx, curidx + len - 1);
 
			curidx += len;
 
		}
 
		if (ok) { cout << i + 1 << " "; }
 
	}
    return 0;
}
