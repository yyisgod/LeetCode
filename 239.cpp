#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		deque<int> index;
		if (nums.size() >=  k && k >= 1)  {
		for (int i = 0; i < k; i++) {
			while(!index.empty() && nums[i] >= nums[index.back()]) 
				index.pop_back();
			index.push_back(i);
		}

		for (int i = k; i < nums.size(); i++) {
			result.push_back(nums[index.front()]);

			while(!index.empty() && nums[i] >= nums[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= (i-k))
				index.pop_front();
			index.push_back(i);
		}
		result.push_back(nums[index.front()]);
		}
		return result;
	}
		
};

int main() {
	int n,k;
	cin >> n >> k;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	Solution s;
	vector<int> result = s.maxSlidingWindow(nums,k);
	for (auto i : result) 
		cout << i << ' ';
	return 0;
}
