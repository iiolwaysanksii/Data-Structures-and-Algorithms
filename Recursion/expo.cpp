/*
RECURSION-----To find x^y
*/
#include <iostream>

using namespace std;

int power(int c,int d)
{
  if(d==0)
    return 1;
  else
    return(c*power(c,(d-1)));
}
int main()
{  int a,b;
   cout<<"Enter the base ";
   cin>>b;
   cout<<"\nEnter the power ";
   cin>>a;

   cout<<"\nb^a is "<<power(b,a);
    return 0;
}