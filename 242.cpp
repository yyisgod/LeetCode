#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    int chs[26] = {0};
	int cht[26] = {0};
	
	for (int i = 0; i < s.length(); i++) {
		chs[s[i] - 'a']++;
	}
	for (int i = 0; i < t.length(); i++) {
		cht[t[i] - 'a']++;
	}
	
	for(int i = 0; i < 26; i++) {
		if(chs[i] != cht[i]) {
			return false;
		}
	}
	return true;    
    }
};


int main() {
	string s,t;
	Solution so;
	cin>> s >> t;
	cout << so.isAnagram(s,t);
	return 0;
}
