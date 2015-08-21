#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL)
    		return NULL;
		return reverse(head, NULL);
    }
	ListNode* reverse(ListNode* node, ListNode* next) {
		if(node->next == NULL) {
			node->next = next;
			return node;
		}
		ListNode *temp = node->next;
		node->next = next;
		return reverse(temp, node);
	}
};

/*iteratively*/
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL)
    		return NULL;
		ListNode *pre = NULL;
		while(head->next) {
			ListNode* temp = head->next;
			head->next = pre;
			pre = head;
			head = temp;
		}
		head->next = pre;

		return head;
    }
};

int main() {
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution1 s;
	cout << s.reverseList(head)->next->val;
}

