/*
Problem Statement

Write a function that takes in a two-dimensional array and returns a one-dimensional array
of all the array's elements in zigzag order. 
Zigzag order starts at the top left corner of the two-dimensional array, goes down by one element, 
and proceeds in a zigzag pattern all the way to the bottom right corner.

Sample input: [ [1, 3, 4, 10],
				[2, 5, 9, 11], 
				[6, 8, 12, 15], 
				[7, 13, 14,16], ] 

Sample output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define nl cout<<"\n"

using namespace std;
void zigzag(int array[][100],int m,int n)
{
	bool goingDown = true;
	int rows = m;
	int cols = n;
	int r = 0;
	int c = 0;
	vector<int> result;
	while (r < rows && c < cols) 
	{
		result.push_back(array[r][c]);
		if (goingDown)
		{
			if (c == 0 && r != rows-1) 
			{
				r++;
				goingDown = false;
			}
			else if (r == rows-1) 
			{
				c++;
				goingDown = false;
			}
			else
			{
				r++;
				c--;
			}
		} 
		else 
		{
			if (r == 0 && c != cols-1) 
			{
				c++;
				goingDown = true;
			}
			else if (c == cols-1) 
			{
				r++;
				goingDown = true;
			} 
			else 
			{
				r--;
				c++;
			}
		}
	}
	for(int x : result)
		cout<<x<<" ";
		
}
int main()
{
	int n = 1,m = 1;
	cin>>m>>n;
	int a[100][100] = {0};
	rep(i,0,m)
		rep(j,0,n)
			cin>>a[i][j];
	zigzag(a,m,n);
}
