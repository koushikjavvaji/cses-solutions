#include<bits/stdc++.h>
using namespace std;
 
long long binaryExponentiation(long long x, long long y, long long mod)
{
    long long answer = 1; 
 
    while(y)
    {
        if(y&1) answer*=x; answer%=mod;
 
        x*=x; x%=mod;
        y >>= 1; 
    }
 
    return answer%mod;
}
 
int main()
{
    int tt; cin >> tt;
 
    while(tt--)
    {
        long long x,y,z; cin >> x >> y >> z; 
        y = binaryExponentiation(y,z, 1e9 + 6);
        cout << binaryExponentiation(x,y, 1e9 +7) << "\n";
    }
}
