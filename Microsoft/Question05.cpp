/*
Company :- Microsoft
5. Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ,ans = -1 ,  lastIndex =-1;
        vector<int> dp(n, 1);
        vector<int> trace(n, -1);
        sort(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if((nums[i]%nums[j] == 0) && dp[j] >= dp[i]){ dp[i] = dp[j] + 1;   trace[i] = j;}             
            }
            if(dp[i] > ans){ans = dp[i];  lastIndex = i;} 
        }

        vector<int>path;
        while(lastIndex != -1){
            path.push_back(nums[lastIndex]);
            lastIndex = trace[lastIndex];
        }
        reverse(path.begin(), path.end());       
          return path;
    }
};
