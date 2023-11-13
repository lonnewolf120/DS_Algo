//Contest Link: https://vjudge.net/contest/545084#overview

#include <bits/stdc++.h>

using namespace std;
#define FastIO ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

int main()
{
	FastIO
	int t,c=0; cin >> t;
	while(t--)
	{
		int n,x; cin >> n; vector<int> a; 
		unordered_map<int,int> mp;
		for (int i = 0; i < n; ++i) 
		{
			cin >> x;a.push_back(x); 
			mp[x]++;
		}
		
		for (int i = 0; i < n; ++i) 
		{
			if(mp.at(a[i]) > 1)
			{
				++c; 
				a.erase(a.begin()+i);
				mp[a[i]]--;
			}
		}
		cout << c << "\n";
	}
	return 0;
}