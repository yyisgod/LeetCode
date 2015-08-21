/*头尾只能取其一*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if( 1==n)
			return nums[0];
		if (n == 2)
			return max(nums[0],nums[1]);
		vector<int> numsA(nums.begin(),nums.end()-1);
		vector<int> numsB(nums.begin()+1,nums.end());
		return max(robOnlyOne(numsA),robOnlyOne(numsB));
	}
    int robOnlyOne(vector<int>& nums) {
        int n = nums.size();
        if(0 == n)
        	return 0;
        if(1 == n)
        	return nums[0];
		int dp[n];
		dp[0] = nums[0];
		dp[1] = max(nums[0],nums[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
		}
		return dp[n-1];
    }
};
int main() {
	int a[] = {
		1,3,5,7,9,4,1,15,2
	};
	vector<int> b(a,a+9);
	Solution s;
	cout << s.rob(b);	
}
