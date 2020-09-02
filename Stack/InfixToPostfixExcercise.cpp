//This programm converts infix equations to postfix equations
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int prec(char c)   //function to return precedence of operators
{
  if(c=='^')
	return 3;
  else if(c=='*'||c=='/')
	return 2;
  else if(c=='+'||c=='-')
	return 1;
  else
	return -1;
}

void convert(string s)
{
  string poststring;
  stack<char> ob;
  ob.push('N');

  for(int i=0;s[i]!='\0';i++)
	{
	  if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))   //if the char that is read is alpha add it to output string
		poststring+=s[i];

	  
	  else if(s[i]=='(')   //first we check if we have encountered a bracket and take appropriate action
		ob.push('(');

	  
	  else if(s[i]==')')
	  {
		while(ob.top()!='N'&&ob.top()!='(') //store this top element to poststring and pop it
		{
			poststring+=ob.top();
			ob.pop();
		}
		if(ob.top()=='(')
			ob.pop();
	  }

	  
	  else    //if we have reached this step
	  {
		while(ob.top()!='N'&&prec(s[i])<=prec(ob.top()))   //check the precedence and if stack is not null
		  {
			 poststring+=ob.top();
			 ob.pop();
		  }
			ob.push(s[i]);   //if everything is in order just push the operator onto stack
	  }

	}//end of for

	while(ob.top()!='N')   //in the end pop all the remaining elements from stack
	  {
		 poststring+=ob.top();
		 ob.pop();
	  }

 cout<<"Postfix String of your infix input is "<<poststring;

}  //end of function used to convert infix to postfix

int main()
{
	cout<<"Program will work as long as you enter valid input\n";
	cout<<"Enter the infix equation\n";
	string str;
	getline(cin,str);
	convert(str);

	return 0;
}
