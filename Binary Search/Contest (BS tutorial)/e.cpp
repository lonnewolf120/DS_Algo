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

int n, m, xc, yc;
bool canReach(int dx, int dy, int steps)
{
    ll new_x = xc+ (dx*steps);
    ll new_y = yc+ (dy*steps);
    return new_x>=0 && new_x < n && new_y >= 0 && new_y < m;
}

int bs(int l, int r, int dx, int dy)
{

    while(l<r)
    {
        int mid = l+(r-l)/2;
        if(canReach(dx,dy,mid)) l = mid;
        else r = mid-1;
    }
    return l;
}
int main() {
    ll n, m,xc,yc,k,steps=0;
    cin >> n >> m >> xc >> yc >> k;
    while (k--)
    {
        ll dx, dy;
        cin >> dx >> dy;
        ll l = 0, r = 1e9;
        ll max_steps = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (xc + dx * mid >= 1 && xc + dx * mid <= n && yc + dy * mid >= 1 && yc + dy * mid <= m)
            {
                l = mid + 1;
                max_steps = mid;
            }
            else
                r = mid - 1;
        }
        xc += dx * max_steps;
        yc += dy * max_steps;
        steps += max_steps;
    }

    cout << steps << ln;
    return 0;
}
