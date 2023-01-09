/*
Company :- Goldman Sachs
12. All Elements in Two Binary Search Trees

Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
 

Constraints:

The number of nodes in each tree is in the range [0, 5000].
-105 <= Node.val <= 105
*/

class Solution {
public:
    void elements(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;

        if(root -> left != NULL) elements(root -> left, ans);
        ans.push_back(root -> val);
        if(root -> right != NULL) elements(root -> right, ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        elements(root1, ans);
        elements(root2, ans);
        sort(ans.begin(), ans.end());

        return ans;
    }
};
