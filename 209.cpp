#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
       int n = nums.size();
	   if (n==0)
		   return 0;
		   n = n + 1;
	   int left = 0;
	   int sum = 0;
	   int count = 0;
	   for (int i = 0; i < nums.size(); i++) {
		   sum += nums[i];
		   ++count;
		   if (sum >= s) {
		   while(sum >= s) {
			   sum -= nums[left++];
			   count--;
		   }
		   if (count + 1 < n )
				n = count + 1;
		}
	   }
	   if (n == nums.size() + 1)
		   return 0;
	   return n;
		
    }
};

int main() {
	int a[] = {1,2,3,4,5};
	vector<int> b(a,a+5);
	Solution s;
	cout << s.minSubArrayLen(11,b);
}
