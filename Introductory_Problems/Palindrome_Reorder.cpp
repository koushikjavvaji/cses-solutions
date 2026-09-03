#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    map<char , int>mp;
    for(int i = 0 ; i < n ; i++){
        mp[s[i]]++;
    }
    int cnt = 0;
    string x = "";
    for(auto it : mp){
        if(it.second & 1){
            cnt++;
        }else{
            for(int i = 1 ; i <= (it.second) / 2 ; i++){
                x += it.first; 
            }
        }
    }
    if(cnt > 1){
        cout << "NO SOLUTION" << endl;
    }else{
        string temp = x;
        reverse(temp.begin() , temp.end());
        for(auto it : mp){
        if(it.second & 1){
            for(int i = 1 ; i <= (it.second) ; i++){
                x += it.first; 
            }
         }
        }
        x += temp;
        cout << x << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}