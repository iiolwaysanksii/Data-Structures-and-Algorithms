//Implement Sparse Matrix

#include <iostream>

using namespace std;

struct node
{
  int row,column,data;
  struct node *next;
};  //end of node

class sparse
{
  node *head,*tail;
  public:
      sparse()
      {
        head=tail=NULL;
      }     //end of constructor
    void tolink(int r,int c,int val)
    {
        node *temp=new node;
        temp->row=r;
        temp->column=c;
        temp->data=val;
        temp->next=NULL;

        if(head==NULL&&tail==NULL)
           head=tail=temp;
        else
        {
         tail->next=temp;
         tail=temp;
        }

      temp=NULL;
      delete temp;
    }  //end of to link member function converts sparse into link list

    void display()
    {
      node *temp=head;
      while(temp!=NULL)
      {
        cout<<"Data at row "<<temp->row+1<<" and column "<<temp->column+1<<" is "<<temp->data<<"\n";
        temp=temp->next;
      }
      delete temp;
    }  //end of display function
};  //end of class
int main()
{   int a,b; //for row and column respectively
    cout<<"Enter no. of rows ";     cin>>a;  cout<<"\n";
    cout<<"Enter no. of columns ";  cin>>b;  cout<<"\n";

    sparse ob;
    int s[a][b];
    cout<<"Now enter the elements of sparse matrix (majority elements should be zero)\n";

    for(int i=0;i<a;i++)
    {
       for(int j=0;j<b;j++)
       {
         cout<<"Enter the ["<<i+1<<"]["<<j+1<<"] element of matrix ";
         cin>>s[i][j];  cout<<"\n";

         if(s[i][j]!=0)
            ob.tolink(i,j,s[i][j]);
       }
    }  //end of for loop for insertion and conversion
    cout<<"Sparse matrix has been converted into link list \n";
    char ch;
    cout<<"Would you like to see the list(y/n)\n";  cin>>ch;
    if(ch=='y')
        ob.display();

    return 0;
}   //end of main
