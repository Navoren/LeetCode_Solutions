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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* temp = head;
        while(temp!= nullptr){
            ListNode* join = temp;
            int sum = 0;
            while(join->val != 0) sum += join->val, join=join->next;
            temp->val = sum;
            temp->next = join->next;
            temp = temp->next;
        }
        return head;
    }
};