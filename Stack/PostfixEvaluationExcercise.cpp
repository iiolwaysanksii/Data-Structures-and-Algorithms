//Evaluate Postfix Expression using Stack
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

struct node
{
  int data;
  struct node *next;

};

class stack
{
   struct node *top;
   public:
    stack()
    {
         top=NULL;
       }

    void push(int el)
    {
        node *temp=new node;
        temp->data=el;    temp->next=NULL;

        if(top==NULL)
          top=temp;

         else
         {
            temp->next=top;
            top=temp;
         }

        temp=NULL;
        delete temp;
      }    //end of push()

    void display()
    {
     if(top==NULL)
        cout<<"Stack is Empty\n";
       else
       {  node *temp=new node;
          temp=top;
          while(temp!=NULL)
          {
            cout<<temp->data;
            temp=temp->next;
          }
          delete temp;
        }  //end of else
      }

    int pop()
    {
      if(top==NULL)
        exit(0);
      else
        {int op;
         node *temp=top;
         op=top->data;
         top=top->next;
         delete temp;
         return op;
        }
    }

    int eval(int x, int y,char sym)
    {
      if(sym=='+')
        return(x+y);
      else if(sym=='-')
        return(x-y);
      else if(sym=='*')
        return(x*y);
      else if(sym=='/')
        return(x/y);
      else if(sym=='$')
        return(pow(x,y));
    }
};
int main()
{   stack ob;
    string s;//s is for the postfix expression string
    int result,op1,op2;  //to store in stack once a operation is performed
    cout<<"Program will work as long as you enter a valid expression..\n";
    cout<<"Enter the postfix expression\n";
    getline(cin,s);

    int len=s.size();
    for(int i=0;i<len;i++)
    {
      if(isdigit(s[i]))
       ob.push(s[i]-'0');
        else
        {
          op2=ob.pop();
          op1=ob.pop();
          result=ob.eval(op1,op2,s[i]);
          ob.push(result);
        }
    }

    cout<<"\nAnswer to the postfix expression is ";
        ob.display();

    return 0;
}