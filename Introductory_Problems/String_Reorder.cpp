#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'A']++;
    }

    string ans;
    ans.reserve(n);

    char previous = '#';

    for (int pos = 0; pos < n; pos++) {

        for (int c = 0; c < 26; c++) {

            if (freq[c] == 0)
                continue;

            if (previous == char('A' + c))
                continue;

            freq[c]--;

            int remaining = n - pos - 1;

            int maxFreq = 0;

            for (int x = 0; x < 26; x++) {
                maxFreq = max(maxFreq, freq[x]);
            }

            if (maxFreq <= (remaining + 1) / 2) {

                ans += char('A' + c);
                previous = char('A' + c);

                break;
            }

            freq[c]++;
        }

        if ((int)ans.size() != pos + 1) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << ans << '\n';
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}