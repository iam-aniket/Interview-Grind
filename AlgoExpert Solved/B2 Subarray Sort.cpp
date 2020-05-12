/*
Problem Statement

Write a function that takes in an array of integers of length at least 2. 
The function should return an array of the starting and ending indices of the smallest subarray in the input array
that needs to be sorted in place in order for the entire input array to be sorted. 
If the input array is already sorted, the function should return [-1, -1].

Sample input: [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19] 
Sample output: [3, 9]
*/
#include<bits/stdc++.h>
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define rep(i,a,n) for(int i = a; i < n; i++)
#define per(i,a) for(int i = a; i>= 0; i--)

using namespace std;
void ExtraSpaceSolution(int arr[],int n)
{
	int arr1[n+1] = {0};
	rep(i,0,n)
  		arr1[i] = arr[i];
	sort(arr1,arr1+n);
	
	int left = 0,right = 0;
	rep(i,0,n)
	{
		if(arr[i] != arr1[i])
		{	left = i;break;}
	}
	per(i,n-1)
	{
		if(arr[i] != arr1[i])
		{	right = i;break;}
	}
	
	cout<<left<<" "<<right<<"\n";
    
}
void printUnsorted(int arr[], int n) 
{ 
	int s = 0, e = n-1, i, max, min;  
	for (s = 0; s < n-1; s++) 
	{ 
	    if (arr[s] > arr[s+1]) 
	    break; 
	} 
	if (s == n-1) 
	{ 
	    cout << "The complete array is sorted"; 
	    return; 
	} 
	for(e = n - 1; e > 0; e--) 
	{ 
	    if(arr[e] < arr[e-1]) 
	    break; 
	} 
	  
	max = arr[s]; min = arr[s]; 
	for(i = s + 1; i <= e; i++) 
	{ 
	    if(arr[i] > max) 
	    max = arr[i]; 
	    if(arr[i] < min) 
	    min = arr[i]; 
	} 
	  
	for( i = 0; i < s; i++) 
	{ 
	    if(arr[i] > min) 
	    {  
	    s = i; 
	    break; 
	    }      
	}  
  
	for( i = n -1; i >= e+1; i--) 
	{ 
	    if(arr[i] < max) 
	    { 
	    e = i; 
	    break; 
	    }  
	}  
	cout << "The unsorted subarray which" << " makes the given array" << endl << "sorted lies between the indees " 
	     << s << " and " << e; 
	return; 
} 
  
int main() 
{ 
	int n = 1;
	cin>>n; 
	int a[n+1] = {0};
	rep(i,0,n)
		cin>>a[i];
	printUnsorted(a,n);
	//ExtraSpaceSolution(a,n);
	
}
/*
11
10 12 20 30 25 40 32 31 35 50 60
*/
