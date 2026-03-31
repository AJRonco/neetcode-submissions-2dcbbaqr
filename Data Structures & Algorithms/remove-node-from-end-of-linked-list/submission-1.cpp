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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        

        ListNode* current = head;
        int length = 0;
        while(current){
            current = current->next;
            length++;
        }

        if (length == n) {
            return head->next;

        }
        ListNode* remove = head;

        for (int i = 1; i < length-n; i++){
            remove = remove->next;
        }
        
        
        if (remove->next && remove->next->next){
            remove->next = remove->next->next;
        }  
        else{
            remove->next = nullptr;
        }

        return head;
    }

};
