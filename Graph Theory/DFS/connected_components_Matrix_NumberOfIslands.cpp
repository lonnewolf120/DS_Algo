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
    static const int N=305;
    bool b[N][N];
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size(); //as this is a square matrix
        if(i<0 || j<0 || i>=n || j>=m || b[i][j] || grid[i][j]=='0') return;
        
        b[i][j] = 1;

        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        for(int i=0; i < grid.size(); ++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(!b[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    ++c;
                }
            }
        }
        return c;
    }
};

int main()
{
    Solution solve;
    vector<vector<char>> grid;
    int n,m; char c;
    cin >> n >>m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    cout << solve.numIslands(grid);
}