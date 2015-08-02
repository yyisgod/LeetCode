#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
// ��Ҫ�����Ÿ��ţ�ö�������������˳�򼴿�(ö�ٵ�һ�����㣬Ȼ��ݹ�)
//
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
		vector<int> result;
		int len = input.size();
		for(int i = 0; i < len; i++) {
			char ch = input[i];
			if (ch == '+' || ch == '-' || ch == '*') {
				vector<int> result1 = diffWaysToCompute(input.substr(0,i));
				vector<int> result2 = diffWaysToCompute(input.substr(i+1));
				for (auto n1 : result1) {
					for (auto n2 :result2) {
						if (ch == '+')
							result.push_back(n1 + n2);
						if (ch == '-') 
							result.push_back(n1 - n2);
						if (ch == '*')
							result.push_back(n1 * n2);
					}
				}
			}
		}

		//û�������
        if (result.empty()) {
			result.push_back(atoi(input.c_str()));
		}
		return result;
    }
};

int main() {
	string str;
	Solution s;
	getline(cin, str);
	vector<int> a = s.diffWaysToCompute(str);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}

	return 0;
}
