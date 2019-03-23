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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* head = pListHead, *p = pListHead;
        int count = 0;
        while(p != NULL) {
            count ++;
            p = p->next;
        }
        if(count < k) return NULL;
        for(int i = 0; i < count - k; i ++)
            head = head->next;
        return head;
    }
};