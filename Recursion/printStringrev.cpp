/*
Print a String in reverse using recursion
*/

#include <iostream>
using namespace std;

void reverse( string str, int n)
{
     if(n==1)
       cout << str[0] << endl;
    else
    {
       cout << str[n - 1];
       reverse(str,(n-1));
    }
}

int main()
{
    string str;
    cout << " Please enter a string " << endl;
    getline(cin, str);
    int len=str.size();
    reverse(str,len);
    return 0;
}
