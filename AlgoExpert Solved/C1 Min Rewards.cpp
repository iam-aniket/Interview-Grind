/*
Problem Statement

Imagine that you're a teacher who's just graded the nal exam in a class. You have a list of student scores on the internal exam
in a particular order (not necessarily sorted), and you want to reward your students. You decide to do so fairly by giving them 
arbitrary rewards following two rules: rst, all students must receive at least one reward; second, any given student must receive 
strictly more rewards than an adjacent student (a student immediately to the left or to the right) with a lower score
and must receive strictly fewer rewards than an adjacent student with a higher score. 

Assume that all students have different scores; in other words, the scores are all unique. Write a function that takes in a list of scores and returns the minimum number of rewards that you must give out to students, all the while satisfying the two rules.

Sample input: [8, 4, 2, 1, 3, 6, 7, 9, 5] 
Sample output: 25 ([4, 3, 2, 1, 2, 3, 4, 5, 1])

*/
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i < n; i++)
#define nl cout<<"\n"
using namespace std;

int minRewards(int scores[],int n) 
{
	int rewards[n] = {1};	
	rep(i,0,n)
		rewards[i] = 1;
	rep(i,1,n)
	{
		if (scores[i] > scores[i - 1]) 
			rewards[i] = rewards[i - 1] + 1;
	}
	for (int k = n - 2; k >= 0; k--) 
	{
		if (scores[k] > scores[k + 1]) 
			rewards[k] = max(rewards[k], rewards[k + 1] + 1);
	}
	int sum = 0;	
	rep(i,0,n)
		sum += rewards[i];
	
	return sum;
}
int main()
{
	int n = 1;
	cin>>n;
	int a[n+1] = {0};
	rep(i,0,n)
		cin>>a[i];
	int x = minRewards(a,n);
	cout<<x<<"\n";
}
/*
9
8 4 2 1 3 6 7 9 5
*/
