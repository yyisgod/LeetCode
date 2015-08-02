#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int left_fac = 1, right_fac = 1, i = 0;
        while(i < n)
        {
            result[i] *= left_fac;
            left_fac *= nums[i];
            result[n - ++i] *= right_fac;
            right_fac *= nums[n - i];
        }
		return result;
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	Solution s;
	vector<int> result = s.productExceptSelf(nums);
	for (auto i:result) 
		cout << i << ' ';
	return 0;
}
