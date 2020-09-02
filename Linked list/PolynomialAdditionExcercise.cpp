//Polynomial Addition Using Linked List
#include <iostream>

using namespace std;
struct node
{
  int co,po;  //co stands for coefficient and po for power
  struct node *next;
};   //end of node

class polyadd
{
  public:
      struct node *head,*tail;
      polyadd()
      {
        head=tail=NULL;
      }

      void push(int coeff,int power)
      {  node *temp=new node;
         temp->co=coeff;
         temp->po=power;
         temp->next=NULL;

        if(head==NULL)
            head=tail=temp;

        else
         {
           tail->next=temp;
           tail=temp;
         }

          temp=NULL;
          delete temp;
      }  //end of add member function

    void disp()
    { node *temp=head;

       if(temp==NULL)
        cout<<"\nTerms with 0 as coefficient are not included in equation\n";

       else
         while(temp!=NULL)
         {cout<<temp->co<<"x^"<<temp->po<<" + ";
             temp=temp->next;
         }
       temp=NULL;
      delete temp;
    }   //end of member function for display purpose

    /*for addition pick a list (in this case we pick a) then start comparing one by one
      degree of each node in 'a' by those in 'b' if it matches add their coefficient and store them
      in a different list(list3) if not well just put it as it is in list3 and move further in 'a'.....
      once we are done with list 'a' check if b is at it's end or not, if it's not store the
      rest of elements in the list3 */
    void add(node *a,node *b)
    {
      while(a!=NULL&&b!=NULL)   //this will work if there are some elements in both so that addition might be possible
     { node *temp=new node;

       if(a->po==b->po)
       {
        temp->co=a->co+b->co;
        temp->po=a->po;
        temp->next=NULL;
        if(head==NULL)
            head=tail=temp;

        else
         {
           tail->next=temp;
           tail=temp;
         }
          a=a->next;
          b=b->next;
       }  //end of if

       else  //powers are not same
       {
        temp->co=a->co;
        temp->po=a->po;
        temp->next=NULL;
        if(head==NULL)
            head=tail=temp;

        else
         {
           tail->next=temp;
           tail=temp;
         }
          a=a->next;
       }    //end of while for 'a'

       temp=NULL;
      delete temp;
     }    //end of while....by this time all elements of 'a' must be in list3 and hopefully all of 'b' too

     //if in case there are elements left in 'a'
     if(a!=NULL)
        while(a!=NULL)
       { node *temp=new node;

        temp->co=a->co;
        temp->po=a->po;
        temp->next=NULL;
        if(head==NULL)
            head=tail=temp;

        else
         {
           tail->next=temp;
           tail=temp;
         }
          a=a->next;

        temp=NULL;
        delete temp;
      }   //end of while for 'a'

     //but if in case there are elements left in 'b'
     if(b!=NULL)
        while(b!=NULL)
       { node *temp=new node;

        temp->co=b->co;
        temp->po=b->po;
        temp->next=NULL;
        if(head==NULL)
            head=tail=temp;

        else
         {
           tail->next=temp;
           tail=temp;
         }
          b=b->next;

        temp=NULL;
        delete temp;
      }   //end of while for 'b'

    }  //end of member function add()


};   //end of class

int main()
{
    polyadd p1,p2,p3;  //p1=polynomial 1,p2=polynomial 2
    int n,c;   //n for highest degree c for coefficient

    //Insert first polynomial
    cout<<"Enter the highest degree of first polynomial\n";
    cin>>n;
    for(int i=n;i>=0;i--)
    {
      cout<<"\nEnter coefficient of x^"<<i<<" ";
      cin>>c;
      if(c!=0)
        p1.push(c,i);
    }

    //Insert second polynomial
    cout<<"\n\nEnter the highest degree of second polynomial\n";
    cin>>n;
    for(int i=n;i>=0;i--)
    {
      cout<<"\nEnter coefficient of x^"<<i<<" ";
      cin>>c;
      if(c!=0)
        p2.push(c,i);
    }

    p3.add(p1.head,p2.head);
    cout<<"\nFirst polynomial :";
    p1.disp(); cout<<"\n";
    cout<<"\nSecond polynomial:";
    p2.disp(); cout<<"\n";
    cout<<"\nSum is           :";
    p3.disp();

    return 0;
}