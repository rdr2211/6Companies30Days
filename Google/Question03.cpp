/*
Company :- Google
3. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // Intuition Count sorting technique
        int k = nums[0];
        int m = INT_MAX;
        for(int i = 0; i < n; i++){
            k = max(k, nums[i]);
            m = min(m, nums[i]);
        }

        int count[k + abs(m) + 1];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n; i++){
            if(nums[i] >= 0) count[nums[i] + abs(m)]++;
            else count[(nums[i] - m)]++;
        }

        for(int i = 1; i <= k + abs(m); i++){
            count[i] += count[i - 1];
        }

        int output[n];
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] >= 0) output[--count[nums[i] + abs(m)]] = nums[i];
            else output[--count[(nums[i]) - m]] = nums[i];
        }

        for(int i = 0; i < n; i++){
            nums[i] = output[i];
        }
        return nums;
    }
};
