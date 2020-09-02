//Calculating comparisons of different sorting algorithms

#include <iostream>
#include <stdlib.h>  //for rand and srand
#include <time.h>    //for time(0)
#include <fstream>   //for file
using namespace std;
 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 
  
int bubbleSort(int arr[], int n) 
{  
	int count=0;

	int i, j; 
	for (i = 0; i < n-1; i++)       
		for (j = 0; j < n-i-1; j++)  
			if (arr[j] > arr[j+1]) 
			{   swap(&arr[j], &arr[j+1]);
				count++;    
			} 

	return count;
} 

int selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx,count=0; 
  
	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
			if (arr[j] < arr[min_idx]) 
			{   min_idx = j;
				count++;
			} 
  
		swap(&arr[min_idx], &arr[i]); 
	} 
	return count;
} 

int insertionSort(int arr[], int n) 
{ 
   int i, key, j,count=0; 
   for (i = 1; i < n; i++) 
   { 
	   key = arr[i]; 
	   j = i-1; 
  
	   while (j >= 0 && arr[j] > key) 
	   { 
		   arr[j+1] = arr[j]; 
		   j = j-1; 
		   count++;
	   } 
	   arr[j+1] = key; 
   }

   return count; 
  
}

void merge(int arr[], int l, int m, int r,int &count) 
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
		count++;
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
  

void mergeSort(int arr[], int l, int r,int &count) 
{ 
	if (l < r) 
	{ 
	   
		int m = l+(r-l)/2; 
  
		mergeSort(arr, l, m,count); 
		mergeSort(arr, m+1, r,count); 
  
		merge(arr, l, m, r,count); 
	} 
} 

int partition (int arr[], int low, int high,int &count) 
{ 
	int pivot = arr[high];    
	int i = (low - 1);    
	for (int j = low; j <= high- 1; j++) 
	{ 
		 
		if (arr[j] <= pivot) 
		{   count++;
			i++;    
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
}

void quickSort(int arr[], int low, int high,int &count) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high,count); 
   
		quickSort(arr, low, pi - 1,count); 
		quickSort(arr, pi + 1, high,count); 
	} 
} 


int main()
{
	ofstream ob("Analysis.txt");

	int size,l=30,comparison=0;   //since we will be generating sizes between 30-1000 

	ob<<"Comparison Analysis of different sorting algorithms"<<"\n\n";

	srand(time(0));
	
	for(int i=0;i<100;i++){  //since there are going to be 100 input sizes

	size=(rand()%10)+l;
	l+=10;
	
	int *array1 =new int[size];
	int *array2 =new int[size];
	int *array3 =new int[size];
	int *array4 =new int[size];
	int *array5 =new int[size];

	for(int j=0;j<size;j++)   //generating elements of array
		array1[j]=array2[j]=array3[j]=array4[j]=array5[j]=rand()%10;

	comparison=insertionSort(array1,size);  
	ob<<"Size: "<<size<<" Insertion: "<<comparison<<" ";

	comparison=bubbleSort(array2,size);
	ob<<" Bubble: "<<comparison<<" ";

	comparison=selectionSort(array3,size);
	ob<<" Selection: "<<comparison<<" ";

	mergeSort(array4,0,size-1,comparison=0);
	ob<<" Merge: "<<comparison<<" ";

	quickSort(array5,0,size-1,comparison=0);
	ob<<" Quick: "<<comparison<<endl;

	delete array1;
	delete array2;
	delete array3;
  }

  ob.close();
  
  return 0;
}
