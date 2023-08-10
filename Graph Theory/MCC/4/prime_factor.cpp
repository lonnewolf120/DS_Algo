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

#define MAXN 100001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		// checking if i is prime
		if (spf[i] == i) {
			// marking SPF for all numbers divisible by i
			for (int j = i * i; j < MAXN; j += i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step

#//Replace Set with vector to get all prime factors-->
set<int> getFactorization(int x)
{
	set<int> ret;
	while (x != 1) {
		ret.insert(spf[x]);
		x = x / spf[x];
	}
	return ret;
}

// driver program for above function
int main(int argc, char const* argv[])
{
	// precalculating Smallest Prime Factor
	sieve();
	
	// calling getFactorization function
	set<int> p[1000];
	forsn(i,2,1000)
	 	p[i]=getFactorization(i);

	forsn(i,1,1000)
	{
		if(p[i].empty()) continue;
		cout<<i<<":\n";
		for(auto j:p[i])
			cout<<j<<" ";
		cout<<ln;
	}
	
	return 0;
}
