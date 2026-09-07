#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve(){
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
    vector<pair<int , int>> steps;
    for(int i = 1; i <= n; i++){
        if(steps.size() == 0){
            steps.push_back({1 , 3});
        }else{
            vector<pair<int , int>> new_steps;
            for(auto step : steps){
                int first , second;
                if(step.first == 1){
                    first = 1;
                }else if(step.first == 2){
                    first = 3;
                }else{
                    first = 2;
                }
                if(step.second == 1){
                    second = 1;
                }else if(step.second == 2){
                    second = 3;
                }else{
                    second = 2;
                }
                new_steps.push_back({first , second});
            }
            new_steps.push_back({1 , 3});
            for(auto step : steps){
                int first , second;
                if(step.first == 1){
                    first = 2;
                }else if(step.first == 2){
                    first = 1;
                }else{
                    first = 3; 
                }
                if(step.second == 1){
                    second = 2;
                }else if(step.second == 2){
                    second = 1;
                }else{
                    second = 3;
                }
                new_steps.push_back({first , second});
            }
            steps = new_steps;
        }
    }
    for(auto step : steps){
        cout << step.first << " " << step.second << endl;
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