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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> p(n);
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 0 ;i < n ;i++)
    {
        cin >>p[i];
    }
    sort(p.begin(),p.end());
    if(n % 2 == 0)
    {
        ll temp1 = p[n/2];
        ll temp2 = p[n/2 - 1];
        for(int i = 0 ;i < n ;i++)
        {
            sum1 += abs(temp1 - p[i]);
            sum2 += abs(temp2 - p[i]);
        }
        cout << min(sum1,sum2) << endl;
    }
    else
    {
        ll nay = p[n/2];
        for(int i = 0 ;i < n ;i++)
        {
            sum1 += abs(nay - p[i]);
        }
        cout << sum1 << endl;
    }
    return 0;
}

