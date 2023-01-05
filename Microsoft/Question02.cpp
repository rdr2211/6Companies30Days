/*
Company :- Microsoft
2. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
*/
class Solution {
public:
    void f(int k, int n, vector<vector<int>> &ans, int index, vector<int> &a, int target){
        if(a.size() == k && target == 0){
            ans.push_back(a);
            return;
        }

        for(int i = index; i <= 9; i++){
            if(a.size() == k && target != 0) break;
            if(i > target) break;
            a.push_back(i);
            f(k, n, ans, i + 1, a, target - i);
            a.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int mi = 0;
        for(int i = 1; i <= k; i++){
            mi += i;
        }
        if(mi > n) return ans;
        else if(mi == n){
            vector<int> temp;
            for(int i = 1; i <= k; i++){
                temp.push_back(i);
            }
            ans.push_back(temp);
            return ans;
        }

        int index = 1;
        vector<int> b;
        f(k, n, ans, index, b, n);

        return ans;
    }
};
