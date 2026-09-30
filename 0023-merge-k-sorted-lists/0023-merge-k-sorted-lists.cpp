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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (auto head : lists){
            while(head){
                arr.push_back(head->val);
                head= head->next;
            }
        }
        sort(arr.begin(),arr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int x : arr){
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        return dummy->next;
    }
};