//Heap Sort Comparisons analysis

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
 
void heapify(int arr[], int n, int i,int &count) 
{ 
	int largest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2;  
   
	if (l < n && arr[l] > arr[largest]) 
		{	
		largest = l; 
		count++;
		}
	
	if (r < n && arr[r] > arr[largest]) 
		{	
		largest = r; 
		count++;
		}
	
	if (largest != i) { 
		swap(arr[i], arr[largest]); 
		heapify(arr, n, largest,count); 
	} 
} 
  
void heapSort(int arr[], int n,int &count) 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i,count); 
  
	for (int i = n - 1; i >= 0; i--) { 
		swap(arr[0], arr[i]); 
		  heapify(arr, i, 0,count); 
	} 
} 

int main()
{
	ofstream ob("Analysis.txt");
	int size,l=30,Comparisons=0;
	
	srand(time(0));

	for (int i = 0; i < 100; ++i)   //to generate 100 different sizes
	{
		size=(rand()%10)+l;
		l+=10;

		int *array = new int[size];

		for (int j = 0; j < size; ++j)   //Fill up the array
			array[j]= rand()%100;

		heapSort(array,size,Comparisons=0);

		ob<<"Size: "<<size<<" Comparisons: "<<Comparisons<<endl;

		delete array;
	}

	ob.close();

	return 0;
}