#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()




    vector<int> resultArray(vector<int>& nums) {
        vector<int>res;
        int c=0,c1=0;
        vector<int> arr1,arr2;
        for (int i = 0; i < nums.size(); ++i)
        {
                cout<<nums[i]<<endl;
        }
        for (int i = 0; i < nums.size(); )
        {
            cout<<nums[i]<<" "<<nums[++i]<<endl;
            arr1.push_back(nums[i]);
            arr1.push_back(nums[++i]);
            ++c, ++c1,++i;
            if(arr1[c]>arr2[c1])
            {
                arr1.push_back(nums[i]);
                ++c;
            }
            else
            {
                arr2.push_back(nums[i]);
                ++c1;
            }
            
        }
        for (auto i:arr1)
        {
            res.push_back(i);
        }
        for (auto i:arr2)
        {
            res.push_back(i);
        }
        return res;
    }
int32_t main()
{
    // LW;
    // tst
    // {
    vector<int> nums ={2,1,3};
    vector<int>res;
        int c=0,c1=0;
        vector<int> arr1,arr2;

        for (int i = 0; i < nums.size(); )
        {
            arr1.push_back(nums[i]); ++i;
            arr1.push_back(nums[i]);
            ++c, ++c1,++i;
            if(arr1[c]>arr2[c1])
            {
                cout<<nums[c]<<endl;
                arr1.push_back(nums[i]);
                ++c;
            }
            else
            {
                cout<<nums[c]<<endl;
                arr2.push_back(nums[i]);
                ++c1;
            }
            
        }
        for (auto i:arr1)
        {
            cout<<i<<endl;
            res.push_back(i);
        }
        for (auto i:arr2)
        {
            cout<<i<<endl;
            res.push_back(i);
        }
    // for(auto i:res) cout<<i<<" ";
    //     cout<<endl;
    // res = sol.resultArray(v);
    // for(auto i:res) cout<<i<<" ";
    //     cout<<ln;
    	//ll n; cin>>n; vector<ll> v(n); for(auto &i:v) cin>>i;
    // }
    // }
    return 0;
}