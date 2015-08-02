#include <iostream>
#include <stack>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
    	int len = st.size();
    	if (!len) 
    		return;
		for (int i = 0; i < len; i++) {
			temp.push(st.top());
			st.pop();
		}
		temp.pop();
		for (int i = 0; i < len - 1; i++) {
			st.push(temp.top());
			temp.pop();
		}
		
        
    }

    // Get the front element.
    int peek(void) {
    	int len = st.size();
    	if (!len) 
    		return 0;
       for (int i = 0; i < len; i++) {
			temp.push(st.top());
			st.pop();
		}
		int val = temp.top();
		for (int i = 0; i < len; i++) {
			st.push(temp.top());
			temp.pop();
		}
		return val;
	 
    }

    // Return whether the queue is empty.
    bool empty(void) {
       return st.empty(); 
    }
private:
	stack<int> st;
	stack<int> temp;
};


int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() <<endl;
	q.pop();
	cout << q.peek() <<endl;
	q.pop();
	cout << q.peek() <<endl;
	q.pop();
	cout << q.peek() <<endl;
	q.pop();
	cout << q.peek() <<endl;
	q.pop();
	cout << q.peek() <<endl;
	q.pop();
	cout << q.empty() << endl;
	return 0;
}
