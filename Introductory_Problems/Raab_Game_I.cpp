#include <iostream>
using namespace std;
 
#define int long long
 
/*
 
    1 2 3 4
    2 3 1 4
 
 
 
    1 2 3 4 5 6 7 8
    2 3 4 5 6 7 8 1 - 7 1
    3 4 5 6 7 8 1 2 - 6 2
    4 5 6 7 8 1 2 3 - 5 3
    5 6 7 8 1 2 3 4 - 4 4
    6 7 8 1 2 3 4 5 - 3 5
    7 8 1 2 3 4 5 6 - 2 6
    8 1 2 3 4 5 6 7 - 1 7
 
*/
void solve(){
    int n , a , b;
    cin >> n >> a >> b;
 
    if(a == 0 && b == 0){
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
        return;
    }else if(a == 0 || b == 0 || (a + b) > n){
        cout << "NO\n";
        return;
    }else if((a + b) > n){
        cout << "NO\n";
        return;
    }else{
        int new_n = a + b;
 
        if(new_n < 0){
            cout << "NO\n";
            return;
        }else{
            cout << "YES\n";
            for(int i = 1 ; i <= a; i++){
                cout << new_n - (a - 1) + (i - 1) << " ";
            }
 
            for(int i = a + 1 ; i <= new_n; i++){
                cout << i - a << " ";
            }
 
            for(int i = new_n + 1 ; i <= n ; i++){
                cout << i << " ";
            }
 
            cout << "\n";
 
            for(int i = 1 ;i <= n ; i++){
                cout << i << " ";
            }
 
            cout << "\n";
        }
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1; 
    cin >> t;
    while (t--) solve();
}
