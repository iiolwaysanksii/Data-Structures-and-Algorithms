/*
RECURSION----Sum of array elements
*/
#include <iostream>
using namespace std;

int add(int arr[],int l,int r,int sum)
{
	if(l>r)
		return sum;

	else
	{
	 add(arr,l+1,r,sum+arr[l]);
	}
}

int main()
{

int array[]={1,2,3,4,5,6,7,8,9,10};

cout<<add(array,0,9,0);	

return 0;
}