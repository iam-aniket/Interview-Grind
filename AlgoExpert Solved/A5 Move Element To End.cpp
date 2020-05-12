/*
Problem Statement

You're given an array of integers and an integer.
Write a function that moves all instances of that integer in the array to the end of array and returns the array.

The function should perform this in Place(ie; it should mutate the ip array) and doesn't need to maintain order of other integers.

Input : [ 2 1 2 2 2 3 4 2 ]
toMove : 2

Output : [ 4 1 3 2 2 2 2 2 ] //order of 4 1 3 could be different also

*/
#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define lli long long int

using namespace std;

void swap(vector<int>& arr, int i, int j) 
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void moveElementToEnd(vector<int> array, int toMove) 
{
	int left = 0; 
	int right = array.size() - 1;
	while (left < right)
	{
		if (array[left] != toMove)
		{
			left++;
			continue;
		}
		if (array[right] == toMove) 
		{
			right--;
			continue;
		}
		
		swap(array, left, right);
		left++;
		right--;
	}
	
	int n = array.size();
	rep(i,0,n)
		cout<<array[i]<<" ";
	cout<<"\n";
  
  return;
}
int main()
{
	int n = 1,toMove = 1;
	cin>>n>>toMove;
	vector<int> a;
	rep(i,0,n)
	{
		int x = 1;
		cin>>x;
		a.push_back(x);
	}
	moveElementToEnd(a,toMove);
	
}
/*
8 2
2 1 2 2 2 3 4 2
*/
