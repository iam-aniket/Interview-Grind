/*
Write a function that returns the length of the longest peak in an array

Peak is defined as adjacent ele in array such that they are strictly increasing untill they reach a tip
and then they are strictly decreasing from the tip.

Ip : 1 2 3 4 0 10 6 5 -1 -3 2 3
Op : 6 {0 10 6 5 -1 -3}
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
using namespace std;
int longestMountain(vector<int>& a) 
{
    int len = 0;
    int n = a.size();
    int j;
    for(int i = 0; i < n; i = j + 1)
	{
        j = i;
        bool down = false;
        bool up = false;
        while(j + 1 < n && a[j + 1] > a[j]) 
		{
        	up = true;
        	j++;
        }
        while(up && j + 1 < n && a[j + 1] < a[j])
		{
        	down = true;
            j++;
        }
        if(up && down)
		{
            len = max(j - i + 1, len);
            j--;
        }
    }
    return len;
}
int main()
{
	int n = 1;
	cin>>n;
	vector<int> a(n,0);
	rep(i,0,n)
		cin>>a[i];
	cout <<longestMountain(a);
}
/*
12
1 2 3 4 0 10 6 5 -1 -3 2 3
/*
12
1 2 3 4 5 6 7 8 9 -2 12 13
*/
