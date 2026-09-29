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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* current = head;

        while (current != nullptr) {
            stack<ListNode*> st;

            ListNode* temp = current;
            int count = 0;

            while (temp != nullptr && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }

            if (count < k)
                break;

            while (!st.empty()) {
                prev->next = st.top();
                st.pop();
                prev = prev->next;
            }

            current = temp;
            prev->next = current;
        }

        return dummy.next;
    }
};