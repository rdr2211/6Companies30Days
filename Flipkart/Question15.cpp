/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Company :- Flipkart
15. House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104
*/
class Solution {
public:
    vector<int> traverser(TreeNode* curr){
        if(!curr){
            return {0, 0};
        }
        
        vector<int>l, r, t;
        l = traverser(curr->left);
        r = traverser(curr->right);
        
        t.push_back( l[1] + r[1] + curr->val );
        t.push_back( max(l[0], l[1]) + max(r[0], r[1]) );
        
        return t;
    }
    int rob(TreeNode* root) {
        vector<int>holder = traverser(root);
        return max(holder[0], holder[1]);
    }
};
