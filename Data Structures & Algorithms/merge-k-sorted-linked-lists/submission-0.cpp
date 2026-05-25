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
        auto compare = [](ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        for(ListNode* list : lists) {
            if(list != nullptr) {
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while(!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            current -> next = smallest;
            current = current -> next;

            if(smallest -> next != nullptr) {
                minHeap.push(smallest -> next);
            }
        }

        ListNode* result = dummy -> next;
        delete dummy;
        return result;
    }
};
