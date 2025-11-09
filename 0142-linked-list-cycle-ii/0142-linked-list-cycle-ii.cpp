/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycle = false;

        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){ // Because to preserve the fast value
                cycle = true;
                break;
            } 
        }
        if(!cycle) return NULL; // Still the cycle didnt exist 

        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
/*     
ListNode* prev = NULL;
   while(slow != fast){
    slow = slow->next;
    prev = fast;
    fast = fast->next;
   }
   prev->next = NULL;  // For removing the cycle
   return slow;
*/