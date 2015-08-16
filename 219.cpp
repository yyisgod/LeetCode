#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) return false;
        if (t < 0) return false;

        map<int, int> m1;
        map<int, int> m2;

        for (int i = 0; i < nums.size(); i++){
            int num1 = nums[i] >= 0 ? nums[i]/(t+1) : nums[i]/(t+1) - 1;
            if (m1.count(num1) && m1[num1] >= i - k)   return true;
            m1[num1] = i;

            int num2 = nums[i] >= 0 ? (nums[i] + (t+2) / 2 )/(t+1) : (nums[i] + (t+2) / 2 )/(t+1) - 1;
            if (m2.count(num2) && m2[num2] >= i - k)   return true;
            m2[num2] = i;
        }

        return false;
    }
};

int main() {
	int a[] = {
		1,2,3,4,5,6,7,0,1,9,8
	};
	vector<int> b(a,a+11);
	Solution s;
	cout << s.containsNearbyAlmostDuplicate(b,3,3);

}
