class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int flag = 0;
		ListNode* temp = new ListNode(flag);
		ListNode* ans = temp;
		while (l1 != NULL || l2 != NULL){
			int x = l1 == NULL ? 0 : l1->val;
			int y = l2 == NULL ? 0 : l2->val;
			temp->val = temp->val + x + y;
			if (temp->val / 10){ flag = temp->val / 10; temp->val = temp->val % 10; }
			l1 == NULL ? l1 : l1 = l1->next;
			l2 == NULL ? l2 : l2 = l2->next;
			if (l1 != NULL || l2 != NULL || flag){
				temp->next = new ListNode(flag);
				temp = temp->next;
			}
			flag = 0;
		}
		return ans;
	}
};