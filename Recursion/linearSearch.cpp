/*
RECURSION  (Linear Search)
returns -1 if not found else returns elements index
*/
#include <iostream>
using namespace std;


int linear(int arr[],int el,int l,int r)
{
	if(l>r)
		return -1;

	else if(arr[l]==el)
		return l;

	else
		return linear(arr,el,l+1,r);
}

int main()
{
int e;
int array[]={1,3,5,7,9,11,13,15,17,19,21};
cout<<"\nEnter element to search ";
cin>>e;

cout<<linear(array,e,0,10);	
}