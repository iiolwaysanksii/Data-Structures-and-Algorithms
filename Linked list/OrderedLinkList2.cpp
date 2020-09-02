//Ordered Linked List Implementation
#include <iostream>
#include <stdlib.h>
using namespace std;

template< class T >
class Node {
public:
    T Data;
    Node<T> *next;
};

template< class T >
class LinkedList {
    public:
    Node<T> *head;

	LinkedList(){
	    head = NULL;
	}

	Node<T>* CreateNode() {
	    Node<T> *temp;

	    temp = new Node<T>;

	    if (temp == NULL) {
	        cout << endl << "Error: Cannot Create New Node!" << endl;
	        exit(1);
	    }

	    temp->next = NULL;

	    return temp;
	}

	void Insert_atBeginning(T Element) {
	    Node<T> *newNode = CreateNode();

	    newNode->Data = Element;

	    if (head == NULL)
	    	head = newNode;

	    else {
	    	newNode->next = head;
	    	head = newNode;
	    }

	}

	void Insert_atEnd(T Element) {
	    Node<T> *newNode = CreateNode();

	    newNode->Data = Element;

	    if (head == NULL)
	    	head = newNode;

	    else {
	    	Node<T> *ending;

	    	ending = head;
	    	while (ending->next != NULL)
	    	    ending = ending->next;

	    	ending->next = newNode;
	    }
	}

	T Delete_atBeginning() {
        if (head == NULL)
            return -1;

        Node<T> *temp;
        T element;

        temp = head;
        head = head->next;

        element = temp->Data;
        delete temp;

        return element;
	}

	T Delete_atEnd() {
        if (head == NULL)
            return -1;

        Node<T> *current, *previous;
        T element;

        current = previous = head;

        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        element = current->Data;

        delete current;

        return element;
	}

	bool Search(T Element) {
        if (head == NULL)
            return false;

        Node<T> *current = head;

        while (current->next != NULL) {
            if (current->Data == Element)
                return true;
            current = current->next;
        }
	}

	void Display() {
	    Node<T> *display;

	    if (head == NULL) {
	    	cout << endl << "Error: Empty List" << endl;
	    	exit(1);
	    }

	    display = head;

	    while(display != NULL) {
	    	cout << display->Data << " ";
	    	display = display->next;
	    }

	    cout << endl;
	}

	~LinkedList() {
        if (head != NULL) {
            Node<T> *temp;

            while (head->next != NULL) {
                temp = head;
                head = head->next;

                delete temp;
            }
        }
	}
};

template< class T >
Node<T> *Merge(Node<T> *head1, Node<T> *head2) {
    Node<T> *temp1, *temp2, *ptr, *tempHead;

    temp1 = head1;
    temp2 = head2;
    tempHead = NULL;

    while (temp1 != NULL && temp2 != NULL) {
        if (tempHead == NULL) {
            ptr = new Node<T>;
            tempHead = ptr;
        }

        else {
            ptr->next = new Node<T>;

            ptr = ptr->next;
        }

        if (temp1->Data < temp2->Data) {
            ptr->Data = temp1->Data;

            temp1 = temp1->next;
        }

        else if (temp2->Data < temp1->Data) {
            ptr->Data = temp2->Data;

            temp2 = temp2->next;
        }

        else {
            ptr->Data = temp1->Data;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1) {
        ptr->next = new Node<T>;
        ptr = ptr->next;

        ptr->Data = temp1->Data;

        temp1 = temp1->next;
    }

    while (temp2) {
        ptr->next = new Node<T>;
        ptr = ptr->next;

        ptr->Data = temp2->Data;

        temp2 = temp2->next;
    }

    return tempHead;
}


int main()
{
    LinkedList<int> l1, l2, l3;
    int Size_ofLL, choice, Element, ele;
    bool flag = true;

    do {
        cout << "Linked List" << endl << endl;

        cout << "MENU" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Merge" << endl;
        cout << "4. Exit" << endl;

        cout << endl << ":: ";
        cin >> choice;

        switch (choice) {
            case 1:
                    cout << endl << "Size of the Linked List: ";
                    cin >> Size_ofLL;


                    cout << endl << "Enter Element to Insert: ";
                    for (int i = 0; i < Size_ofLL; i++){
                        cin >> Element;

                        l1.Insert_atEnd(Element);
                    }

                    l1.Display();

                    break;

            case 2:
                    cout << endl << "Element to Delete: ";
                    cin >> Element;

                    ele = l1.Delete_atEnd();

                    if (ele == -1)
                        cout << endl << "Empty Linked List";
                    else
                        cout << endl << ele << " Deleted";

                    break;

            case 3:
                    Size_ofLL = Element = 0;

                    if (l1.head == NULL) {
                        cout << endl << "Size of the Linked List: ";
                        cin >> Size_ofLL;

                        cout << endl << "Enter Element to Insert: ";
                        for (int i = 0; i < Size_ofLL; i++){
                            cin >> Element;

                            l1.Insert_atEnd(Element);
                        }
                    }

                    cout << endl << "Enter Size of 2nd Linked List: ";
                    cin >> Size_ofLL;

                    cout << endl << "Enter Elements to Insert: ";
                    for (int i = 0; i < Size_ofLL; i++) {
                        cin >> Element;

                        l2.Insert_atEnd(Element);
                    }

                    l3.head = Merge(l1.head, l2.head);

                    cout << endl << "Linked List after Merging" << endl;
                    l3.Display();

                    break;

            case 4:
                    flag = false;

                    break;

            default:
                    cout << endl << "Wrong Choice !!!";
                    break;
        }

        cout << endl << endl;

    } while (flag);
}

