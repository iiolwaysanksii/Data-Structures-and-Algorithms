/*
Implement DFS on a directed Graph including Starting Time and Finishing Time
*/
#include<iostream>
#include<list>          //helps in making adjacency list
using namespace std;

class Graph{
	int V;  //No. of vertices
	int *stime,*ftime;		//starting and finishing times of each vertex
	bool *visited;		//to keep track of visited and non-visited nodes
	list<int> *adj;     // Pointer that points to a list of integer type....remember it's dynamic

	public:
		Graph(int V){
				this->V=V;
				adj= new list<int>[V];		// <- an array of lists
				stime = new int[V];
				ftime = new int[V];
				visited = new bool[V];
			}
		
		void addEdge(int x, int y){ 
			adj[x].push_back(y); // Add y to x’s list. 
		}  
  
		void DFS(){	

			for (int i = 0; i < V; ++i)
			visited[i]=false;		

			int time=0;	//to calc starting and finishing time of nodes

			for (int i=0 ; i < V; ++i)
				if(!visited[i])
					DFS_VISIT(i,time);			//call DFS_Visit on every i where visited is false
		
			cout<<"\n\n";
			for (int i = 0; i < V; ++i)
				cout<<" For "<< i <<" Starting Time is : "<< stime[i] << " and Finishing Time is : " << ftime[i] << "\n";
		}  

		void DFS_VISIT(int v,int &t){			//v is vertex on which DFS_Visit is called and t is for time
			t++;
			stime[v]=t;		//starting time of this vertex is now set at time when it arrived
			
			visited[v]=true;
			cout <<v <<" ";

			list<int>::iterator i;

			for (i = adj[v].begin(); i != adj[v].end(); ++i)		//i scans the adjacency list of v until all vertex are visited
				if(!visited[*i])
					DFS_VISIT(*i,t);

			t++;
			ftime[v] = t;		//finishing time of the vertex whose list we just began is recorded
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