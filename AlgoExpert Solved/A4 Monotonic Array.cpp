/*
Problem Statement

Write a function that take in an array of integers and returns boolean representing whether array is monotonic.
An array is monotonic if its elements from left to right are entirely non-increasing or entirely non-decreasing

Input array : [ -1 -5 -10 -1100 -1101 -1102 -9001 ] 
Output : true
*/
#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define lli long long int

using namespace std;


bool isMonotonic(int array[],int n)
{
    if (n <= 2)
        return true;
    rep(i,0,n)
	{
    	int prevN = array[i - 1];
        int currN = array[i];
        int nextN = array[i + 1];
        if (prevN <= currN <= nextN || prevN >= currN >= nextN)
            continue;
        else
            return false;
	}
	return true;
}
    
int main()
{
	int n = 1;
	cin>>n;
	int a[n+1] = {0};
	rep(i,0,n)
		cin>>a[i];
	bool res = false;
	
	res = isMonotonic(a,n);
	if(res)
		cout<<"Array is Monotonic\n";
	else
		cout<<"Not Monotonic\n";
}
