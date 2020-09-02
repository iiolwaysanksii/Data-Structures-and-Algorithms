/*
RECURSION
1 + 1/2 + 1/3 + 1/4 + ........ + 1/n  
*/
#include <iostream>
using namespace std;

double series(double n)
{
 if(n<1)
 	return 0;

 else
 	return(1/n + series(n-1));
}

int main()
{
 cout<<series(10);
 return 0;	
}