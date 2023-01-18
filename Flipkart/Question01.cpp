/*
Company :- Flipkart
1. Partition to K Equal Sum Subsets

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
 

Constraints:

1 <= k <= nums.length <= 16
1 <= nums[i] <= 104
The frequency of each element is in the range [1, 4].
*/
class Solution {
public:
    bool fn(int index, vector<int> &nums, int count, int target, int curr, vector<int> &vis){
        if(count == 1){
            return true;
        }
        // if index pointer gets out of array
        if(index >= nums.size()) return false;
        // if subset sum is equal to target we will decrease the k and start backtracking from starting index 
        if(curr == target) return fn(0, nums, count - 1, target, 0, vis);

        for(int i = index; i < nums.size(); i++){
            if(vis[i] != 1 && nums[i] <= target){
                vis[i] = 1;
                if(fn(i + 1, nums, count, target, curr + nums[i], vis)){
                    return true;
                }
                vis[i] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int subsetSum = 0;
        for(auto &i : nums){
            subsetSum += i;
        }
        
        if(subsetSum % k != 0) return false;
        subsetSum /= k;

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> vis(n, 0);

        return fn(0, nums, k, subsetSum, 0, vis);
    }
};
