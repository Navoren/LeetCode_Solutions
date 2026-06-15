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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast){
            slow = slow->next;
            prev = slow;
            fast = fast->next->next;
        }
        if(prev != nullptr){
            prev->next = slow->next;
        }

        return head;
    }
};