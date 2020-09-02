#include <iostream>
using namespace std;

class Node {
public:
    int Data;
    Node *Left;
    Node *Right;
    Node *Parent;
    int Color; // 0->Red, 1->Black

    Node(int d = 0) {
        Data = d;
        Left = NULL;
        Right = NULL;
        Parent = NULL;
    }
};

class RedBlackTree {
    Node *root;

    void LeftRotate(Node*);
    void RightRotate(Node*);
    void RB_Insert(Node*);
    void RB_Insert_Fixup(Node*);
    void InOrder(Node*);
    Node *SearchNode(Node*, int);

public:
    RedBlackTree(){
        root = NULL;
    }

    void Insert(int);
    void Display();
    void Search(int);

};

void RedBlackTree::LeftRotate(Node *x)
{
    Node *y;

    y = x->Right;
    x->Right = y->Left;

    if (y->Left != NULL)
        y->Left->Parent = x;

    y->Parent = x->Parent;

    if (x->Parent == NULL)
        root = x;
    else if (x == x->Parent->Left)
        x->Parent->Left = y;
    else
        x->Parent->Right = y;

    y->Left = x;
    x->Parent = y;
}

void RedBlackTree::RightRotate(Node *x)
{
    Node *y;

    y = x->Left;
    x->Left = y->Right;

    if (y->Right != NULL)
        y->Right->Parent = x;

    y->Parent = x->Parent;

    if (x->Parent == NULL)
        root = x;
    else if (x == x->Parent->Right)
        x->Parent->Right = y;
    else
        x->Parent->Left = y;

    y->Right = x;
    x->Parent = y;
}

void RedBlackTree::RB_Insert_Fixup(Node *z)
{
    Node *y;

    if (root == z) {
        z->Color = 1;
        return;
    }

    while (z->Parent != NULL && z->Parent->Color == 0) {
        if (z->Parent == z->Parent->Parent->Left) {
            y = z->Parent->Parent->Left;

            if (y->Color == 0) {
                z->Parent->Color = 1;
                y->Color = 1;
                z->Parent->Parent->Color = 0;
                z = z->Parent->Parent;
            }

            else {
                if (z == z->Parent->Right) {
                    z = z->Parent;
                    LeftRotate(z);
                }

                z->Parent->Color = 1;
                z->Parent->Parent = 0;

                RightRotate(z);
            }
        }

        else {
            y = z->Parent->Parent->Left;

            if (y->Color == 0) {
                z->Parent->Color = 1;
                y->Color = 1;
                z->Parent->Parent->Color = 0;
                z = z->Parent->Parent;
            }

            else {
                if (z == z->Parent->Left) {
                    z = z->Parent;
                    RightRotate(z);
                }

                z->Parent->Color = 1;
                z->Parent->Parent = 0;

                LeftRotate(z);
            }
        }
    }

    root->Color = 1;
}

void RedBlackTree::RB_Insert(Node *z)
{
    Node *y, *x;

    y = NULL;
    x = root;

    while (x != NULL) {
        y = x;
        if (z->Data < x->Data)
            x = x->Left;
        else
            x = x->Right;
    }

    z->Parent = y;

    if (y == NULL)
        root = z;
    else if (z->Data < y->Data)
        y->Left = z;
    else
        y->Right = z;

    z->Color = 0;

    RB_Insert_Fixup(z);
}

void RedBlackTree::Insert(int key)
{
    Node *newNode = new Node(key);

    RB_Insert(newNode);
}

Node *RedBlackTree::SearchNode(Node *ROOT, int key) {
    if (ROOT == NULL)
        return ROOT;

    if (key < ROOT->Data)
        return SearchNode(ROOT->Left, key);
    else if (key > ROOT->Data)
        return SearchNode(ROOT->Right, key);
    else
        return ROOT;
}

void RedBlackTree::Search(int key) {
    Node *node = SearchNode(root, key);

    if (node == NULL) {
        cout << endl << "Node Not Found with key " << key << endl;
        return;
    }

    cout << endl << "Node Found with key " << key;
    cout << endl << "Color: " << (node->Color == 0?"Red":"Black");
    cout << endl << "Parent: " << node->Parent->Data << endl;
}

void RedBlackTree::InOrder(Node *ROOT)
{
    if (ROOT != NULL) {
        InOrder(ROOT->Left);
        cout << endl <<"Key: "<< ROOT->Data << " - Color: " << ROOT->Color;
        InOrder(ROOT->Right);
    }
}

void RedBlackTree::Display()
{
    InOrder(root);
}

int main()
{
    RedBlackTree RB;

    RB.Insert(11);
    RB.Insert(2);
    RB.Insert(14);
    RB.Insert(15);
    RB.Insert(1);

    cout << "InOrder of Red Black Tree: ";
    RB.Display();

    cout << endl;

    cout << endl << "Searching Node 14 in the tree";
    RB.Search(9);
}
