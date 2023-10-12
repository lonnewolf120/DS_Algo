
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


int main()
{
    //fastio
    ll n; 
    while(cin>>n)
    {
    	stack<ll> st;
		queue<ll> q;
		priority_queue<ll> pq;
		bool s=true,qt=true,pqq=true;
		forn(i,n)
		{
			ll x,y; cin >> x >> y;
			if(x==1)
			{
				st.push(y); q.push(y); pq.push(y);
			}
			else
			{
				if(s)
				{
					if(st.empty() || st.top()!=y)s=false;
					else st.pop(); 
				}
				if(qt)
				{
					if(q.empty() || q.front()!=y)qt=false;
					else q.pop();
				}
				if(pqq)
				{
					if(pq.empty() || pq.top()!=y)pqq=false;
					else pq.pop();
				}
			}
			
		}
		if(!s && !qt && pqq) cout << "priority queue\n";
		else if(!s && qt && !pqq) cout << "queue\n";
		else if(s && !qt && !pqq) cout << "stack\n";
		else if(s || qt || pqq) cout << "not sure\n";
    	else cout << "impossible\n";
    }

   	
    return 0;
}