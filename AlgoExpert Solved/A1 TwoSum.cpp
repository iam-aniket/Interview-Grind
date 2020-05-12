/*
Problem Statement
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. 
If any two numbers in the input array sum up to the target sum, the function should return them in an array, in sorted order.
If no two numbers sum up to the target sum, the function should return an empty array. 
Assume that there will be at most one pair of numbers summing up to the target sum.

Sample input: [3, 5, -4, 8, 11, 1, -1, 6], 10 Sample output: [-1, 11]
*/
#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define lli long long int

using namespace std;

void sumUsingHashing(lli a[],lli n,lli sum)
{
	unordered_set<lli> s;
	rep(i,0,n)
	{
		lli temp = sum - a[i]; 
		if(s.find(temp) != s.end())
		{
			cout<<a[i]<<" + "<<temp<<" = "<<sum<<"\n";
			return;	
		}	
		s.insert(a[i]);
	}
	cout<<"-1";
	return;
}
void sumUsingTwoPTRmethod(lli a[],lli n,lli sum)
{
	sort(a,a+n);

	for(int i = 0,j = n-1;i < n,j >= 0;)
	{
		if(a[i] + a[j] < sum)
			i++;
		else if(a[i] + a[j] > sum)
			j--;
		else
		{
			cout<<a[i]<<" + "<<a[j]<<" = "<<sum<<"\n";
			return;	
		}	
	}
	cout<<"-1\n";
	return;
}
int main()
{
	lli n = 1,sum = 1;
	cin>>n>>sum;
	lli a[n+1] = {0};
	rep(i,0,n)
		cin>>a[i];
	
	sumUsingHashing(a,n,sum);
	//sumUsingTwoPTRmethod(a,n,sum);
}
/*
12 5
12 6 38 1 4 2 1 3 2 4 1 5
*/
