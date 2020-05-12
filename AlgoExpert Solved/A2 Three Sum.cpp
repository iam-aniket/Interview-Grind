//THREE Number SUM
/*
Problem Statement
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should nd all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. If no three numbers sum up to the target sum, the function should return an empty array.

Sample input: [12, 3, 1, 2, -6, 5, -8, 6], 0

Sample output: [[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]
*/

//This program displays only one triplet <---------------> Extend it for displaying all<-->EASY<-->Just display and continue instead of return

#include<bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define tek ios_base::sync_with_stdio(false);cin.tie(0)
#define lli long long int

using namespace std;

void sumUsingHashing(lli a[],lli n,lli sum)
{
	rep(i,0,n-2)
	{ 
        unordered_set<int> s; 
        
		rep(j,i+1,n)
		{ 
            if (s.find(sum - a[i] - a[j]) != s.end()) 
			{ 
                cout<<a[i]<<" + "<<a[j]<<" + "<<sum - a[i] - a[j]<<" = "<<sum<<"\n";
			    return; 
            }    
            s.insert(a[j]); 
        } 
    } 
	cout<<"-1";
	return;
}
void sumUsingThreePTRmethod(lli a[],lli n,lli sum)
{
	sort(a,a+n);
	int j = 0,k = 0;
	rep(i,0,n-2)
	{
		j = i+1;k = n-1;
		
		while(j < k)
		{
			if(a[j] + a[k] == sum - a[i])
			{
				cout<<a[i]<<" + "<<a[j]<<" + "<<a[k]<<" = "<<sum<<"\n";
				return;
			}
			else if(a[j] + a[k] < sum - a[i])
					j++;
			else
				k--;
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
	//sumUsingThreePTRmethod(a,n,sum);
}
/*
6 22
1 4 45 6 10 8 
*/
/*
12 5
12 6 38 1 4 2 1 3 2 4 1 5
*/
