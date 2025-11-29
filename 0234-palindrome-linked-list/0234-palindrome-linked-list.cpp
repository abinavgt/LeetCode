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
    ListNode* reverseList(ListNode* head){
        
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;

        front->next = head;
        head->next = NULL;
        return newHead;

    }

    bool isPalindrome(ListNode* head) {
        // Check the middle element
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Taking the elements afetr the mid
        ListNode* secondHead = reverseList(slow); 

        // Comparing the values before the mid and afetr the mid
        ListNode* first = head;
        ListNode* second = secondHead;
        while(second!=NULL){
            if(first->val != second->val){
                reverseList(secondHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(secondHead);
        return true;

    }
};