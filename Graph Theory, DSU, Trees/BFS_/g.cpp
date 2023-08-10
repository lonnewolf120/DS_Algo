#include <bits/stdc++.h>
using namespace std;
//#include "debug.h"
#define int long long
#define float long double
#define endl "\n"
const int INFI = 1e18;
const int MOD = 1e9 + 7;

bool check(vector<vector<int>> &grid, int n, int m, int h, int w)
{
    int total = 0;
    vector<vector<int>> pase(n, vector<int>(m)), niche(n, vector<int>(m));
    ;
    for (int i = 0; i < n; i++)
    {
        bool f = true;
        for (int j = 0; j < m; j++)
        {
            total += grid[i][j];
            if (f)
            {
                pase[i][j] = grid[i][j], f = false;
            }
            else
                pase[i][j] = grid[i][j] + pase[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << pase[i][j] << " ";
        cout << endl;
    }
    if (total <= 0)
        return false;
    for (int i = 0; i < n - h; i++)
    {
        int sub_sum = 0, temp;
        for (int j = 0; j < m - w; j++)
        {
            if (j - w - 1 >= 0)
                temp = (pase[i][j + w - 1] - pase[i][j - w - 1]);
            else
                temp = pase[i][j + w - 1];
            //debug(temp);
            sub_sum += temp;
            if (sub_sum >= 0)
            {
                return false;
            }
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    // cin.ignore();
    while (t--)
    {
        int n, m, h, w;
        cin >> n >> m >> h >> w;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        if (check(grid, n, m, h, w))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}