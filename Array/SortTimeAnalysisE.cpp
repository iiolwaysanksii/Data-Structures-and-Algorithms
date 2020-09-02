/*
Comparing running time of different algorithms
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <ctime>
using namespace std;
 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
	  
	   for (j = 0; j < n-i-1; j++)  
		   if (arr[j] > arr[j+1]) 
			  swap(&arr[j], &arr[j+1]); 

	 cout<<"Bubble Sort finished\n";
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 
  
	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		  if (arr[j] < arr[min_idx]) 
			min_idx = j; 
  
		swap(&arr[min_idx], &arr[i]); 
	} 
cout<<"Selection sort successful\n";
} 

void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
	   key = arr[i]; 
	   j = i-1; 
  
	   while (j >= 0 && arr[j] > key) 
	   { 
		   arr[j+1] = arr[j]; 
		   j = j-1; 
	   } 
	   arr[j+1] = key; 
   } 
  
} 

void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 
  
	int L[n1], R[n2]; 
  
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
  
	i = 0; 
	j = 0;
	k = l;  
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
  
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; 
  
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 
  
		merge(arr, l, m, r); 
	} 
} 


int main()
{
	ofstream ob("Analysis.txt");

	int size,l=30,c1=0,c2=0;   //since we will be generating sizes between 30-1000 

	srand(time(0));
	
	for(int i=0;i<100;i++){  //since there are going to be 100 input sizes

	size=(rand()%10)+l;
	l+=10;
	
	int *array =new int[size];

	for(int j=0;j<size;j++)
		array[j]=rand()%10;

	c1=clock();
	insertionSort(array,size);	
	c2=clock();
	ob<<"Size: "<<size<<" InsertionTime: "<< (c2-c1)<<" ";

	c1=clock();
	mergeSort(array,0,size);
	c2=clock();

	ob<<" MergeTime: "<<(c2-c1)<<" ";

	c1=clock();
	bubbleSort(array,size);
	c2=clock();
	ob<<" BubbleTime: "<<(c2-c1)<<" ";

	c1=clock();
	selectionSort(array,size);
	c2=clock();
	ob<<" SelectionTime: "<<(c2-c1)<<" "<<endl;

	delete array;
  }

  ob.close();
  
  return 0;
}
