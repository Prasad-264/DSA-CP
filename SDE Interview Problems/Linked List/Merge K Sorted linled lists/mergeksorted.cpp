/*
Given K sorted linked lists of different sizes. The task is to merge them in such a
way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.


Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.

*/

//---------------------------------- Brute Force (Same as merge 2 sorted) ----------------------------------

class Solution {
private:
    Node* sortedMerge(Node* head1, Node* head2) {  
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        if(head1->data > head2->data) swap(head1, head2);
        Node* res = head1;
        while(head1 != NULL && head2 != NULL) {
            Node* temp = NULL;
            while(head1 != NULL && head1->data <= head2->data) {
                temp = head1;
                head1 = head1->next;
            }
            temp->next = head2;
            swap(head1, head2);
        }
        return res;
    } 
    
public:
    Node * mergeKLists(Node *arr[], int k) {
        Node* head1 = arr[0];
        for(int i=1; i<k; i++) {
            Node* head2 = arr[i];
            head1 = sortedMerge(head1, head2);
        }
        return head1;
    }
};

// TC : O(n(n-1)k)

//----------------------------------- Using Priority Queue O(N*K log K) -------------------------------------
class Solution {
public:
    Node * mergeKLists(Node *arr[], int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; ++i) {
            while(arr[i]) {
                pq.push(arr[i]->data);
                arr[i] = arr[i]->next;
            }
        }
        
        Node* temp = new Node(0);
        Node* curr = temp;
        while(!pq.empty()) {
            temp->next = new Node(pq.top());
            pq.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return curr->next;
    }
};

// TC O(nk log(k))

