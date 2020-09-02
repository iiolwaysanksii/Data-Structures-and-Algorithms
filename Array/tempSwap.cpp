#include<iostream>

using namespace std;

template <class A> void Swap(A &a,A &b)
{
    A t;
    t=a;
    a=b;
    b=t;
}

int main()
{
    int x=4,y=7;
    double x1=4.5,y1=7.5;

    cout<<"Before Swapping";
    cout<<"\nx="<<x<<"      y="<<y;
    cout<<"\nx1="<<x1<<"   y1="<<y1<<endl;

    Swap(x,y);
    Swap(x1,y1);

    cout<<"After Swapping";
    cout<<"\nx="<<x<<"      y="<<y;
    cout<<"\nx1="<<x1<<"   y1="<<y1;
   return 0;
}

