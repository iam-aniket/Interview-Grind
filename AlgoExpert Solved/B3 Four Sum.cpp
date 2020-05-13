#include <bits/stdc++.h> 
#define rep(i,a,n) for(int i = a; i < n ; i++)

using namespace std; 

bool findfour(int arr[], int n, int k) 
{ 
	// map to store sum and indexes for 
	// a pair sum 
	unordered_map<int, vector<pair<int, int> > > hash; 

	rep(i,0,n) 
	{ 
		rep(j,i+1,n)
		{ 
			// calculate the sum of each pair 
			int sum = arr[i] + arr[j]; 
			
			if (hash.find(k - sum) != hash.end()) 
			{ 
				auto num = hash.find(k - sum); 
				vector<pair<int, int> > v = num->second; 

				// check for index coincidence as if 
				// there is a common that means all 
				// the four numbers are not from 
				// different indexes and one of the 
				// index is repeated
				
				if (v[0].first != i && v[0].first != j && 
						v[0].second != i && v[0].second != j) 
				{
					cout<<"Elements are : ";
					cout<<arr[i]<<" + "<<arr[j]<<" + ";
					cout<<arr[v[0].first]<<" + "<<arr[v[0].second]<<" = "<<k<<"\n";	
					return true; 
				}
			}
			// store the sum and index pair in hashmap 
			hash[sum].push_back(make_pair(i, j)); 
		} 
	} 
	hash.clear(); 
	return false; 
} 
int main() 
{ 
	int n = 1,k = 1;
	cin>>n>>k; 
	int a[n+1] = {0};
	rep(i,0,n)
		cin>>a[i]; 
	if (findfour(a, n, k)) ; 
	else
		cout << "No valid four sum" << endl; 
	return 0; 
} 
/*
6 7
1 5 2 -2 -1 0
*/
