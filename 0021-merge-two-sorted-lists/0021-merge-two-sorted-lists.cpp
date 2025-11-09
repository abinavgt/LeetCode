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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        
        if(List1 ==NULL || List2 == NULL){
            return List1 == NULL? List2:List1;
        }

        if(List1->val <= List2->val){ //Comparing the node 1 from List1 and node from the List2
            List1->next = mergeTwoLists(List1->next,List2); // Recursion for passing List1 & List2
            return List1;
        }
        else{
            List2->next = mergeTwoLists(List1,List2->next);
            return List2;
        }
    }
};