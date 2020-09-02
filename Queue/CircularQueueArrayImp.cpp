//Circular Queue Array Implementation
#include <iostream>

using namespace std;

#define size 10

class q{
	int arr[size];
	int front,rear;

public:
	q(){
		front=rear=-1;
	}

	void enq(int el){
		if((front==0&&rear==size-1)||rear+1==front)
			cout<<"\nOverflow";

		else if(rear==-1)
			front=rear=0;

		else if(rear==size-1&&front!=0)
			rear=0;
		
		else
			rear++;

		arr[rear]=el;
		}

	void deq(){
		if(front==-1)
			cout<<"\nUnderflow";

		else{
			cout<<"Deleted element is"<<arr[front];

			if(front==rear)
				front=rear=-1;

			else if(front==size-1)
				front=0;

			else
				front++;
		}
	}
};

int main(int argc, char const *argv[])
{
	char ch='y'; 
	int n,m;
	q ob;

while(ch=='y'){
	cout<<"\nMenu:"
		<<"\nEnqueue"
		<<"\nDequeue";
		
		cin>>n;

		switch(n){
			case 1:cout<<"\nEnter the element";
					cin>>m;
					ob.enq(m);
					break;

			case 2:ob.deq();
					break;

			default:cout<<"\nInvalid choice";				
		}

		cout<<"\nWant to continue with the main menu (y/n)";
		cin>>ch;
	}
	return 0;
}

