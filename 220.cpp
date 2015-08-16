#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int> m;
	   if(nums.size() < 2 | k == 0)
		   return false;
	   for (int i = 0; i < nums.size(); i++) {
		   if(m.count(nums[i]) && (i - m[nums[i]]) <=k)
			   return true;
		   m[nums[i]] = i;
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
	cout << s.containsNearbyDuplicate(b,7);

}
