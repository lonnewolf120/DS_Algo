
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

void reverseQueue(deque<ll> &q)
{
	if(q.empty()) return;

	ll m = q.front();
	q.pop_front();
	reverseQueue(q);
	q.push_back(m);
}
void solve()
{
	deque<ll> q; bool f=true;
	ll n,x; cin >> n;
	while(n--)
	{
		string s; cin >> s;
	if(f)
	{
		if(s[0]=='t')
		{
			cin >> x;
			q.push_front(x);
		}
		else if(s[0]=='p')
		{
			cin >> x;
			q.push_back(x);
		}
		else if(s[0]=='f')
		{
			if(q.size())
			{
				cout << q.front() << ln;
				q.pop_front();
			}
			else cout << "No job for Ada?\n";
		}
		else if(s[0]=='b')
		{
			if(q.size())
			{
				cout << q.back() << ln;
				q.pop_back();
			}
			else cout << "No job for Ada?\n";
		}
		else
		{
			f=false;
		}
	}
	else //just do opposite
	{
		if(s[0]=='t')
		{
			cin >> x;
			q.push_back(x);
		}
		else if(s[0]=='p')
		{
			cin >> x;
			q.push_front(x);
		}
		else if(s[0]=='f')
		{
			if(q.size())
			{
				cout << q.back() << ln;
				q.pop_back();
			}
			else cout << "No job for Ada?\n";
		}
		else if(s[0]=='b')
		{
			if(q.size())
			{
				cout << q.front() << ln;
				q.pop_front();
			}
			else cout << "No job for Ada?\n";
		}
		else
		{
			f=true;
		}
	}
	}
}
int main()
{
    fastio
    solve();
    return 0;
}