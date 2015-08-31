#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int maxp = 0;
		int sum = 0;
		for(int i = 1; i < prices.size(); i++) {
			sum += max(0, prices[i] - prices[i-1]);
			maxp = max(maxp,sum);
		}
		return maxp;
    }
};

int main() {
	int a[] = {1, 7, 4, 11};
	vector<int> b(a,a+4);
	Solution s;
	cout << s.maxProfit(b);
}
