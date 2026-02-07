#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
 
ll ispossible(int n, ll mid)
{
 
	int cnt = 0;
	ll cnt2 = 0;
	ll cnt3 = 0;
 
	REP(i, 1, n)
	{
		ll temp = mid / i;
		if (min(temp * 1ll * i, n * 1ll * i) == mid)
		{
			cnt++;
		}
 
		ll ani = mid / i;
		if (mid % i == 0)
		{
			ani--;
		}
		if (n < ani)
		{
			cnt2 += n;
		}
		else
		{
			cnt2 += ani;
		}
	}
	if (cnt == 0) cnt = 1;
	REP(i, 1, n)
	{
		ll ani = mid / i;
		if (n < ani)
		{
			cnt3 += 0;
		}
		else
		{
			cnt3 = cnt3 + (n - ani);
		}
	}
	if (cnt3 > cnt2)
	{
		if ((cnt3 - cnt2) <= (cnt - 1))
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (cnt3 < cnt2)
	{
		if ((cnt2 - cnt3) <= (cnt - 1))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	if (cnt3 == cnt2)
	{
		if (cnt3 % 2 == 0)
		{
			if (cnt % 2 != 0)
			{
				return 1;
			}
		}
		else
		{
			if (cnt % 2 == 0)
			{
				return 1;
			}
		}
	}
 
	return -1;
 
}
int32_t main() {
 
	int n;
	cin >> n;
	ll lo = 1;
	ll hi = n * 1ll * n;
	ll res = 0;
 
	while (lo <= hi)
	{
		ll mid = lo + (hi - lo) / 2;
		ll nay = ispossible(n, mid);
		// cout << lo << " " << mid << " " << hi << " " << nay << endl;
		if (nay == 1)
		{
			res  = mid;
			break;
		}
		else if (nay == 2)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
 
	}
	cout << res << endl;
	return 0;
}
