//Reverse a String using Recursion

#include <iostream>

using namespace std;

void reverse(string &s,int i=0)
{
  int n=s.size();
  if(i==n/2)
    return ;
  else
  {
    swap(s[i],s[n-i-1]);
    reverse(s,i+1);
  }
}

int main()
{
    string str;
    cout<<"Enter the string\n";
    getline(cin,str);
    cout<<"\nAfter reversing the string becomes\n";
    reverse(str);
    cout<<str;

    return 0;
}