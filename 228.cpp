#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		int start = 0;
		vector<string> result;
		if (nums.size()) {
			
		for (int i = 0; i < nums.size()-1; i++) {
			int j = nums[i+1] - nums[i];
			if ((nums[i+1] - nums[i]) != 1 ) {
				stringstream ss;
				string str;
				if ((i - start) > 0) {
					ss << nums[start] << "->" << nums[i];
					ss >> str;
					result.push_back(str);
					start = i+1;
				} else {
					ss << nums[start];
					ss >> str;
					result.push_back(str);
					start = i+1;
				}
			}
		}
		int i = nums.size() - 1;
		stringstream ss;
		string str;
		if ((i - start) > 0) {
			ss << nums[start] << "->" << nums[i];
			ss >> str;
			result.push_back(str);
		} else {
			ss << nums[start];
			ss >> str;
			result.push_back(str);
		}
		return result;
    }}
};

int main() {
	int a[3] = {
		-2147483648,-2147483647,2147483647
	};
	vector<int> nums(a,a+3);
	Solution s;
	vector<string> str = s.summaryRanges(nums);
	for (auto i:str)
		cout << i << ',';

	return 0;
}
