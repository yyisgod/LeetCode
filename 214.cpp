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
        int k = -1;
        for (int i=1; i<n-1; i++) {
            //int k = pi[i];
            while (k != -1 && s[k+1] != s[i]) k = pi[k];
            if (s[k+1] == s[i]) {
                k++;
            }
            pi[i] = k;
        }

        k = -1;
         for (int i=0; i < n; i++) {
            while (k != -1 && s[k+1] != rs[i]) k = pi[k];
            if (s[k+1] == rs[i]) {
                k++;
            } 
        }

        string ans(rs, 0, n-k-1);
        ans.append(s);
        return ans;
    }
};
int main() {
	
}
