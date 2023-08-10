# Breadth-First Search (BFS)

in BFS, we’ll traverse in levels/breadth first. The below circled ones are the same levels. So, after finishing a level we’ll go to next levels, regardless of how many there are in the same level. 

![BFS.gif](Breadth-First%20Search%20(BFS)%20cf4a351ab471419b82b38bd08cd735d3/BFS.gif)

![Untitled.png](Breadth-First%20Search%20(BFS)%20cf4a351ab471419b82b38bd08cd735d3/Untitled.png)

![Untitled](Breadth-First%20Search%20(BFS)%20cf4a351ab471419b82b38bd08cd735d3/Untitled%201.png)

[https://www.youtube.com/watch?v=M8jdDR5kV3k](https://www.youtube.com/watch?v=M8jdDR5kV3k)

So, we’ll pass all the children in a level at once, process each of those node, so we need to work with First-In First-out principle, that’s why we’ll need :

[Queue](https://www.notion.so/Queue-0974c49bf3d34a4793c9a48fbe94db1a?pvs=21)

And Before marking them, we’ll add their children to the queue as well, and continue.

### BFS Implementation

![Untitled](Breadth-First%20Search%20(BFS)%20cf4a351ab471419b82b38bd08cd735d3/Untitled%202.png)

![BFS.gif](Breadth-First%20Search%20(BFS)%20cf4a351ab471419b82b38bd08cd735d3/BFS%201.gif)

```cpp
const int N=1e3+10;
bool visited[N];
int level[N];
int parent[N];
vector<int> g[N];
void bfs(int source)
{
	queue<int> q;
	q.push(source);
	visited[source] = true;
//extra parts
	parent[source] = -1;
	while(!q.empty())
	{
		int cur_v = q.front();
		q.pop();
		for(auto child:g[cur_v])
		{
			if(!visited[child])
			{
				q.push(child);
				visited[child]=true;
				//storing the levels & parents of nodes
				level[child]= level[cur_v]+1;
				parent[child] = cur_v;
			}
		}
	}
}
```

[BFS problems](Breadth-First%20Search%20(BFS)%20cf4a351ab471419b82b38bd08cd735d3/BFS%20problems%208e5b3661bca64b929e73780e00aadaa4.csv)