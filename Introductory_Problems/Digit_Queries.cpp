#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
#define int long long
 
void solve(){
    int k;
    cin >> k;

    int digits = 1;
    int count = 9;
    int start = 1;

    while (k > digits * count) {
        k -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    int number = start + (k - 1) / digits;

    int index = (k - 1) % digits;

    string numStr = to_string(number);

    cout << numStr[index] << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; 
    cin >> t;
    while (t--) solve();
}