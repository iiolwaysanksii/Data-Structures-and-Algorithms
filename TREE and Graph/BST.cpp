// Binary Search Tree Related Concepts 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    Node *left;
    int key;
    Node *right;
};

template< class T >
class BST {

    // Private Functions
    Node *Maximum(Node*);
    Node *Minimum(Node*);

    Node *Successor(Node*, T);
    Node *Predecessor(Node*, T);

    Node *Search(Node*, T);
public:
    Node *root;

    BST(){
        root = NULL;
    }

    Node *CreateNode() {
        Node *temp = new Node;

        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    // Insertion
    void Insert(Node*, T);

    // Deletion
    Node *Delete(Node*, T, char);

    // Traversal
    void LevelOrder();
    void InOrder(Node*);
    void PreOrder(Node*);
    void PostOrder(Node*);
    void Morris_InOrder();

    // Maximum and Minimum
    T MAX(Node*);
    T MIN(Node*);

    // Counting
    int TotalNodes(Node*);
    int LeafNodes(Node*);
    int InternalNodes(Node*);

    // Height
    int Height(Node*);

    // Search
    bool SearchKey(Node*, T);

    // Mirror Image
    void Mirror(Node*);

    // Successor and Predecessor.
    T InOrder_Successor(Node*, T);
    T InOrder_Predecessor(Node*, T);
};

// Insert
template< class T >
void BST<T>::Insert(Node *ROOT, T key) {
    if (root == NULL) {
        Node *NewNode = CreateNode();
        NewNode->key = key;

        root = NewNode;
    }

    else {
        if (key > ROOT->key) {
            if (ROOT->right == NULL) {
                ROOT->right = CreateNode();

                ROOT->right->key = key;
            }

            else {
                Insert(ROOT->right, key);
            }
        }

        if (key < ROOT->key) {
            if (ROOT->left == NULL) {
                ROOT->left = CreateNode();

                ROOT->left->key = key;
            }

            else {
                Insert(ROOT->left, key);
            }
        }
    }
}
/*---------------------------------------------------------------------*/

// Delete
/*
    There are 3 Cases for Deleting a Node:
    1. Node to Delete is the Leaf Node.
    2. Node to Delete have 1 Child
    3. Node to Delete is a Internal Nodel i.e 2 Child
        3.1. Merging
        3.2. Copying
*/
template< class T >
Node *BST<T>::Delete(Node *ROOT, T key, char opt) {
    // Search for the key in the BST.
    if (ROOT == NULL)
        return ROOT;
    else if (key < ROOT->key)
        ROOT->left = Delete(ROOT->left, key, opt);
    else if (key > ROOT->key)
        ROOT->right = Delete(ROOT->right, key, opt);

    else {
        // Case 1: No Child.
        if (ROOT->left == NULL && ROOT->right == NULL) {
            delete ROOT;
            ROOT = NULL;
        }

        // Case 2: One Child
        else if (ROOT->left == NULL) {
            Node *temp = ROOT;
            ROOT = ROOT->right;
            delete temp;
        }

        else if (ROOT->right == NULL) {
            Node *temp = ROOT;
            ROOT = ROOT->left;
            delete temp;
        }

        // Case 3: Two Child
        else {

            if (opt == 'M') {
                // Case 3.1. Merging
                Node *succ = Successor(ROOT, key);

                succ->left = ROOT->left;
                succ = ROOT;

                ROOT = ROOT->right;

                delete succ;
            }

            if (opt == 'C') {
                // 3.2. Copying

                Node *temp = Minimum(ROOT->right);
                ROOT->key = temp->key;
                ROOT->right = Delete(ROOT->right, temp->key, opt);
            }
        }
    }

    return ROOT;
}

/*----------------------------------------------------------------------*/

// Traversal
template< class T >
void BST<T>::LevelOrder()  {
    queue<Node*> Q;

    Q.push(root);

    while (!Q.empty()) {
        Node *tempNode = Q.front();

        if (tempNode->left != NULL)
            Q.push(tempNode->left);

        if (tempNode->right != NULL)
            Q.push(tempNode->right);

        cout << tempNode->key << " ";
        Q.pop();
    }
}

template< class T >
void BST<T>::InOrder(Node *ROOT) {
    if (ROOT != NULL) {
        InOrder(ROOT->left);
        cout << ROOT->key << " ";
        InOrder(ROOT->right);
    }
}

template< class T >
void BST<T>::PreOrder(Node *ROOT) {
    if (ROOT != NULL) {
        cout << ROOT->key << " ";
        PreOrder(ROOT->left);
        PreOrder(ROOT->right);
    }
}

template< class T >
void BST<T>::PostOrder(Node *ROOT) {
    if (ROOT != NULL) {
        PostOrder(ROOT->left);
        PostOrder(ROOT->right);
        cout << ROOT->key << " ";
    }
}

template< class T >
void BST<T>::Morris_InOrder() {
    Node *current, *predecessor;
    current = root;

    while (current) {
        if (current->left == NULL) {
            cout << current->key << " ";
            current = current->right;
        }
        else {
            /* Find the InOrder Predecessor */
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
                predecessor = predecessor->right;

            /* Make current as right child of its inorder predecessor */
            if(predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            }

            /* Revert the changes made in if part to restore the original
            tree i.e., fix the right child of predecssor */
            else {
                predecessor->right = NULL;
                cout << current->key << " ";
                current = current->right;
            }

        }
    }
}
/*----------------------------------------------------------------*/

// Maximum Minimum
/*
    Find the Maximum and Minimum key in the BST.
    Maximum key is the right most key of the right subtree.
    Minimum key is the left most key of the left subtree.
*/
template< class T >
Node *BST<T>::Maximum(Node *ROOT) {
    if (ROOT->right == NULL)
        return ROOT;

    return Maximum(ROOT->right);
}

template< class T >
T BST<T>::MAX(Node * ROOT) {
    return Maximum(ROOT)->key;
}

template< class T >
Node *BST<T>::Minimum(Node *ROOT) {
    if (ROOT->left == NULL)
        return ROOT;

    return Minimum(ROOT->left);
}

template< class T >
T BST<T>::MIN(Node * ROOT) {
    return Minimum(ROOT)->key;
}
/*---------------------------------------------------------------------*/

// Count Nodes
/*
    Count Nodes i.e Total Number of Nodes in BST, Internal Nodes and Leaf Nodes.
    Internal Nodes are Nodes with 2 Childrens.
    Leaf Nodes are Nodes with No Childern.
*/
template< class T >
int BST<T>::TotalNodes(Node *ROOT) {
    if (ROOT == NULL)
        return 0;

    return (TotalNodes(ROOT->left) + TotalNodes(ROOT->right) + 1);
}

template< class T >
int BST<T>::InternalNodes(Node *ROOT) {
    if (ROOT == NULL)
        return 0;

    else if(ROOT->left == NULL || ROOT->right == NULL)
        return 0;

    else
        return (InternalNodes(ROOT->left) + InternalNodes(ROOT->right) + 1);
}

template< class T >
int BST<T>::LeafNodes(Node *ROOT) {
    if (ROOT == NULL)
        return 0;

    if (ROOT->left == NULL && ROOT->right == NULL)
        return 1;

    return (LeafNodes(ROOT->left) + LeafNodes(ROOT->right));
}
/*----------------------------------------------------------------------------*/

// Height
/*
    Height of the BST is the maximum level of nodes.
*/
template< class T >
int BST<T>::Height(Node *ROOT) {
    if (ROOT == NULL)
        return 0;

    int H1 = Height(ROOT->left);
    int H2 = Height(ROOT->right);

    // Height is the Maximum of Left Nodes and Right Node +1 for root.
    return 1 + max(H1, H2);
}
/*---------------------------------------------------------------------------*/

// Search
/*
    Search for a particular key in the BST.
*/
template< class T >
Node *BST<T>::Search(Node *ROOT, T key) {
    if (ROOT == NULL)
        return NULL;
    else if (key < ROOT->key)
        Search(ROOT->left, key);
    else if (key > ROOT->key)
        Search(ROOT->right, key);
    else
        return ROOT;
}

template< class T >
bool BST<T>::SearchKey(Node *ROOT, T key) {
    Node * temp = Search (ROOT, key);

    if (temp)
        return true;
    return false;
}
/*---------------------------------------------------------------------------*/

// Mirror Image
template< class T >
void BST<T>::Mirror(Node *ROOT) {

    if (ROOT == NULL)
        return;

    Mirror(ROOT->left);
    Mirror(ROOT->right);

    Node *temp = ROOT->left;
    ROOT->left = ROOT->right;
    ROOT->right = temp;
}

/*---------------------------------------------------------------------------*/
// Inorder Successor
// Private Function
template< class T >
Node *BST<T>::Successor(Node *ROOT, T key) {

    // Search for the Node with the key.
    Node *Current = Search(ROOT, key);

    if (Current == NULL) {
        cout << endl << "Key Not Found" << endl;
        return NULL;
    }

    // Case 1: if right subtree of the node is present.
    // Then, successor is the minimum element in the right subtree
    if (Current->right != NULL)
        return Minimum(Current->right);

    // Case 2: Subtree is not Present.
    else {
        // successor
        Node *succ = NULL;

        // loop until ROOT and Current are not equal
        while (ROOT != Current) {
            if (Current->key < ROOT->key) {

                // if current key is less than root key
                // make succ as root
                // go left
                succ = ROOT;
                ROOT = ROOT->left;
            }
            else
                // else go right
                ROOT = ROOT->right;
        }

        return succ;
    }

}

// Public Function
template< class T >
T BST<T>::InOrder_Successor(Node *ROOT, T key) {
    Node *temp = Successor(ROOT, key);

    if (temp == NULL)
        return -1;
    return temp->key;
}
/*------------------------------------------------------------------------*/

// Inorder Predecessor
// Private Function
template< class T >
Node *BST<T>::Predecessor(Node *ROOT, T key) {

    // Search for the Node with the key.
    Node *Current = Search(ROOT, key);

    if (Current == NULL) {
        cout << endl << "Key Not Found" << endl;
        return NULL;
    }

    // Case 1: if left subtree of the node is present.
    // Then, successor is the maximum element in the left subtree
    if (Current->left != NULL)
        return Maximum(Current->left);

    // Case 2: Subtree is not Present.
    else {
        // predecessor
        Node *pred = NULL;

        // loop until ROOT and Current are not equal
        while (ROOT != Current) {
            if (Current->key > ROOT->key) {

                // if current key is greater than root key
                // make pred as root
                // go right
                pred = ROOT;
                ROOT = ROOT->right;
            }
            else
                // else go left
                ROOT = ROOT->left;
        }

        return pred;
    }

}

// Public Function
template< class T >
T BST<T>::InOrder_Predecessor(Node *ROOT, T key) {
    Node *temp = Predecessor(ROOT, key);

    if (temp == NULL)
        return -1;
    return temp->key;
}
/*-------------------------------------------------------------------------------*/


int main()
{
	int choice, key_toDelete;;
	bool flag = true;
    BST<int> B;

    do {
	    cout << "Binary Search Tree" << endl;

	    cout << "MENU:" << endl;
	    cout << "1. Insertion" << endl;
	    cout << "2. Deletion by copying" << endl;
	    cout << "3. Deletion by Merging" << endl;
	    cout << "4. Search a no. in BST" << endl;
	    cout << "5. Display its preorder, postorder and inorder traversals" << endl;
	    cout << "6. Display its level-by-level traversals" << endl;
	    cout << "7. Count the non-leaf nodes and leaf nodes" << endl;
	    cout << "8. Display height of tree" << endl;
	    cout << "9. Create a mirror image of tree" << endl;
	    cout << "10. Exit" << endl;

	    cout << endl << ":: ";
	    cin >> choice;

	    switch (choice) {
	    	case 1:
	    			int keys, temp;

	    			cout << endl << "Enter Total Number of Keys to Insert: ";
	    			cin >> keys;

	    			cout << endl << "Enter keys: ";
	    			for (int i = 0; i < keys; i++) {
	    				cin >> temp;

	    				B.Insert(B.root, temp);
	    			}

	    			break;

	    	case 2:
					cout << endl << "Enter key to Delete: ";
					cin >> key_toDelete;

					B.root = B.Delete(B.root, key_toDelete, 'C');

	    			break;

	    	case 3:
					cout << endl << "Enter key to Delete: ";
					cin >> key_toDelete;

					B.root = B.Delete(B.root, key_toDelete, 'M');

	    			break;

	    	case 4:
	    			int key_toSearch;

	    			cout << endl << "Enter key to Search: ";
	    			cin >> key_toSearch;

	    			if (B.SearchKey(B.root, key_toSearch))
	    				cout << endl << "Found Key in the BST";
	    			else
	    				cout << endl << "Key Not Found!!!";

	    			break;

	    	case 5:
	    			cout << endl << "PreOrder: ";
					B.PreOrder(B.root);

					cout << endl << "PostOrder: ";
					B.PostOrder(B.root);

					cout << endl << "InOrder: ";
					B.InOrder(B.root);

	    			break;

	    	case 6:
	    			cout << endl << "Level Order Traversal: ";
					B.LevelOrder();

	    			break;

	    	case 7:
					cout << endl << "Non-Leaf Node (Internal Nodes): " << B.InternalNodes(B.root);
					cout << endl << "Leaf Nodes: " << B.LeafNodes(B.root);

	    			break;

	    	case 8:
	    			cout << endl << "Height: " << B.Height(B.root);

	    			break;

	    	case 9:
	    			B.Mirror(B.root);
	    			cout << endl << "DONE";

	    			break;

	    	case 10:
	    			flag = false;
	    			break;

	    	default:
	    			cout << endl << "Wrong Choice !!!" << endl;
	    			break;
	    }

	    cout << endl << endl;
	} while (flag);
}
