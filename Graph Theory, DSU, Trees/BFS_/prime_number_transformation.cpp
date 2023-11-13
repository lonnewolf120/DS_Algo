#include <bits/stdc++.h>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
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
#define yes cout << "YES\n"
#define no cout << "NO\n"

vector<ll> prm[1000];
void prime(int n)
{
    int tmp=n;
    int add=0;
    //iterate through every number to see if it's divisible 
    for(int div=2; tmp>1; div++)
    {
        add=0;
        //while tmp is divisible by div keep dividing and store the number
        while(tmp%div==0)
        {
            add=div;
            tmp/=div;
        }
        if( add )	
            prm[n].pb(add); //pb add to n
    }
    if(add == n)
        prm[n].clear();
}

/*
6 --> 2,3
8 --> 2
9 --> 3
10 --> 2,5
12 --> 2,3
*/
ll bfs(ll n, ll m)
{
    int level[1001]={0};
	queue<ll> q;
	q.push(n);
	//level[n]=0;

	while(!q.empty())
	{
		ll p = q.front();
		q.pop();
		//visited[p]=1;

		for(auto i:prm[p])
		{
            ll node=p+i;
			if(node<=m && level[node]==0)
			{
				//visited[i]=true;
				level[node]=level[p]+1;
				// cout<< node <<" "<<level[node]<<ln;
                if(prm[node].empty()) continue;
                q.push(node);
            if(node==m)
                return level[node];
			}
		}
	}
    return -1;
}


int main()
{
    fastio
    //Generate prime factor for all numbers from 2 to 1000
    forsn(i,1,1000)
       	prime(i);
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
        // map<ll,ll> level;
     //cout << "Case " << it << ": ";
        ll n,m; cin >> n >> m;

        cout<<"Case "<<it<<": ";
        cout<<bfs(n,m);
        // forsn(i,2,50)
        // {
        // 	if(!prm[i].empty())
        // 	{
        // 	cout<<i<<":\n";
        // 	for(auto j:prm[i])
        // 		cout<<j<<" ";
        // 	}
        // 	cout<<ln;
        // }
    }
    return 0;
}