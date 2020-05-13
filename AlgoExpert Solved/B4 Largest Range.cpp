/*
Problem Statement

Write a function that takes in an array of integers and returns an array of length 2 representing the largest range of numbers
contained in that array. The rst number in the output array should be the rst number in the range while the second number
should be the last number in the range. A range of numbers is dened as a set of numbers that come right after each other in the
set of real integers. For instance, the output array [2, 6] represents the range {2, 3, 4, 5, 6}, which is a range of length 5.
Note that numbers do not need to be ordered or adjacent in the array in order to form a range.

Assume that there will only be one largest range.

Sample input: [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6] 
Sample output: [0, 7]

*/
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array) {
  // Write your code here.
	int longest = 0;
	vector<int> longestRange;
	unordered_map<int, bool> nums;
	for (int n : array) {
		nums[n] = true;
	}
	
	for (int n : array) {
		if (!nums[n]) continue;
		nums[n] = false;
		int len = 1;
		int left = n - 1;
		int right = n + 1;
		while (nums[left]) {
			left--;
			len++;
		}
		while (nums[right]) {
			right++;
			len++;
		}
		if (longest < len) {
			longest = len;
			longestRange = {left + 1, right - 1};
		}
	}
	return longestRange;
}
