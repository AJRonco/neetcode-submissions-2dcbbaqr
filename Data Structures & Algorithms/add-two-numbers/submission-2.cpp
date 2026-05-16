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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;

        ListNode dummy = ListNode(0);
        if ((l1->val + l2->val) >= 10){
            carry = true;
        }
        int sum = carry ? 1 : 0;

        ListNode* current = new ListNode((l1->val + l2->val)%10);
        dummy.next = current;
        
        l1 = l1->next;
        l2 = l2->next;

        while(l1 && l2){
            sum = carry ? 1 : 0;
            
            if ((l1->val + l2->val + sum) >= 10){
                carry = true;
            }
            else {
                carry = false;
            }
            sum = (sum + l1->val + l2->val) % 10;
            printf("sum:%d\n", sum);
            current->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            current = current->next;

        }

        



        while (l1){
            sum = carry ? 1 : 0;
            if (l1->val + sum >= 10){
                carry = true;
            }
            else{
                carry = false;
            }
            current->next = new ListNode((l1->val+sum)%10);
            current = current->next;
            l1 = l1->next;
        }


        while (l2){
            sum = carry ? 1 : 0;
            if (l2->val + sum >= 10){
                carry = true;
            }
            else{
                carry = false;
            }
            current->next = new ListNode((l2->val+sum)%10);
            current = current->next;
            l2= l2->next;
    
        }

        if (carry){
            current->next = new ListNode(1);
            current = current->next;
        }

        return dummy.next;
        
    }
};
