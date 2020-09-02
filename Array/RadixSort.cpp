#include <iostream>
using namespace std;

void counting_sort(int A[],int size,int k,int bit){

	/*
	K is the range.
	If in case range in not known use function to find max and min number
	then with expression(max-min+1) we can find out range
	*/
	int C[k]={0};		//frequency array
	int *B= new int[size];	//Output array

	for (int i = 0; i < size; ++i)	//calculates the frequency of each element in array A and stores it in C
		C[ (A[i]/bit)%10 ]++;

	for (int i = 1; i < k; ++i)		//Calculataes the cumulative frequencies 
		C[i]=C[i]+C[i-1];

	for (int i=size-1; i >= 0 ; --i)
	{
		B[C[ (A[i]/bit)%10 ] - 1] = A[i]; 
        C[ (A[i]/bit)%10 ]--; 
	}
	
	for (int i = 0; i < size; ++i){	//put the sorted array back in original array
		cout<<B[i]<<"  ";
		A[i]=B[i];
	}
	cout<<"\n\n";
	delete B;
}

	void Radix_Sort(int A[],int d){
	/*
	In a implementation where d is not known we can use a function
	to find maximum number and decide d from there
	*/
		int bit=1;
		
		for(int i=0; i<d ;i++){			
			counting_sort(A,10,10,bit);
			bit*=10;					//increment increases the bit from once to tens then hundred and so on...
		}
	}

int main(int argc, char const *argv[])					
{
	int arr[]={260,36,25,17,447,665,448,689,77,890};
	
	cout<<"Original Array\n";
	for (int i = 0; i < 10; ++i)
		cout<<arr[i]<<"  ";
	cout<<"\n\nIntermediate Steps\n";

	Radix_Sort(arr,3);

	cout<<"Output Array\n";
	for (int i = 0; i < 10; ++i)
		cout<<arr[i]<<"  ";
	cout<<endl;
	return 0;
}