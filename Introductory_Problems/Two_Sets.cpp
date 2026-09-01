#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if(sum & 1){
        cout << "NO" << endl;
    }else{
        vector<int>temp1 , temp2;
        int req = sum / 2;
        for(int i = n ; i >= 1 ; i--){
            if(req > 0){
                if(req >= i){
                    req -= i;
                    temp1.push_back(i);
                }else{
                    temp2.push_back(i);
                }
            }else{
                temp2.push_back(i);
            }
        }
        cout << "YES" << endl;
        cout << temp1.size() << endl;
        for(int i = 0 ;i < temp1.size() ; i++){
            cout << temp1[i] << " ";
        }
        cout << endl;
        cout << temp2.size() << endl;
        for(int i = 0 ;i < temp2.size() ; i++){
            cout << temp2[i] << " ";
        }
        cout << endl;
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