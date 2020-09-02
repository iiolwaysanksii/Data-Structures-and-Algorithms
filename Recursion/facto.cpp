/*
RECURSION-----Factorial
*/
#include <iostream>

using namespace std;

int fact(int n)
{
  if(n<=1)
        return 1;
  else
    return(n*fact(n-1));
}

int main()
{   int a;
    cout<<"Enter a number whose factorial you want to find\n";
    cin>>a;
    cout<<"factorial is "<<fact(a);
    return 0;
