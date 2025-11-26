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
 
                   // Iterative Approach 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr!=NULL){
            next = curr->next; // Here the value of next is preserved
            curr->next = prev; // Here the value of next is moving to prev

            prev = curr;
            curr = next;
        }
        return prev;
    }
};




                       /** Recursive Approach

class Solution{
    public:
    ListNode* reverseList(ListNode* head){

        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead = reverseList(head->next); //Stores the elements recursively
        ListNode* front = head->next;
        front->next = head;
        head->next =NULL;
        return newHead;
    }
};
*/