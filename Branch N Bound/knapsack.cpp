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
    //ub = vi + (W-wi)*(Vi+1/wi+1)
    root.ub=root.profit+(W-root.wt)*(double)v[root.level].profit/v[root.level].wt;

    q.push(root);

    while(!q.empty()){

        node k=q.front();q.pop();

        if(k.level==n) continue;  //final level reached so traverse others
        
 ////TAKE       
        node take = {
            k.wt+v[k.level].wt,     //weight = prev-weight + weight-next-elem
            k.profit+v[k.level].profit,     //profit = prev-profit + profit-next-elem
            k.level+1,  //level increase by 1
            k.ub};  //ub

        // ub = vi + (W-wi)*(Vi+1/wi+1), [here take's level is increased by one, so it is referring to the next elem]
        take.ub = take.profit + (W-take.wt)*(double)v[take.level].profit/v[take.level].wt;

        if(take.profit>max_profit and take.wt<=W) //make it max only if it's valid
            max_profit=take.profit;

        if(take.ub>max_profit)     //if greater element found push it for further iteration on that node
            q.push(take);
        
 ////NOT-TAKE
        node not_take = {
            k.wt,
            k.profit,
            k.level+1,
            k.ub};

        not_take.ub = not_take.profit+(W-not_take.wt)*(double)v[not_take.level].profit/v[not_take.level].wt;

        if(not_take.ub > max_profit)
            q.push(not_take);
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