//Ordered Linked List Implementation
#include <iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node*next;
};//end of node structure

class slist
{
  node *head,*tail;

   public:
      slist()
      {
       head=tail=NULL;
      }

      void insertinto(int val)
      {
        node *temp=new node;   //temp is accessible thought our member function
        temp->data=val;   temp->next=NULL;

        if(head==NULL&&tail==NULL)   //means list is empty
           {head=tail=temp;
            cout<<"First node of list Inserted\n";
           }

        else    //there must be some node in list
        {
          if(val<head->data)   //insert at head
          {
           temp->next=head;
           head=temp;
           cout<<"Node Insert at head\n";
          }
          else if(val>tail->data) //insert at tail
          {
            tail->next=temp;
            tail=temp;
            cout<<"Node inserted at tail\n";
          }
           else if(val==head->data||val==tail->data)   //no need to insert in this case
           cout<<"Data entered by you either matches head or matches tail so no insertion..\n";

            /*if none of the above is executed then we reach this step
                we need two pointers one at head and one at node after head
                from here we start comparing data of these two nodes and move further
                into the list until the place is found*/
            else
            { node *p=head;  //for previous element
              node *n=p->next;  //for next element

              while(n!=NULL)
              {
                if(val>p->data&&val<n->data)
                 {
                   p->next=temp;
                   temp->next=n;
                   cout<<"Node inserted\n";
                   break;
                 }
                else
                 {
                   p=p->next;
                   n=n->next;
                 }
             }  //end of while
             p=n=NULL;
             delete p;
             delete n;
            }   //end of nested else
        }  //end of first else
        temp=NULL;
        delete temp;
      }   //end of insertinto() member function

      void deleteinto(int val)
      {
        node *temp=new node;   //temp is accessible thought our member function
        temp->data=val;   temp->next=NULL;

        if(head==NULL)   //means list is empty
           cout<<"List is empty\n";


        else    //there must be some node in list
        {
          if(val<head->data||val>tail->data)
            cout<<"Node is not in the list\n";

          else if(head==tail)   //means there's just one node in list
            {
              temp=head;
              head=tail=NULL;
               cout<<"Only node in list deleted\n";
            }
          else if(val==head->data)  //means we delete head
            {
              temp=head;
              head=head->next;
              cout<<"Head deleted\n";
            }
            else if(val==tail->data)  //we delete tail
            {
              temp=head;
              while(temp->next!=tail)
                    temp=temp->next;
                tail=temp;  //tail shifted backwards
                temp=temp->next; //temp shifted to original tail
                tail->next=NULL;
                cout<<"Tail deleted\n";
            }

            else  //means my node is somewhere in middle
            {/*In order to delete element from a particular pos we stop at the
             node which is just before that node and connect it to the node
             which comes after the node that is to be deleted but first we place
             a different pointer at that node so we can free that memory space*/
             node *pre=head;
             while(pre->next!=tail)  //we stop execution when we are at element before tail
             {
              if(pre->next->data==val)
              {
               temp=pre->next;  //place temp at node which is to be deleted
               pre->next=pre->next->next;
               cout<<"Node deleted from somewhere in middle\n";
               break;
              }
              else
              {
               pre=pre->next;
              }
             }   //end of while
             pre=NULL;
             delete pre;
            }   //end of else for deletion in middle
        }  //end of first else
        delete temp;

      }   //end of deleteinto() head member function

      void lookinto()
      {
        cout<<"Enter the element that has to be searched in list "; int e,f=0; cin>>e;

        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        { if(temp->data==e)
           {f++;
            break;
           }
           temp=temp->next;
        }
        if(f==0)
            cout<<"Element is not in the list \n";
        else
            cout<<"Element is present in the list\n";

        temp=NULL;
        delete temp;
      }  //end of look into member function

      void display()
      {
         node *temp=new node;
         if(head==NULL&&tail==NULL)
            cout<<"\nNo node to display\n";
         else
         {  temp=head;
           while(temp!=NULL)
           {cout<<"Data in Node is "<<temp->data<<"\n";
           temp=temp->next;
           }
         }
         temp=NULL;
         delete temp;
      }   //end of display member function

};

int main()
{
    slist ob;
    char ch='y';int n,d;    //n is for the input of main menu
                                //d is for data of node
   do{
  cout<<" Enter\n"
      <<"1.Insertion\n"
      <<"2.Deletion\n"
      <<"3.Search\n"
      <<"4.Display the whole list\n";   cin>>n;

    switch(n)
    {       case 1:
                   cout<<"Enter the integer data of node\n";  cin>>d;
                   ob.insertinto(d);
                   break;

            case 2:
                   cout<<"Enter the data of node that is to be deleted\n"; cin>>d;
                   ob.deleteinto(d);
                   break;

            case 3:
                   ob.lookinto();
                   break;

            case 4:
                   ob.display();
                   break;

            default:
                    cout<<"Read the menu again your choice is not valid\n";
                    break;
    }    //end of switch-case
   cout<<"Do you want to continue with the main menu(y/n)\n";
   cin>>ch;
   system("CLS");
}while(ch=='y');     //end of while loop

    return 0;
}
