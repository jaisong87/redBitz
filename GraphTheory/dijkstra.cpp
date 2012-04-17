#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define DBG 0
#define INFI (1<<30)

/* A simple graph class that has only dijkstra impl */
/* To avoid a few lines i'm not specifying any comparator to the priority_queue and hence doing a manipulation (negative distances) */
class Graph{
vector<vector<pair<int, int> > > adjList;
int V, E;
bool isDirected;

public:
Graph(int V1, int E1, bool directed)
	{
	V = V1;
	E = E1;
	isDirected = directed;
	vector<pair <int, int> > nullList;
	for(int i=0;i<V;i++)
		adjList.push_back(nullList);
	}

void takeInput()
	{
	int u, v, w;
	for(int e=0;e<E;e++)
		{
			cin>>u>>v>>w;
		if(u>=V || v>=V)
			cout<<"Error! - Invalid node"<<endl;
		else {
			adjList[u].push_back(pair<int, int> (v, w) );
			if(!isDirected) adjList[v].push_back(pair<int, int> (u, w) );
			}
		}
	}

int getShortestPathDistance(int s, int t)
	{
		priority_queue<pair<int,int> > djQueue;
		int* dis = new int[V];
		int* parent = new int[V];
		bool* visited = new bool[V];

		for(int i=0;i<V;i++)
			{
			dis[i] = -1*INFI;
			parent[i] = -1;
			visited[i] = false;
			}	
		
		dis[s] = 0;
		djQueue.push(pair<int, int>(dis[s], s));
		pair<int,int> qtop;
	
		int visitCount = 0;
		while(! djQueue.empty())
				{
				qtop = djQueue.top();
				int curDis = -1*qtop.first;
				int nodeU = qtop.second;
				djQueue.pop();
				if(DBG) cout<<"Popping node#"<<nodeU<<" with dis "<<curDis<<endl;
				if(!visited[nodeU])
						{
						visited[nodeU] = true;
						visitCount++;
						for(int i = 0; i < adjList[nodeU].size(); i++)
								{
								pair<int,int> edge = adjList[nodeU][i];
								int nodeV = edge.first;
								int wtW = edge.second;
								if(!visited[nodeV]  && (-1*dis[nodeV] > wtW + curDis ) )
									{
									dis[nodeV] = -1*(curDis + wtW);
									parent[nodeV] = nodeU;
									djQueue.push(pair<int,int> (dis[nodeV], nodeV)); 
									if(DBG) cout<<"Updating dis["<<nodeV<<"] = "<<-1*dis[nodeV]<<endl;
									}
								}
						}
				}
	int minDis = -1*dis[t];
	cout<<s<<" - "<<t<<" => "<<-1*dis[t]<<endl;

if(DBG)
	{
	for(int i=0;i<V;i++)
		cout<<-1*dis[i]<<" ";
	cout<<endl;
	}

	if(minDis == INFI) minDis = -1;
	delete[] dis;
	delete[] parent;
	delete[] visited;
	
	return minDis;
	}
};

/* 
 * This program computer single pair shortest path for s-t in a graph G(V, E)
 * First line of input is V , E 
 * E lines follow with ( u, v, w  ) triples where w is the weight of edge
 * Then enter ( s , t ) to calculate distance from s to t
 * The problem assumes undirected graph 
 */
int main()
{
int V, E;
cin>>V>>E;
bool isDirected = false;
Graph g1 = Graph(V, E, isDirected);

g1.takeInput();

cout<<"Enter s-t pair "<<endl;
int s, t;
cin>>s>>t;
cout<<g1.getShortestPathDistance(s, t)<<endl;

return 0;
} 

