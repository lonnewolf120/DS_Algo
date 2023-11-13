#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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

const int cs=26;
class Trie
{
public:
	int EoW;
	Trie* children[cs];
	Trie()
	{
		EoW=0;
		for (int i = 0; i < cs; ++i)
		{
			this->children[i]=NULL;
		}
	}
};
Trie* root=NULL;
void insert(string a)
{
	Trie* tmp=root;
	for (char c:a)
	{
		int ind;
		(c>='a' && c<='z')? ind=c-'a': ind=c-'A';
		if(tmp->children[ind]==NULL)
			tmp->children[ind]=new Trie();
		tmp=tmp->children[ind];
	}
}
bool search_all(string a)
{
	Trie* tmp=root;
	for (int i = 0; i < a.size(); ++i)
	{
		int ind;
		(a[i]>='a' && a[i]<='z')? ind=a[i]-'a': ind=a[i]-'A';
		if(i!=a.size() && tmp->children[ind]==NULL)
		{
			cout<<"String present: ";
			for (int j = 0; j <= i; ++j)
			{
				cout<<a[j];
				/* code */
			}
			return false;

		}
		tmp=tmp->children[ind];
	}
	if(tmp->EoW) return true;
}
void print(Trie* r)
{

}
int main()
{
    fastio
    // ll t;
    // cin >> t;
    // for(int it=1;it<=t;it++) {
    //  //cout << "Case " << it << ": ";
    //     solve();
    // }
    return 0;
}