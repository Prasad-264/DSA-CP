/*
Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 11 14 16 19 21 23 25 28 30 30 
Explanation : The resultant linked list is sorted.

*/

class Solution {
public:
    Node* insertionSort(struct Node* head) {
        Node* temp1 = head;
        Node* temp2 = head;
        Node* min = head;
        while(temp1 != NULL) {
            min = temp1;
            temp2 = temp1;
            while(temp2 != NULL) {
                if(temp2->data < min->data) {
                    min = temp2;
                }
                temp2 = temp2->next;
            }
            swap(min->data, temp1->data);
            temp1 = temp1->next;
        }
        return head;
    }
    
};
