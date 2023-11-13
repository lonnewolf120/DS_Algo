#include<bits/stdc++.h>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#define ll long long int
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    ll t,n,q,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n+1],mx=INT_MAX,b[n+1];
        for(i=1;i<=n;i++)
        {
            cin>>a[i];

        }
            for(i=1;i<=n;i++)
            {
                q=a[i];
                if(q!=i)
                {
                    mx=min(mx,abs(q-a[q]));
                }
            }
        cout<<mx<<'\n';
    }
    return 0;
}