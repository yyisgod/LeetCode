#include<iostream>
#include<set>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
        
		int sum = 0;
		while (n > 0) {
			sum += (n % 10)*(n % 10);
			n /= 10;
		}
		if(sum == 1)
				return true;
		if(isUsed.count(sum) != 0)
			return false;
		isUsed.insert(sum);

		return isHappy(sum);
    }
private:
	set<int> isUsed;
};

int main() {
	Solution s;
	cout << s.isHappy(19);

}
