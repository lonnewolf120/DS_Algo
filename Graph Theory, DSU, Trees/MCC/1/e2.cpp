#include <bits/stdc++.h>
// #include <C:\D Drive\Projects\Tutorials\Graph Theory\MCC\1\debug2.h>
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


// global variables
map<char,set<char>> g;
map<char,bool> visited;
string ans="";
// functions
void dfs(char src) {
    visited[src]=1;

    ans+=src;

    for(auto j:g[src]) {

        if(!visited[j])dfs(j);
    }

}
int main()
{
    fastio
    ll t; cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();

        for(int i=0; i<n-1; i++) {

            g[s[i]].insert(s[i+1]);
            g[s[i+1]].insert(s[i]);
        }

        bool f=true;
        int cnt=0,start=s[0];
        for(char i='a'; i<='z'; i++) {
            if(g[i].size()==1)cnt++,start=i;
            else if(g[i].size()>2)f=false;
        }
        if(cnt!=2)cnt=0;
        if(cnt==0&&n>1)
        {
            cout<<"NO\n";
            for(int i=0; i<200; i++)
            g[i].clear();
            continue;
        }
        cout<<"YES\n";

        visited.clear();
        ans="";
        dfs(start);

        for(char i='a'; i<='z'; i++) {
            if(!visited[i])ans+=i;
        }
        cout<<ans<<ln;
        for(int i=0; i<200; i++)
            g[i].clear();
    }
    return 0;
}


                                                                