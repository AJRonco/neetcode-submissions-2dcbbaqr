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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }

        vector<ListNode*> nodes;
        ListNode* cur = head;
        while(cur){
            nodes.push_back(cur);
            cur = cur->next;
        }


        int l = 0;
        int r = nodes.size()-1;

        while (l < r){
            nodes[l]->next = nodes[r];
            l++;

            if (l >= r){
                break;
            }
            nodes[r]->next = nodes[l];
            r--;
        }
        nodes[l]->next = nullptr;
    }
};
