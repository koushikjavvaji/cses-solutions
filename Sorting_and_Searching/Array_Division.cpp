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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
bool ispossible(vector<long long>&arr,long long k,long long max_sum)
{
   int subarr_count = 0;
	ll cur_sum = 0;
 
	for (const int &x : arr) {
		if (x > max_sum) { return false; }
 
		if (cur_sum + x > max_sum) {
			subarr_count++;
			cur_sum = 0;
		}
		cur_sum += x;
	}
	if (cur_sum > 0) { subarr_count++; }
 
	return subarr_count <= k;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    vi x(n);
    REP(i,0,n-1)
    {
        cin >> x[i];
    }
    ll lo = 1;
    ll hi = 1e18;
    ll res = 0;
    while(lo < hi)
    {
         
        ll mid = (lo + hi)/2;
        //cout << lo << " " << mid <<" "<<hi << endl;
        if(ispossible(x,k,mid))
        {
            res  = mid;
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
       
    }
    cout << res << endl;
    return 0;
}

