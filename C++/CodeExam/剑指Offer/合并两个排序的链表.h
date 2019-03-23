/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL) return NULL;
        else if(pHead1 == NULL) return pHead2;
        else if(pHead2 == NULL) return pHead1;
        ListNode* ans = (ListNode*)malloc(sizeof(ListNode));
        ListNode* head = ans;
        if(pHead1->val <= pHead2->val) {
            ans->val = pHead1->val;
            pHead1 = pHead1->next;
        } else {
            ans->val = pHead2->val;
            pHead2 = pHead2->next;
        }
        while(pHead1 != NULL && pHead2 != NULL) {
            if(pHead1->val <= pHead2->val) {
                ans->next = pHead1;
                ans = ans->next;
                pHead1 = pHead1->next;
            } else {
                ans->next = pHead2;
                ans = ans->next;
                pHead2 = pHead2->next;
            }
        }
        while(pHead1 != NULL) {
            ans->next = pHead1;
            ans = ans->next;
            pHead1 = pHead1->next;
        }
        while(pHead2 != NULL) {
            ans->next = pHead2;
            ans = ans->next;
            pHead2 = pHead2->next;
        }
        return head;
    }
};