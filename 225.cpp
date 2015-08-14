#include<iostream>
#include<queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
       st.push(x); 
    }

    // Removes the element on top of the stack.
    void pop() {
        if(st.size() == 0)
			return;
		if(st.size() == 1) {
			st.pop();
			return;
		}
		queue<int> temp;
		int len = st.size() - 1;
		for(int i = 0; i < len ; i++) {
			temp.push(st.front());
			st.pop();
		}
		st.pop();
		for(int i = 0; i < len; i++) {
			st.push(temp.front());
			temp.pop();
		}
    }

    // Get the top element.
    int top() {
		if(st.size() == 0)
			return 0;
		if(st.size() == 1) {
			return st.front();
		}
		queue<int> temp;
		int len = st.size() - 1;
		for(int i = 0; i < len ; i++) {
			temp.push(st.front());
			st.pop();
		}
		int result = st.front();
		st.pop();
		for(int i = 0; i < len; i++) {
			st.push(temp.front());
			temp.pop();
		}
		st.push(result);
		return result;
    }

    // Return whether the stack is empty.
    bool empty() {
       return st.empty(); 
    }
private:
	queue<int> st;
};

int main() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() <<endl;
	return 0;


}
