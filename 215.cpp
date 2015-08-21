#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
		return nums[k-1];

    }
};

int main() {
	int a[] = {
		2,1};
	vector<int> b(a,a+2);
	Solution s;
	cout << s.findKthLargest(b,1);

}
