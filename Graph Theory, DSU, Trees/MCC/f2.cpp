#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define endl "\n"
const int INFI = 1e18;
const int MOD = 1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    // cin.ignore();
    while (t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>v(n);
        int trades=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            trades+=y;
            v[i]={x,y};
        }
        sort(v.begin(),v.end());
        int buy=ceil(trades/2);
        int buy_price=0;
        int cnt=0;
        int flag=0;
        for(int i=0;i<v.size();i++)
        {
            while(v[i].second!=0)
            {
                buy_price+=v[i].first;
                // cout<<"buy:"<<buy_price<<endl;
                cnt++;
                // cout<<"cnt:"<<cnt<<endl;
                v[i].second--;
                // cout<<"it.first it.second:"<<v[i].first<<" "<<v[i].second<<endl;
                if(cnt==buy)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                break;
            }
        }
        int sell_price=0;
        for(const auto it:v)
        {   
        //    cout<<"tradesleft: "<<it.first<<" "<<it.second<<endl; 
           sell_price+=it.first*it.second;
        //    cout<<"sell: "<<sell_price<<endl;
        }
        cout<<sell_price-buy_price<<endl;
    }
    return 0;
}