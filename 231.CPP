#include <iostream>
#include<bitset>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
			return false;
		bitset<32> s(n);
		if(s.count() == 1)
			return true;

    }
};

int main() {
	int n;
	cin >> n;
	Solution s;
	cout << s.isPowerOfTwo(n);

	return 0;
}
