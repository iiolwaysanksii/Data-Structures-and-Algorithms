/*
Implement DFS on a directed Graph without Starting and Finishing time
*/
#include<iostream>
#include<list>          //helps in making adjacency list
using namespace std;

class Graph{
	int V;  //No. of vertices
	bool *visited;		//to keep track of visited and non-visited nodes
	list<int> *adj;     // Pointer that points to a list of integer type....remember it's dynamic

	public:
	
		Graph(int V){
				this->V=V;
				adj= new list<int>[V];		// <- an array of lists
				visited = new bool[V];
			}
		
		void addEdge(int x, int y){ 
			adj[x].push_back(y); // Add y to x’s list. 
		}  
  
		void DFS(){	

			for (int i = 0; i < V; ++i)
			visited[i]=false;					

			for (int i=0 ; i < V; ++i)
				if(!visited[i])
					DFSVISIT(i);		//call DFS_Visit on every i where visited is false
		}  

		void DFSVISIT(int v){
			
			visited[v]=true;
			cout <<v <<" ";

			list<int>::iterator i;

			for (i = adj[v].begin(); i != adj[v].end(); ++i)		//i scans the adjacency list of v until all vertex are visited
				if(!visited[*i])
					DFSVISIT(*i);


		}
};



int main(int argc, char const *argv[])
{	
	int v,e,edge;	

	/*
	v-->Number of vertices
	e-->Number of edges
	edge-->edge between two vertices
	*/
	
	cout<<"Enter Number of vertices........\n";
	cin>>v;
	Graph ob(v);

	for (int i = 0; i < v; ++i)
	{
		cout<<"\nNo. of vertices vetiice("<<i<<") is connected to"<<" : ";
		cin>>e;
		cout<<"\nEnter the vertices : \n";
		
		for (int j = 0; j < e; ++j)
		{
			cin>>edge;
			ob.addEdge(i,edge);		
		}
	}
 	
	cout << "\n\nFollowing is Breadth First Traversal: "; 
	ob.DFS();

	return 0;
}