#include<iostream>
using namespace std;
/*
 Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		if(head == NULL) 
			return NULL;
		while(head->val == val) {
			head = head->next;
			if(head == NULL) 
			return NULL;
		}
		ListNode* p = head;
		while(head->next) {
			ListNode* temp = head;
			if(head->next->val == val) {			
			while(head->next != NULL && head->next->val == val)
				head = head->next;
			temp->next = head->next;
			}
			head = head->next;
			if(head == NULL)
			break;
		}
		return p;
    }
};

int main() {
	ListNode *head = new ListNode(6);
//	head->next = new ListNode(1);
//	head->next->next = new ListNode(2);
//	head->next->next->next = new ListNode(6);
//	head->next->next->next->next = new ListNode(3);
//	head->next->next->next->next->next = new ListNode(4);
//	head->next->next->next->next->next->next = new ListNode(5);
//	head->next->next->next->next->next->next->next = new ListNode(6);
	Solution s;
	cout << s.removeElements(head,6)->val;
}
