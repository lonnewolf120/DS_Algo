#include <bits/stdc++.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define ln "\n"
#define pb push_back
#define fi first

const int N=10e3;
int dp[N][N];
vector<int> a ={10,20,30,40,50};
int mcm(int i, int j)
{
	if(i==j) return 0;
	if(dp[i][j]!= -1) return dp[i][j];
	int mn=1<<31;
	for (int k = i; i < j; ++i)
	{
		int steps = a[i-1]*a[k]*a[j]+mcm(i,k)+mcm(k+1,j);
		mn=min(mn,steps);
	}
	return dp[i][j]=mn;
}

int mcm_tabular(int n)
{
	for (int i = 0; i < n; ++i)
		dp[i][i]=0;
	for(int i=n-1; i>=1; --i)
	{
		for(int j=i+1;j<=n-1;++j) //always the left partition of i
		{
			dp[i][j]=1<<31;
			for (int k = i; i < j; ++i)
			{
				int steps = a[i-1]*a[k]*a[j]+dp[i][k]+dp[k+1][j];
				dp[i][j]=min(dp[i][j],steps);
			}
		}
	}
	return dp[1][n-1];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    n=a.size();
    // while(n--)
    // {
    // 	ll x; cin>>x; a.push_back(x);
    // }
    // cout<<mcm(1,n-1)<<ln;
    cout<<mcm_tabular(n)<<ln;
    return 0;
}