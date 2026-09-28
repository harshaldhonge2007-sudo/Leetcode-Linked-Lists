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
    ListNode* sortList(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;

        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;

        sort(values.begin(), values.end());

        int ind = 0;

        while (curr != nullptr) {
            curr->val = values[ind];
            ind++;
            curr = curr->next;
        }

        return head;
    }
};