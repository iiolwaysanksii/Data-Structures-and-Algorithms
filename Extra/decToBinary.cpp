#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void convert(int n)
{
	cout<<"\n";

	stack<int> ob;
	ob.push(-1);

	if(n==0)
		ob.push(0);

	else{
		int r;

		while(n>1)
		{
			r=n%2;
			n=n/2;
			ob.push(r);
		}
		ob.push(1);
	}

	while(ob.top()!= -1 )
	{
		cout<< ob.top();
		ob.pop();
	}
}

int main()
{
	int n;
	cout<<"Enter a number ";
	cin>>n;

	convert(n);

	return 0;
}
