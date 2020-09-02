/*
Implement BFS on a directed Graph
*/
#include<iostream>
#include<list>          //helps in making adjacency list
using namespace std;

class Graph{
	
	int V;  //No. of vertices
	bool *visited;	//to keep track of visited and non-visited nodes
	list<int> *adj;     // Pointer that points to a list of integer type....remember it's dynamic

	public:
		
		Graph(int V){
				this->V = V;
				adj = new list<int>[V];		// <- an array of lists
				visited = new bool[V];
			}
		
		void addEdge(int x, int y){ 
			adj[x].push_back(y); // Add y to x’s list. 
		}  
  
		void BFS(int s){

			for (int i = 0; i < V; ++i)			//for every vertex set the visited to false
				visited[i] = false;
			
			list<int> queue;	//queue for bfs

			visited[s]=true;	//first node visited
			queue.push_back(s); 
  
			// 'i' will be used to get all adjacent 
			// vertices of a vertex 
			list<int>::iterator i;
  
		while(!queue.empty()) 
		{ 
		// Dequeue a vertex from queue and print it
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 
  
		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited, 
		// then mark it visited and enqueue it.
			for (i = adj[s].begin(); i != adj[s].end(); ++i) 
			{ 
				if (!visited[*i]) 
				{ 
				visited[*i] = true; 
				queue.push_back(*i); 
				} 
			} 
		} 
	}  
};

int main(int argc, char const *argv[])
{	
	int v,e,s,edge;

	/*
	v--.Number of vertices
	e-->Number of edges 
	s-->sourse vertex for DFS
	edge-->for edgge between two vertices
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
 	
 	cout<<"Enter the source vertex for BFS: ";
 	cin>>s;
	
	cout << "Following is Breadth First Traversal: "; 
	ob.BFS(s);

	return 0;
}