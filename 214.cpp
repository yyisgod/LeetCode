#include <iostream>
#include <string>
using namespace std;

/*
O(n) solution using KMP
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        const int n = s.size();
        string rs(s.rbegin(), s.rend());//reverse s
        int pi[n];
        fill_n(pi, n, 0);
        pi[0] = -1;
        for (int i=0; i<n-1; i++) {
            int k = pi[i];
            while (k != -1 && s[k+1] != s[i+1]) k = pi[k];
            if (s[k+1] == s[i+1]) {
                pi[i+1] = k+1;
            } else {
                pi[i+1] = -1;
            }
        }

        int i=-1, j=-1;
        while (j < n-1) {
            while (i != -1 && s[i+1] != rs[j+1]) i = pi[i];
            if (s[i+1] == rs[j+1]) {
                i++; j++;
            } else {
                j++;
            }
        }

        string ans(rs, 0, n-i-1);
        ans.append(s);
        return ans;
    }
};
int main() {
	
}
