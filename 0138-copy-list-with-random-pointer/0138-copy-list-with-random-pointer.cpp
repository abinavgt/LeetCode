/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node* ,Node*> m; // For Allocating the connections

        Node* newHead = new Node(head->val);
        m[head] = newHead;
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        while(oldTemp!=NULL){
            Node* CopyNode = new Node(oldTemp->val);
            m[oldTemp] = CopyNode;
            newTemp->next = CopyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        // Now copying the random connections
        oldTemp = head;
        newTemp = newHead;
        while(oldTemp !=NULL){
            newTemp->random = m[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};