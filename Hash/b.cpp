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

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
          int n ;cin>>n;
          vector<int>ans;
          long long int sum =0;
          int co =0;
          for(int  i=0;i<n;i++){
               int x;
               cin>>x;
               if(x==1)
               co++;
               
               sum+=x;
               ans.push_back(x);
               
               
          }
          if(sum-n>=co && n!=1)
          cout<<"YES"<<endl;
          else
          cout<<"NO"<<endl;
     }
     return 0;
}