#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, s, e) for (ll i = s; i <= e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define eb emplace_back
#define INF (1LL << 30)
#define LW                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                  \
    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define tst ll t; cin >> t; while (t--)

void print_lcs(vector<vector<char>> &steps, string a, string b, ll n, ll m)
{
    vector<char> v;
    ll i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (steps[i][j] == 'D')
        {
            v.pb(a[i - 1]);
            i--;
            j--;
        }
        else if (steps[i][j] == 'U')
        {
            i--;
        }
        else if (steps[i][j] == 'L')
        {
            j--;
        }
        // else continue;
    }
    cout << "LCS Length: " << v.size() << ln;
    reverse(all(v));
    for (char i : v)
        cout << i;
    cout << ln;
}

ll dp[1000][1000];

void LCS_tabular_and_print(string a, string b, ll n, ll m)
{
    vector<vector<char>> steps(n + 1, vector<char>(m + 1, 'N'));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                steps[i][j] = 'D';
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i][j - 1];
                    steps[i][j] = 'L';
                }
                else if (dp[i][j - 1] < dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j];
                    steps[i][j] = 'U';
                }
                else
                    steps[i][j] = 'N';
            }
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
            cout << steps[i][j] << " ";
        cout << ln;
    }
    print_lcs(steps, a, b, n, m);
}

//Top-Down or Memoization
ll LCS(ll i, ll j,string a, string b)
{
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]=='\0' || b[j]=='\0') return 0;
    if(a[i]==b[j]) return dp[i][j]=1+LCS(i+1,j+1,a,b);
    return dp[i][j]=max(LCS(i,j+1,a,b),LCS(i+1,j,a,b));
}

/*
Notice the main difference:
Recursive or TopDown method goes from top-down hence i-1,j-1
but for BottomUP/Tabular method we do +

The Tabular method allows to easily print the lcs (which is harder in recursive one)
*/
int main()
{
    LW;
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    memset(dp,-1,sizeof(dp));
    cout<<LCS(0,0,a,b)<<ln;
    // LCS_tabular_and_print(a,b,n,m);
    return 0;
}
