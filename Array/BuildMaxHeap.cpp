//Building Max Heap and counting the number of comparisons 

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int count=0;
 
void heapify(string s, int n, int i) 
{ 
	int largest = i; 
	int l = 2 * i + 1;
	int r = 2 * i + 2;  
   
	if (l < n && s[l] > s[largest]) 
		{	
		largest = l; 
		count++;
		}
	
	if (r < n && s[r] > s[largest]) 
		{	
		largest = r; 
		count++;
		}
	
	if (largest != i) { 
		swap(s[i], s[largest]); 
		heapify(s, n, largest); 
	} 
} 


void build(string s,int size){
	for (int i = 0; i < size/2; ++i)
		heapify(s,size,i);
}

int main()
{
	ofstream ob("Analysis.txt");

	string s="COMPLEXITY";  

	int size=s.length();

	build(s,size);

	ob<<"Size: "<<size<<" Comparisons: "<<count<<endl;
	

	ob.close();

	return 0;
}