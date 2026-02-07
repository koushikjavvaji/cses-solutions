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
#include <unordered_map>
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
template <typename T>
std::istream &operator>>(std::istream &in, std::vector<T> &v){
    for (int i = 0; i < v.size(); i++){
        in >> v[i];
    }
    return in;
}
 
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
    for (int i = 0; i < v.size(); ++i){
        os << v[i] << ' ';
    }
    os << endl;
    return os;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin >> n >> m >> k;
    vi a(n),b(m);
    REP(i,0,n-1)
    {
        cin >> a[i];
    }
    REP(i,0,m-1)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll temp = 0;
    ll res = 0;
    ll low = 0,high = m - 1;
    REP(i,0,n-1)
    {
        ll ans  = 0;
        ll applicant = a[i];
        high = m-1;
        ll req = a[i] - k;
         ans = -1;
        while(low <= high)
        {
            ll mid = (low + high)/2;
            if(b[mid] >= req)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        if(b[ans] >= (a[i] - k) && b[ans] <= (a[i] + k))
        {
           // cout << ans << endl;
            res++;
            low = ans + 1;
        }
    }
    cout << res << endl;
    return 0;
}

