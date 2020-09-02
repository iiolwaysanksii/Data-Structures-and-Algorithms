#include <queue>
#include <utility>
#include "WeightedGraph.h"
#define INF 9909099
typedef pair<int, int> Pair;

// Initialize Priority Queue
priority_queue <Pair, vector<Pair>, greater<Pair> > Q;

void Prims(Graph*, int, int);

int main()
{
    int nVertices, vertex_1, vertex_2, weight, source;
    char option;

    cout << "Minimum Spanning Tree - Prims Algorithm" << endl;

    cout << endl << "Number of Vertices in the Graph: ";
    cin >> nVertices;

    // Graph
    Graph *G = new Graph(nVertices);

    cout << endl << "Enter Edge b/w Vertices & Weight";
    cout << endl << "Ex: If there is a edge b/w vertex 1 and vertex 2 with Weight 4 - 1 2 4" << endl;

    do {
        cout << endl << "Edge & Weight: ";
        cin >> vertex_1 >> vertex_2 >> weight;

        // Set the Edge in the Graph along with the Weight
        G->setEdge(vertex_1-1, vertex_2-1, weight);

        cout << endl << "Add more Edges (Y/N): ";
        cin >> option;

    } while (option == 'Y' || option == 'y');

    // Source Vertex to begin.
    cout << endl << "Source Vertex: ";
    cin >> source;

    // Call Prim's to find the MST.
    Prims(G, nVertices, source-1);
}

void Prims(Graph *G, int nvertex, int r)
{
    /*
        Function to find the Minimum Spanning Tree of a
        Graph G using the Prim's Algorithm.

        G: Pointer to the Graph
        nvertex: Total Number of Vertex in the Graph G
        r: Source Vertex

        After Finding the MST function displays the MST in
        the form of parent - child vertex;

        Eg:
            if after running prim's we have a edge b/w 1 & 3,
                then the result would be like
                    Edge b/w Vertex 1 - 3
    */

    Node *temp;
    int u, v, w, parent[nvertex], key[nvertex];

    // To Keep Track of Visited Vertex
    bool visited[nvertex] = {false};

    // for each vertex in the Graph G
    // Set key = INF & Parent as -1 (NIL)
    for (int i = 0; i < nvertex; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    // Set the key of Source Vertex (r) as 0
    key[r] = 0;

    // Build Priority Queue
    Q.push(make_pair(0, r));

    while (!Q.empty()) {
        // Get the vertex from the priority-queue
        u = Q.top().second;
        Q.pop();

        // Set the vertex u as visited;
        visited[u] = true;

        // for each v in the AdjList of u
        temp = G->AL[u].Head;
        while (temp) {

            // Vertex & Weight
            v = temp->V;
            w = temp->W;

            // if Vertex is not yet visited &
            // weight b/w u-v is less than v.key
            if (!visited[v] && w < key[v]) {

                // update v.key with the weight
                key[v] = w;
                // add the pair to priority queue
                Q.push(make_pair(key[v], v));
                // Set v's parent as u
                parent[v] = u;
            }

            temp = temp->next;
        }

    }

    // Display the Minimum Spanning Tree
    cout << endl << "Minimum Spanning Tree"<<endl;
    for (int i = 1; i < nvertex; i++)
        cout << "Edges b/w Vertex " << parent[i]+1 << " - " << i+1 << endl;
}
