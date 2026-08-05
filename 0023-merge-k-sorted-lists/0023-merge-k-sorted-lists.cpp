/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            cmp
        >pq;

        for(auto &node : lists){
           if(node) pq.push(node);
        }

        ListNode* temp = new ListNode(0);
        ListNode* tail = temp;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(tail->next){
                pq.push(tail->next);
            }
        }

        return temp->next;
    }
};