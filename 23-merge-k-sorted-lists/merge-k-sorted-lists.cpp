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
        ListNode* head = NULL;
        map<int,int>mp;
        for(auto x : lists){
            while(x!=NULL){
                mp[x->val]++;
                x = x->next;
            }
        }
        ListNode* cur = new ListNode(0);
        head = cur;
        for(auto x : mp){
            while(x.second--){
                cur->next = new ListNode(x.first);
                cur = cur->next;
            }
        }
        return head->next;
    }
};