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
 /*
 Company :- Flipkart
 3. Remove Zero Sum Consecutive Nodes from Linked List

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        // Intiution was to use prefix sum and map it with corresponding node 
        int sum = 0;
        ListNode* temp = new ListNode(0);

        ListNode* ans = temp;
        temp -> next = head;
        while(temp != NULL){
            sum += temp -> val;
            mp[sum] = temp;
            temp = temp -> next;
        } 

        sum = 0;
        for(ListNode* i = ans; i != NULL; i = i -> next){
            i -> next = mp[sum += i -> val] -> next;
        }

        return ans -> next;
    }
};
