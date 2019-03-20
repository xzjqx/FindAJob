/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode *p = pHead;
        while(p != NULL) {
            RandomListNode* tmp = new RandomListNode(p->label);
            RandomListNode* next = p->next;
            p->next = tmp;
            tmp->next = next;
            p = next;
        }
        p = pHead;
        while(p != NULL) {
            p->next->random = (p->random == NULL) ? NULL : p->random->next;
            p = p->next->next;
        }
        RandomListNode* head = pHead->next;
        p = pHead;
        while(p != NULL) {
            RandomListNode* tmp = p->next;
            p->next = tmp->next;
            tmp->next = (tmp->next == NULL) ? NULL : tmp->next->next;
            p = p->next;
        }
        return head;
    }
};