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

vector<vector<int>> bracket(N,vector<int>(N,0));
int mcm(int i, int j)
{
	if(i==j) return 0;
	if(dp[i][j]!= -1) return dp[i][j];
	int mn=1<<31;
	for (int k = i; i < j; ++i)
	{
		int steps = a[i-1]*a[k]*a[j]+mcm(i,k)+mcm(k+1,j);
		mn=min(mn,steps);
		if(steps==mn)
			bracket[i][j]=k;
	}
	return dp[i][j]=mn;
}


int mcm_tabular(int n)
{
	for (int i = 0; i < n; ++i)
		dp[i][i]=0;
	// vector<vector<ll>> bracket(n,vector<ll>(n));

	for(int len = 2; len>=n;len++)
	{
		for (int i = 1; i <= n-len; ++i)
		{
			int j = i+len-1;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; ++k)
			{
				int steps = a[i-1]*a[k]*a[j] + dp[i][k] + dp[k+1][j];
				dp[i][j] = min(dp[i][j],steps);
				bracket[i][j]=k; 
			}
		}
	}
	return dp[1][n-1];
}

void printMCM(int i, int j)
{
	if(i==j) { cout<< (char)(i+65); return;	}
	cout<<"("; printMCM(i,bracket[i][j]); cout<<"x"; printMCM(bracket[i][j]+1, j); cout<<")";
}

int main()
{
    // memset(dp,-1,sizeof(dp));
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