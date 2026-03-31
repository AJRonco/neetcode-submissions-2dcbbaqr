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
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;


        for (auto listHead: lists) {
            while (listHead != nullptr) {
                minHeap.push(listHead->val);
                listHead = listHead->next;
            }
        }


        ListNode dummy;
        ListNode* current = &dummy;

        while (!minHeap.empty()){
            current->next = new ListNode(minHeap.top());
            minHeap.pop();
            current = current->next;
        }

        return dummy.next;
    }
};
