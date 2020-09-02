//Implementation of stack using array
#include <iostream>
#include <stdlib.h>
using namespace std;

class stack
{ int top,size;
  int s[20];

  public:
	  stack(int n)
	   {
		 top=-1;
		  size=n;
	   }
	  
	  void push()
	  {
		int el;
		
		if(top==size-1)
			cout<<"Stack is full so can't push the element\n";
		
		else{
		  cout<<"Enter the element that has to be inserted\n";
			cin>>el;
		
			 top++;
		
			  s[top]=el;
		
		cout<<"Element pushed \n"
			<<"Total elements in stack are "<<top+1<<"\n"
			<<"You can now only push "<<size-(top+1)<<" more elements\n";
		
		}  //end of else
	  }  //end of push

	  
	  void pop()
	  {
	
		if(top==-1)
			cout<<"Stack is empty so pop can't be performed\n";
	
		else if(top==0)
		{
		   cout<<"Element that is popped "<<s[top]<<"\n";
	
		   top=-1;
	
		}  //end of else if
	
		else
		{
		   cout<<"Element that is popped "<<s[top]<<"\n";
	
		   top--;
		}  //end of else
	  } // end of pop

	
	  void Clear()
	  {
		top=-1;
	
		cout<<"Stack cleared\n";
	  }

	
	  void topel()
	  {
		if(top==-1)
		cout<<"Stack is Empty\n";
	
		else
		cout<<"Element at top position is "<<s[top]<<"\n";
	  }

	
	  void display()
	  {
		if(top==-1)
		 cout<<"Stack is Empty\n";
	
		else
		 for(int i=top;i>=0;i--)
		  cout<<s[i]<<"\n";
	  }
};


int main()
{
   int s,m; char ch='y';
   /*s is for size of array
	 m is for the choice in main menu
	 ch is for repetetion of main menu*/
   cout<<"Enter the size of stack (max 20)\n";
   cin>>s;

   stack ob(s);
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