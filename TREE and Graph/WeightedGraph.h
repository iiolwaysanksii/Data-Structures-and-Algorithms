#include <iostream>
using namespace std;

// Node Structure
struct Node {
    /*
        V: Vertex
        W: Weight
        next: Pointer to the next Node.
    */

    int V;
    int W;
    Node *next;
};

struct AdjacencyList {
    // Head Pointer for the AdjList
    Node *Head = NULL;
};

class Graph {
    int Vertices;

    // Function to Create a New Node
    Node *CreateNode(int u, int w) {
        // Create a Node
        Node *temp = new Node;
        // Set Vertex and Weight and next as NULL;
        temp->V = u;
        temp->W = w;
        temp->next = NULL;

        // Return the New Node
        return temp;
    }

public:
    AdjacencyList *AL;

    Graph(int num_of_vertex) {
        this->Vertices = num_of_vertex;

        // Initialize the AdjList for the Graph
        AL = new AdjacencyList[this->Vertices];
    }

    void setEdge(int u, int v, int w) {
        /*
            Set Edge b/w u-v and v-u (as the Graph is Undirected)

            u: Source Vertex;
            v: Destination Vertex;
            w: Weight of the Edge b/w vertex u-v;
        */

        // Create Node with the respective
        // vertex and weights;
        Node *N1 = CreateNode(v, w);
        Node *N2 = CreateNode(u, w);

        // Add the Node to the AdjList of
        // the respective Vertex
        if (AL[u].Head == NULL) {
            AL[u].Head = N1;
        }

        else {
            N1->next = AL[u].Head;
            AL[u].Head = N1;
        }

        if (AL[v].Head == NULL) {
            AL[v].Head = N2;
        }

        else {
            N2->next = AL[v].Head;
            AL[v].Head = N2;
        }
    }

    void print() {
        /*
            Display the AdjList of the Graph G;
        */

        Node *temp;

        for (int i = 0; i < Vertices; i++) {
            temp = AL[i].Head;

            cout << i+1;
            while (temp) {
                // Print both Vertex and Weight
                cout << " Vertex: " << temp->V+1 << " - Weight: " << temp->W << " ";

                temp = temp->next;
            }
            cout << endl;
        }

    }

    ~Graph() {
        /*
            Destructor to Free the Memory;
        */

        Node *temp;

        for (int i = 0; i < Vertices; i++) {

            if (AL[i].Head != NULL) {
                while ((temp = AL[i].Head) != NULL) {
                    AL[i].Head = AL[i].Head->next;
                    delete temp;
                }
            }
        }

        delete AL;
    }
};
