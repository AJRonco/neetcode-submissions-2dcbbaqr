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
    ListNode* reverseList(ListNode* head) {
        auto current = head;
        ListNode* previous = NULL;


        while (current) {
            auto next_temp = current->next;
            current->next = previous;
            previous = current;
            current = next_temp;

        }

        return previous;
    }
};
