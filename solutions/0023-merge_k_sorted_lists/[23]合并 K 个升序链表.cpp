#include "utils.h"
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
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
        struct cmp {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* head = new ListNode();
        ListNode* p = head;
        for (auto* list: lists) {
            if (list) {
                q.push(list);
            }
        }

        while (!q.empty()) {
            auto* cur = q.top();
            p->next = cur;
            p = p->next;
            q.pop();
            if (cur->next) {
                q.push(cur->next);
            }
        }
        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
