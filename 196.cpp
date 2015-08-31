#include<iostream>
#include<bitset>
using namespace std;

class Solution {
public:
   uint32_t reverseBits(uint32_t n) {
        bitset<32> a(n);
		bitset<32> b(0);
		for(int i = 0; i < 32; i++)
			b[i] = a[31-i];
		return (uint32_t)b.to_ulong();
    }
};

int main() {
	Solution s;
	cout << s.reverseBits(43261596);
}
