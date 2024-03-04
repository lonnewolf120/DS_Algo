#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ln "\n"

void solve()
{
    ll n, c = 1;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {

            if (v[i][j] == 0)
            {
                if ((i > 0 && j > 0 && v[i - 1][j] == 0 && v[i][j - 1] == 0) && (v[i + 1][j] == 0 && v[i][j + 1] == 0 && i < n - 1 && j < n - 1))
                {
                    v[i][j] = c;
                    c = (c == 1) ? 2 : 1;
                }
                else if (i == 0 && v[i][j + 1] == 0 && v[i + 1][j] == 0)
                {
                    v[i][j] = c;
                    c = (c == 1) ? 2 : 1;
                }
                else if (j == 0 && v[i + 1][j] == 0 && v[i][j + 1] == 0)
                {
                    v[i][j] = c;
                    c = (c == 1) ? 2 : 1;
                }
                else if (i == n - 1 && v[i][j - 1] == 0 && v[i + 1][j] == 0)
                {
                    v[i][j] = c;
                    c = (c == 1) ? 2 : 1;
                }
                else if (j == n - 1 && v[i - 1][j] == 0 && v[i][j - 1] == 0)
                {
                    v[i][j] = c;
                    c = (c == 1) ? 2 : 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << ln;
    }
}

int main()
{
    // fastio
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}
