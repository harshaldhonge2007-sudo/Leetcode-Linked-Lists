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
class Solution{
    public:

    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* previous = nullptr;

        while(fast!=nullptr && fast->next != nullptr){
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        previous->next = slow->next;
        return head;
    }

    void printlist(ListNode*head){
        ListNode* current = head;
        while(current != nullptr){
            cout << current->val;
            if(current->next != nullptr) cout << " ";
            current = current->next;
        }
    }
    
};