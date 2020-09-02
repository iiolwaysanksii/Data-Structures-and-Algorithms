//Implementation of Stack using Linked List
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node  //node structure
{
    int data;
    struct node*next;
};//end of node structure

class stack
{
   int count;
   node *top;
   public:
       stack()
       {
         count=0;
         top=NULL;
       }
      void push()
      {
        node *temp=new node;
        cout<<"Enter the Integer data of a stack node\n";
        cin>>temp->data;    temp->next=NULL;

        if(top==NULL)
          {
           top=temp;
           count++;
          }    // end of if
         else
         {
            temp->next=top;    //next here actually is used
            top=temp;
            count++;          //to help bind the node which is just below temp
         }    //end of else

         cout<<"Node Inserted\n";
         cout<<"Total node in stack are "<<count<<"\n";
        temp=NULL;
        delete temp;
      }    //end of push()

      void pop()
      {
         node *temp=new node;
         temp=top;
         if(top==NULL)
            cout<<"Stack is empty\n";
         else
         {
           cout<<"Data in popped node is "<<top->data<<"\n";
           top=top->next;
         }
        delete temp;
      }  //end of pop()

      void Clear()
      {  /*we can easily make top=NULL but we
          also need to free the memory as well
          so we do this*/

        while(top!=NULL)
        {
          node *temp=new node;  //d node means deleted node
          temp=top;
          top=top->next;
          delete temp;
        }  //end of while used to free the memory
        cout<<"Task completed stack is empty now\n";
      }  //end of Clear()

      void display()
      {
       if(top==NULL)
        cout<<"Stack is Empty\n";
       else
       {  node *temp=new node;
          temp=top;
          while(temp!=NULL)
          {
            cout<<"Data in the node is "<<temp->data<<"\n";
            temp=temp->next;
          }   //end of while inside else
          delete temp;   //as after the execution of while loop temp would be NULL so we delete it
        }  //end of else
      }  //end of Display()

      void topel()
      {
        if(top==NULL)
          cout<<"Stack is empty\n";
        else
          cout<<"Data in top node is "<<top->data<<"\n";
      }  //end of topel()
};   //end of class stack

int main()
{
   int m; char ch='y';
   /*m is for the choice in main menu
     ch is for repetetion of main menu*/
   stack ob;
    do
    {
       system("CLS");
        cout<<"MENU\n"
            <<"1.Push\n"
            <<"2.Pop\n"
            <<"3.Clear (clear the stack)\n"
            <<"4.Display the Top element\n"
            <<"5.Display the whole stack\n"
            <<"6.EXIT\n";
         cin>>m;
         switch(m)
         {
          case 1: ob.push();
                  break;
          case 2: ob.pop();
                  break;
          case 3: ob.Clear();
                  break;
          case 4: ob.topel();
                  break;
          case 5: ob.display();
                  break;
          case 6: exit(0);

          default: cout<<"Invalid choice....\n";
                   break;
         }   //end of switch-case
       cout<<"Want to continue with the main menu(y/n)\n";
       cin>>ch;
    }while(ch=='y');  //end of while do while
     return 0;
}