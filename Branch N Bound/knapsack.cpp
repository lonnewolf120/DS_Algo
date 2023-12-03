#include<bits/stdc++.h>
using namespace std;

struct item{
    int wt,profit;
};
struct node{
    int wt,profit,level,ub;
};
bool compareRatio(item a,item b){
    return (double)a.profit/a.wt>(double)b.profit/b.wt;
}

int main(){
    int n,W;
    cin>>n>>W;
    vector<item> v;
    for(int i=0;i<n;i++){
        int w;cin>>w;
        int p;cin>>p;
        v.push_back({w,p});
    }
    sort(v.begin(),v.end(),compareRatio);

    queue<node> q;
    node root={0,0,0,0};
    int max_profit=0;
    //ub = vi + (W-wi)*(Vi-1/wi-1)
    root.ub=root.profit+(W-root.wt)*(double)v[root.level].profit/v[root.level].wt;

    q.push(root);

    while(!q.empty()){

        node k=q.front();q.pop();

        if(k.level==n) continue;  //final level reached so traverse others
        
        node child = {//node = wt, profit, level, ub
            k.wt+v[k.level].wt,
            k.profit+v[k.level].profit,
            k.level+1,
            k.ub};

        child.ub = child.profit + (W-child.wt)*(double)v[child.level].profit/v[child.level].wt;

        if(child.wt<=W && child.profit>max_profit)
            max_profit=child.profit;

        if(child.ub>max_profit)
            q.push(child);

        child = {k.wt,k.profit,k.level+1,k.ub};

        child.ub = child.profit+(W-child.wt)*(double)v[child.level].profit/v[child.level].wt;

        if(child.ub > max_profit)
            q.push(child);
    }

    cout<<max_profit<<endl;

    return 0;
}

/*
5 10
3 50
2 40
5 60
3 30
10 100
*/