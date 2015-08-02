//XOR  只能用作正数 
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		int result = 0;
		if(head) {
			ListNode* slow = head, *fast = head;
			int count = 1;
    		while (fast->next) {             
        		fast = fast->next;
        		count++;
        		if(fast->next) {
            		slow = slow->next;
            		fast = fast->next;
            		count++;
        		}
    		}
    		if(count == 1)
    			return true;
			while(head->next){
				if(!(head == slow && count % 2 == 1))
					result = result xor head->val;
				head = head->next;
			}
			result = result xor head->val;
			return !result;
		}
    }
};

int main() {
/*
class Solution {
public:
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;

    ListNode* slow = head, *fast = head;
    while (fast->next) {              // Find end and median
        fast = fast->next;
        if(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    ListNode* median = slow->next;     // Inverse the second part
    inverseList(median);
    ListNode* p1 = head;
    ListNode* p2 = fast;
    while (p1 && p2) {                // Check Palidrome
        if (p1->val != p2->val) {
            inverseList(fast);        // Inverse list to original order
            slow->next = median;
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    inverseList(fast);                 // Inverse list to original order
    slow->next = median;
    return true;
}



void inverseList(ListNode* head) {
    if(!head || !head->next)
        return;
    ListNode* preNode = NULL;
    ListNode* thisNode = head;
    ListNode* nextNode = head->next;
    while (thisNode) {
        thisNode->next = preNode;
        preNode = thisNode;
        thisNode = nextNode;
        if(nextNode)
            nextNode = nextNode->next? nextNode->next:NULL;
    }
}
};
*/
}
