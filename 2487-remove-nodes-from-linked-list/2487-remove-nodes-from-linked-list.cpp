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
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr) return nullptr;

        // Reverse the list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        // Remove nodes smaller than maximum seen
        int maxVal = head->val;
        curr = head;

        while(curr != nullptr && curr->next != nullptr){
            if(curr->next->val < maxVal){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxVal = curr->val;
            }
        }

        // Reverse again
        prev = nullptr;
        curr = head;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};