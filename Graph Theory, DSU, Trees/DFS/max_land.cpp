#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

//Here goes the Solution class;
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size();
        if(i<0 || j<0) return 0;
        if(i>=n || j>=m) return 0;
        if(grid[i][j]==0) return 0;
        
        grid[i][j]=0;
        int l=1;

        l += dfs(i,j-1,grid);
        l += dfs(i,j+1,grid);
        l += dfs(i-1,j,grid);
        l += dfs(i+1,j,grid);
        return l;
    }
    //using memoization
    ll ans[1000][1000];
    int dfs2(int i, int j, vector<vector<int>>& grid)
    {
        int n=grid.size(), m=grid[0].size(),l=1;
        if(ans[i][j]!=0)return ans[i][j];
        if(i<0 || j<0) return 0;
        if(i>=n || j>=m) return 0;
        if(grid[i][j]==0) return 0;

        grid[i][j] = 0;
    
        ans[i][j] = dfs2(i,j-1,grid)+dfs2(i,j+1,grid)+dfs2(i-1,j,grid)+dfs2(i+1,j,grid);
        return ans[i][j];
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c;
        dfs(10,10,grid);
        for(int i=0; i<grid.size();++i)
        {
            for(int j=0; j<grid[0].size();++j)
            {
                if(grid[i][j]!=0) 
                {
                    c=max(c,dfs(i,j,grid));
                }
            }
        }
        cout << *max_element(ans,ans+1000) << endl;
        return c;
    }
};

int main()
{
    fastio
    Solution solve;

    return 0;
}