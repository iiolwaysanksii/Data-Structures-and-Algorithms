#include <iostream>
using namespace std;

struct Node {
    int V;
    Node *next;
};

struct AdjacencyList {
    Node *Head;
};

Node *CreateNode()
{
    Node *temp = new Node;
    temp->V = 0;
    temp->next = NULL;

    return temp;
}

void u_setEdge(AdjacencyList *AL, int U, int V)
{
    Node *E1 = CreateNode();
    Node *E2 = CreateNode();

    E1->V = V;
    E2->V = U;

    if (AL[U].Head == NULL) {
        AL[U].Head = E1;
    }

    else {
        E1->next = AL[U].Head;
        AL[U].Head = E1;
    }

    if (AL[V].Head == NULL) {
        AL[V].Head = E2;
    }

    else {
        E2->next = AL[V].Head;
        AL[V].Head = E2;
    }
}

void d_setEdge(AdjacencyList *AL, int U, int V)
{
    Node *E1 = CreateNode();

    E1->V = V;

    if (AL[U].Head == NULL) {
        AL[U].Head = E1;
    }

    else {
        E1->next = AL[U].Head;
        AL[U].Head = E1;
    }
}


void print(AdjacencyList *AL, int num_of_vertices)
{
    Node *temp;

    for (int i = 0; i < num_of_vertices; i++) {

        temp = AL[i].Head;

        cout << i+1;
        while (temp) {
            cout << " -> " << temp->V+1;

            temp = temp->next;
        }
        cout << endl;
    }

}

void free(AdjacencyList *AL, int n)
{
    Node *temp;

    for (int i = 0; i < n; i++) {

        if (AL[i].Head != NULL) {
            while ((temp = AL[i].Head) != NULL) {
                AL[i].Head = AL[i].Head->next;
                delete temp;
            }
        }
    }
}
