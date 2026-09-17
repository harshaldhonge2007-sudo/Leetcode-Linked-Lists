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

    ListNode* ReverseLL(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = ReverseLL(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = ReverseLL(slow->next);

        ListNode* first = head;
        ListNode* temp = second;

        // Compare
        while (temp != nullptr) {
            if (first->val != temp->val) {
                ReverseLL(second);   // Restore list
                return false;
            }

            first = first->next;
            temp = temp->next;
        }

        // Restore list
        ReverseLL(second);

        return true;
    }
};