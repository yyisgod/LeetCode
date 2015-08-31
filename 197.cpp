#include<iostream>
#include<bitset>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> a(n);
		return a.count();
    }
};

int main() {
	Solution s;
	cout << s.hammingWeight(11);
}
