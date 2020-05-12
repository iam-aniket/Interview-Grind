/*
Problem Statement
Write a function that takes in two non-empty arrays of integers. 
The function should return the pair of numbers (one from the rst array, one from the second array) whose absolute difference is closest to zero. 
The function should return an array containing these two numbers, with the number from the first array in the first position.
Assume that there will only be one pair of numbers with the smallest difference. 

Sample input: [-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17] 
Sample output: [28, 26]

*/
//O(nlogn + mlogm) -- TC
#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define lli long long int

using namespace std;

int main()
{
	lli n = 1,m = 1;
	cin>>n>>m;
	
	lli a[n+1] = {0},b[n+1] = {0};
	rep(i,0,n)
		cin>>a[i];
	rep(i,0,m)
		cin>>b[i];
		
	sort(a,a+n);	//O(nlogn)
	sort(b,b+n);	//O(mlogm)
	
	int min = abs(a[0] - b[0]);
	
	for(int i = 0,j = 0; i < n,j < m;)	//O(m + n)
	{
		if(abs(a[i] - b[j]) < min)
			min = abs(a[i] - b[j]);
		
		if(a[i] > b[j])
			j++;
		else
			i++;
	}
	cout<<min<<"\n";
	
}
/*
4 6
1 2 11 5
4 12 19 23 127 235
*/
