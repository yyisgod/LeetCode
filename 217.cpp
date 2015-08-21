#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       set<int> m;
	   if(nums.size() < 2)
		   return false;
	   for (int i = 0; i < nums.size(); i++) {
		   if(m.count(nums[i]))
			   return true;
		   m.insert(nums[i]);
	   }
		return false;
	   }
    
};
int main() {
	int a[] = {
		1,2,3,4,5,6,7,0,11,9,8
	};
	vector<int> b(a,a+11);
	Solution s;
	cout << s.containsDuplicate(b);
}


