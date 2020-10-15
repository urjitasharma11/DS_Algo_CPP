/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/
/*-------------------------------------CODE--------------------------------------------------*/
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
class myComparator {
public:
    int operator()(ListNode* l1, ListNode* l2) const {
        return (l1->val > l2->val);
    }
};
class Solution {
public:
    ListNode* help(priority_queue<ListNode*, vector<ListNode*>, myComparator>& p){
        if(p.empty()) return NULL;
        ListNode* t = p.top();
        p.pop();
        if(t->next!=NULL){
            p.push(t->next);
        }
        t->next = help(p);
        return t;
    }
    ListNode* mergeKLists(vector<ListNode*>& l) {
        priority_queue<ListNode*, vector<ListNode*>, myComparator> p;
        for(int i = 0;i<l.size();i++){
            if(l[i]!=NULL){
                p.push(l[i]);
            }
        }
        return help(p);
    }
};