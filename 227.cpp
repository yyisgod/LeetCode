#include<iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;


class Solution {
public:
    int calculate(string s) {
       stack<char> op;
	   stack<int> nums;
		istringstream is(s);
		int num;
		is >> num;
		nums.push(num);
		char ch;
		while(is >> ch >> num) {
			op.push(ch);
			switch(op.top()) {
				case '*':
					num *= nums.top();
					nums.pop();
					op.pop();
					break;
				case '/':
					num = nums.top() / num;
					nums.pop();
					op.pop();
			}
			nums.push(num);
		}
		int result = 0;
		if(op.empty() && !nums.empty()) {
			result = nums.top();
			nums.pop();
			return result;
		}
		while(!op.empty()) {
			result += (op.top() == '-') ? -nums.top():nums.top();
			nums.pop();
			op.pop();
		}
		result += nums.top();
		nums.pop();
		return result;

    }
};

int main() {
	string s("3");
	Solution s1;
	int a = s1.calculate(s);
	cout << a;
}
