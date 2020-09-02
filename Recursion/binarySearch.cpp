/*
RECURSION (Binary SEarch)
returns -1 if element is not found otherwise returns the position of element
*/
#include <iostream>
using namespace std;

int binary(int arr[],int el,int l,int r)
{
	if(l>r)
		return -1;
	else
	{
		int mid=(l+r)/2;
		
		if(arr[mid]==el)
			return mid;

		else if(arr[mid]<el)
			return binary(arr,el,mid+1,r);

		else if(arr[mid]>el)
			return binary(arr,el,l,mid-1);

	}
}

int main()
{
int e;
int array[]={1,3,5,7,9,11,13,15,17,19,21};
cout<<"\nEnter element to search ";
cin>>e;

cout<<binary(array,e,0,10);	
}