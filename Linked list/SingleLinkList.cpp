//Singly Linked List Implementation
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
  int count,position;    //count will keep tap on total no. of nodes

  public:
      slist()
      {
       head=tail=NULL;
       count=0;
      }

      void inserthead(int val)
      {
         node *temp=new node;
         temp->data=val;   temp->next=NULL;

         if(head==NULL&&tail==NULL)  //means it is my first node
         {  head=temp;  tail=temp;  count++; }
         else                  //else we connect the node at head
         {
           temp->next=head;
           head=temp;
           count++;
         }
         cout<<"\nNode inserted\n";
         cout<<"total nodes in link list at present are "<<count<<"\n";
          temp=NULL;
         delete temp;
     }   //end of insert head() member function

      void inserttail(int val)
      {
         node *temp=new node;
         temp->data=val;   temp->next=NULL;

         if(head==NULL&&tail==NULL)  //means it is my first node
         {  head=temp;  tail=temp;  count++;  }
         else                  //else we connect it to tail
         {
             tail->next=temp;
             tail=temp;  count++;
         }
         cout<<"\nNode inserted\n";
         cout<<"Total nodes in linked list at present are "<<count<<"\n";
         temp=NULL;
         delete temp;
      }  //end of insert tail() member function

      void insertat(int val,int p)
      {
         if(p>=count)
            cout<<"Sorry can't add here\n";   //first check if the position is correct or not
         else if(p==0||p==1)
            cout<<"Choose insertion at head if you want to add at this position\n";

         else
         {  node *temp=new node;
            temp->data=val;
            temp->next=NULL;
            if(head==NULL&&tail==NULL)  //means it is my first node
            {  head=temp;
               tail=temp;
               count++;
               cout<<"Total nodes in list are "<<count<<"\n";
             }

             else
             {
              node *last=head;
              int position=1;

              while(last!=NULL)
              { if(position==p-1)        //we have to insert element here
                  {
                      temp->next=last->next;    //first connect the node just after next to temp so that list remains intact
                      last->next=temp;
                      count++;     //then connect temp with last
                      break;
                  }
                  else
                    last=last->next;
                    position++;
              }
              last=NULL;
              delete last;
            }
            cout<<"\nNode inserted\n";
            cout<<"Total nodes in list are "<<count<<"\n";
            temp=NULL;
            delete temp;
          }  //end of outer else

      }  //end of insert at() member function

      void deletehead()
      {
        if(head==NULL)
        {
            cout<<"List is Empty\n";
        }
        else{
        node *temp=new node;
        cout<<"Data in deleted node is "<<head->data<<"\n";
        if(head==tail)   //this would mean there's only one node in list
        {temp=head;
         head=tail=NULL;
         count=0;
         }
       else
       { temp=head;
        head=head->next;
        count--;
        }
        delete temp;
        cout<<"Node Deleted \n";
        cout<<"Total nodes left in list are "<<count<<"\n";
       }  //end of first else
      }   //end of delete head member function

      void deletetail()
      {
        if(head==NULL)
        {
            cout<<"List is Empty\n";
        }
        else{
        node *temp=new node;
        if(head==tail)   //this would mean there's only one node in list
        {cout<<"Data in deleted node is "<<head->data<<"\n";
         temp=head;
         head=tail=NULL;
         count=0;
         }
        else
        {
            temp=head;
            while(temp->next!=tail)  //we locate element before tail
            temp=temp->next;

            cout<<"Data in Deleted nose is "<<tail->data<<"\n";
            tail=temp;   //shift the tail backwards and clear it's next slot
            temp=temp->next;   //shift temp to original tail so we can free that memory
            tail->next=NULL;
            count--;
            cout<<"Node Deleted\n";  cout<<" total no. of nodes left in linked list are "<<count<<"\n";
        }
        delete temp;
        }    //end of first else
       }  //end of delete tail member function

      void deleteat(int p)
      {
        if(p>=count)
            cout<<"Either the list is empty or The position entered is not reachable\n";
        else if(p==0||p==1)
            cout<<"Choose deletion at head if you want to delete node at this position\n";
        else
        {
         if(head==tail)   //this would mean there's only one node in list
         { node *dnode=head;
          cout<<"Data in Deleted node is "<<dnode->data<<"\n";
          head=tail=NULL;
          delete dnode;
          count=0;
         }

         else
         { node *temp=new node;
           node *last=head;

           position=1;
           /*In order to delete element from a particular pos we stop at the
             node which is just before that node and connect it to the node
             which comes after the node that is to be deleted but first we place
             a different pointer at that node so we can free that memory space*/
           while(last->next!=tail)
           {
            if(position==p-1)
            {temp=last->next;
             cout<<"Data in Deleted node is "<<temp->data<<"\n";
             last->next=last->next->next;
             count--;
            }
            else
             last=last->next;   //just this statement in last
             position++;
           }   //end of while
           delete temp;
           last=NULL;
           delete last;
         }  //end of else for deletion  at pos

        } //end of else for deletion
      } //end of delete at member function

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
  char choice='y',c;int n,m,d,pos;    //n is for the input of main menu m is for sub menu
                                //d is for data of node and pos is for position
   do{
  cout<<" Enter\n"
      <<"1.Insertion\n"
      <<"2.Deletion\n"
      <<"3.Search\n"
      <<"4.Display the whole list\n";   cin>>n;

    switch(n)
    {       case 1:
              do{cout<<"Enter the integer data of node\n";  cin>>d;
                 cout<<"\nWhere to insert this node\n"
                     <<"1.At Head\n"
                     <<"2.At Tail\n"
                     <<"3.At particular position\n"; cin>>m;
                  switch(m)
                  { case 1: ob.inserthead(d);
                            break;
                    case 2: ob.inserttail(d);
                            break;
                    case 3: cout<<"Enter the position you want to add the node at\n";
                            cin>>pos;
                            ob.insertat(d,pos);
                            break;
                    default : cout<<"wrong input...\n";
                              break;
                  }
                  cout<<"Want to continue with Insertion (y/n)\n";  cin>>c;
                  system("CLS");
                }while(c=='y');   //end of do while loop for insertion
              break;

                 case 2: do{cout<<"\nFrom which position the node is to be deleted\n"
                  <<"1.From Head\n"
                  <<"2.From Tail\n"
                  <<"3.From particular position\n"; cin>>m;
                  switch(m)
                  { case 1: ob.deletehead();
                            break;
                    case 2: ob.deletetail();
                            break;
                    case 3: cout<<"Enter the position from where the node has to be deleted\n";
                            cin>>pos;
                            ob.deleteat(pos);
                            break;
                    default : cout<<"wrong input...\n";
                              break;
                  }
                  cout<<"Want to continue with Deletion (y/n)\n";  cin>>c;
                  system("CLS");
                }while(c=='y');   //end of do while loop for Deletion
                          break;

                   case 3: ob.lookinto();
                             break;

                    case 4: ob.display();
                            break;

            default: cout<<"Read the menu again your choice is not valid\n";
               break;
    }    //end of outer switch-case
   cout<<"Do you want to continue with the main menu(y/n)\n";
   cin>>choice;
   system("CLS");
}while(choice=='y');     //end of while loop

    return 0;
}
