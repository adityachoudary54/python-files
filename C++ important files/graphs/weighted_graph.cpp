#include<iostream>
#include<list>
#include<set>
using namespace std;
class Graph
{
	int V;
	list<pair<int,int>> *l;
public:
	Graph(int v)
	{
		V=v;
		l=new list< pair<int,int> >[V];
	}
	void addEdge(int u,int v,int w,bool bidir=true)
	{
		l[u].push_back(make_pair(v,w));
		if(bidir)
        	l[v].push_back(make_pair(u,w));
	}
	void printAdjList()
	{
		for(int it=0;it<V;it++)
		{
			cout<<it<<"->";
			for(auto neighbour=l[it].begin();neighbour!=l[it].end();neighbour++)
			{
				cout<<neighbour->first<<","<<neighbour->second<<"  ";
			}
			cout<<endl;
		}
	}

	void dijkstra(int src)
	{
		int *dist=new int[V];
		for(int i=0;i<V;i++)
		{
			dist[i]=INT_MAX;
		}
		set<pair<int,int>> s;
		dist[src]=0;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			auto it=s.begin();
			int parent=it->second;
			int parentDist=it->first;
			s.erase(it);
			for(auto j=l[parent].begin();j!=l[parent].end();j++)
			{
				if(parentDist+j->second<dist[j->first])
				{
					int oldDist=dist[j->first];
					auto f=s.find(make_pair(oldDist,j->first));//This is done when a given node recurs in the path it is removed and then updated.
					if(f!=s.end())
					{
						s.erase(f);
					}
					dist[j->first]=parentDist+j->second;
					s.insert(make_pair(dist[j->first],j->first));
				}
			}
		}
		for(int i=0;i<V;i++)
		{
			cout<<i<<" "<<dist[i]<<endl;
		}
	}
};
int main()
{
	Graph g(6);
	//cout<<"hello";
	g.addEdge(0,1,1);
	g.addEdge(0,4,6);
	g.addEdge(4,1,3);
	g.addEdge(1,2,4);
	g.addEdge(4,2,1);
	g.addEdge(4,5,7);
	g.addEdge(5,3,2);
	g.addEdge(2,3,3);
	g.dijkstra(0);
	g.printAdjList();
}