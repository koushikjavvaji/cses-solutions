#include <iostream>
#include <vector>
#include <string>
#include <map> // Include map header
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
 
int checker(ll mid, string s, Hash &ash, string &duplicate) {
    ll n = s.length();
    map<pair<ll, ll>, ll> mp;
    for (int i = 0; i <= n - mid; i++) {
        pair<ll, ll> pac = ash.Query(i, i + mid - 1);
        mp[pac]++;
        if (mp[pac] > 1) {
            duplicate = s.substr(i, mid); // Store the duplicate substring
            return i;
        }
    }
    return -1;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    Hash ash(s);
    ll n = s.length();
    ll left = 1;
    ll right = n - 1;
    ll ans = -1;
    string longest_duplicate;
    while (left <= right) {
        ll mid = (left + right) / 2;
        string duplicate;
        int idx = checker(mid, s, ash, duplicate); // Store the result of checker and the duplicate substring
        if (idx != -1) {
            ans = idx;
            longest_duplicate = duplicate; // Update the longest duplicate substring
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!longest_duplicate.empty()) {
        cout << longest_duplicate << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
