/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]

*/

//------------------------------------ Recursive Solution -------------------------------------

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;
        
        ListNode* curr = head->next;
        
        if (curr->val != head->val) {
            head->next = deleteDuplicates(curr);
            return head;
        } 
        else {
            while (curr && curr->val == head->val) curr = curr->next;
            return deleteDuplicates(curr);
        }        
    }
};


//------------------------------------- Curr Head + Predecessor -------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                while(curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                if(prev != NULL) {
                    prev->next = curr->next;
                    curr = curr->next;    
                }
                else {
                    head = curr->next;
                    curr = curr->next;   
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

//----------------------------------------- Linear Time Solution--------------------------------

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // handle edge cases, if list is empty
        // or if it has one element, return it
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // create an auxiliary head pointer
        // and a new iterator
        auto auxiliary_head = new ListNode(-1);
        auto iter = auxiliary_head;
        
        while (head != nullptr) {
            if (head->next && head->val == head->next->val) {
                // if current node value is equal to its next value
                // skip all nodes of that value
                int curr = head->val;
                while (head && head->val == curr) {
                    head = head->next;
                }
            } else {
                // otherwise, assign node to next iterator
                // increment new iterator and increment node
                iter->next = head;
                iter = iter->next;
                head = head->next;
            }
        }
        
        // we need to cut the cord
        iter->next = nullptr;
        
        // return new head
        return auxiliary_head->next;
    }
};

