#include <bits/stdc++.h>
 
using namespace std;
const int MOD = 1e9+7;
const int MX = 1e6+1;
long long dp[MX];
long long fact(int n)
{
    if(dp[n]!=0)
        return dp[n];
    dp[n]=(1ll*n*fact(n-1))%MOD;
    return dp[n];
}
long long binpow(long long a, long long b)
{
    long long ans=1;
    while(b>0)
    {
        if((b&1)>0)
        {
            ans=(ans*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
long long inv(long long a)
{
    long long res = binpow(a,MOD-2);
    return res;
}
long long calc(int a, int b)
{
    long long num, den,tot;
    num=fact(a);
    den=(fact(a-b)*fact(b))%MOD;
    tot=(num*inv(den))%MOD;
    return tot;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    dp[0]=1;
    dp[1]=1;
    int n, a, b, i;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a >> b;
        cout << calc(a,b) << '\n';
    }
    return 0;
}