//Addition of large number using two stacks
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> a,b,c;

void input(){
	a.push(-1);
	b.push(-1);
	c.push(-1);
	cout<<"Enter a large number digit by digit(-1 to terminate)";
	int n=0;
	while(n!=-1){
		cin>>n;
		if(n!=-1)
			a.push(n);
	}

	cout<<"\n Enter another large number digit by digit(-1 to terminate)";
	n=0;

	while(n!=-1){
		cin>>n;
		if(n!=-1)
			b.push(n);
	}
}

void sum(){

int temp=0;
  
  while(a.top()!=-1&&b.top()!=-1)
  {
   temp=temp + a.top() + b.top();
   a.pop();
   b.pop();
   c.push(temp%10);
   temp/=10;
  }

  if(a.top()!=-1)
  {
   while(a.top()!=-1)
   {
   	temp= temp+a.top();
   	a.pop();
    c.push(temp);
    temp=0;
   }
  }
      
      if(b.top()!=-1)
   while(b.top()!=-1)
   {
   	temp=temp+b.top();
   	b.pop();
    c.push(temp);
    temp=0;
   }
    

    if(temp!=0)
   c.push(temp);  
}

void display(){
	int temp;
	
	while(c.top()!=-1){
		temp=c.top();
		c.pop();
		cout<<temp;
	}

}


int main(){
	input();
	sum();
	display();
	return 0;
}