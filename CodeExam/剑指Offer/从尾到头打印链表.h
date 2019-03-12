/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        ListNode* p = head;
        while(p != NULL) {
            ans.insert(ans.begin(), p->val);
            p = p->next;
        }
        return ans;
    }
};