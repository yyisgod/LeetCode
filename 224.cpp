#include<iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;


class Solution {
public:
    int calculate(string s) {
       stack<char> opS;
       stack<int>  numS;
       s = '(' + s + ')';

       int i, curNum = 0, len = s.size();
       for(i=0; i<len; ++i)
       {
           if(isdigit(s[i])) curNum = curNum*10 + s[i] -'0';
           else if(isspace(s[i])) continue;
           else if(s[i] == '(')
           {
                opS.push('(');
                opS.push('+');
           }
           else
           {
                switch(s[i])
                {
                    case ')':
                        if('-'== opS.top()) curNum = -curNum;
                       opS.pop();

                       while(opS.top()!='(') 
                       {
                           curNum += (opS.top()=='-')? -numS.top(): numS.top(); 
                           opS.pop(); 
                           numS.pop();
                       }
                       opS.pop(); // skip '('
                       break;
                    default: //+,-,*,/
                        opS.push(s[i]);
                        numS.push(curNum);
                        curNum = 0;
                }
           }
       }
       return curNum;
    }
};

int main() {
	string s("(1+(4+5+2)-3)+(6+8)");
	Solution s1;
	int a = s1.calculate(s);
	cout << a;
}
