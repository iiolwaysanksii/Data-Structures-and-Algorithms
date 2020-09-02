#include <iostream>
using namespace std;

template<class A> A area (A a){
  return a*a;
}

template<class A,class B> A area(A a, B b){
  return 0.5*a*b;
}

int main()
{  cout<<" MENU "<<endl
       <<"Press 1 if you want to fine area of a square "<<endl
       <<"Press 2 if you want to find area of a triangle "<<endl;
   int ch;
   cin>>ch;

   switch(ch)
   {
     case 1: cout<<"Enter the side of square "<<endl;
              int s;
               cin>>s;
                cout<<"Area of square is "<<area(s);
                 break;
     case 2: cout<<"Enter the base and height of triangle"<<endl;
              double p,t;
               cin>>p>>t;
                cout<<"Area of triangle is " <<area(p,t);
                 break;
     default:
              cout<<"wrong input";
   }
    return 0;
}
