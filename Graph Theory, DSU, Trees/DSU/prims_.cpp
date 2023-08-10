#include <bits/stdc++.h>
using namespace std;
#define inf 2e9
const int N = 1e3 + 5;

vector<pair<int,int>> adj[N];
pair<int,int> parent[N];
int weight[N];
bool visited[N];
void prims(int n,int src=1)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i <= n; ++i)
	{
		visited[i]=false;
		weight[i]=inf;
	}
	int wt=0;
	pq.push({0,src});
	parent[src]={src,0};
	weight[src]=0;

	while(!pq.empty())
	{
		int node=pq.top().second;
		pq.pop();
		
		if(visited[node]) continue;
		visited[node]=true;

		for (auto child:adj[node])
		{
			int childNode=child.first;
			int childWt=child.second;
			
			if(!visited[childNode] && childWt<weight[childNode])
			{
				weight[childNode]=childWt;
				parent[childNode] = {node,childWt};
				pq.push({childWt,childNode});
			}
		}

	}

	//return wt;
}


int main(int argc, char const *argv[])
{
	int edges; cin >>edges;
	for (int i = 0; i < edges; ++i)
	{
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	prims(edges);
	for (int i = 1; i <= edges; ++i)
	{
		if(parent[i].first!=i)
		cout << i << " " << parent[i].first << " " << parent[i].second << endl;
	}
	return 0;
}
