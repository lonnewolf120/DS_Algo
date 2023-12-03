
#include <bits/stdc++.h>
using namespace std;
   
typedef long long ll;
typedef long double ld;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"

#define int long long
struct item{
    int profit, wt;
};

struct node
{
// public:
    int wt, profit, level, ub;
};

bool cmp(item a, item b)
{
    return (double)a.profit/a.wt>(double)b.profit/b.wt;
}

int32_t main()
{
    fastio
    
    int n,W;
    cin>>n>>W;
    vector<item> v;
    for(int i=0;i<n;i++){ 
        int w;cin>>w;
        int p;cin>>p;
        v.push_back({w,p});
    }
    sort(v.begin(),v.end(),cmp);
    queue<node> q;

    int maxProfit = 0;
    node root = {0,0,0,0};
    root.ub=root.profit+(W-root.wt)*(double)v[root.level].profit/v[root.level].wt;
    cout<<"ROOT UB: "<<root.ub<<ln;
    q.push(root);
    while(!q.empty())
    {
        node top = q.front(); q.pop();

        if(top.level == n) break; //exit condition

////TAKE
        node take = {
            top.wt + v[top.level].wt,
            top.profit + v[top.level].profit,
            top.level+1,
            top.ub
        };
        take.ub = take.profit + (W-take.wt)*(double)v[take.level].profit/v[take.level].wt;
        if(take.profit > maxProfit && take.wt<=W)
            maxProfit = take.profit;
        if(take.ub > maxProfit) q.push(take);

////NOT TAKE
        node not_take =
        {
            top.wt,
            top.profit,
            top.level+1,
            top.ub
        };
        not_take.ub = not_take.profit + (W-not_take.wt)*(double)v[not_take.level].profit/v[not_take.level].wt;
        
        if(not_take.ub > maxProfit) q.push(not_take);

    }
    cout<<maxProfit<<ln;


    return 0;
}